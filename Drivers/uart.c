#include "uart.h"
#include <stdarg.h>
#include <stdio.h>
//=====串口0、1、2号地址映射====
const UART_MemMapPtr UART_ARR[] = {UART0_BASE_PTR,
		                           UART1_BASE_PTR,
								   UART2_BASE_PTR};
//====定义串口IRQ号对应表====
static uint8_t table_irq_uart[3] = {12, 13, 14};


//typedef struct {
//	int dest;
//	void (*func)(char);
//	char *loc;
//} FILE;
int fputc(int ch, FILE *f)
{ 
    UART_Send_Char(UART_1, ch);
    return ch;
}

//===========================================================================
//函数名称：uart_init
//功能概要：使用总线时钟（BUS_CLK_KHZ），初始化uart模块
//参数说明：uartNo:串口号：UART_0、UART_1、UART_2
//       baud:波特率：1200、2400、4800、9600、19200、115200
//函数返回：无
//===========================================================================
 void  UART_Init (uint8_t uartNo,uint32_t baud_rate)
{
    //局部变量声明
    register uint16_t sbr;
//    uint8_t temp;
    //声明uartch1为UART_MemMapPtr结构体类型指针
    UART_MemMapPtr uartch1 = UART_ARR[uartNo];

    //根据带入参数uartNo，给局部变量uartch1赋值
    switch (uartNo)
    {
    case UART_0:
        #if (UART_0_GROUP==1)
            //复用引脚PTA2和PTA3分别为UART0的接收和发送
            SIM_PINSEL0 |= SIM_PINSEL_UART0PS_MASK;
        #endif

        #if (UART_0_GROUP==2)
            //复用引脚PTB0和PTB1分别为UART0的接收和发送
            SIM_PINSEL0 &= ~SIM_PINSEL_UART0PS_MASK;
        #endif
        SIM_SCGC |= SIM_SCGC_UART0_MASK;        //UART0使能总线时钟
        UART0_C2 |= UART_C2_TE_MASK;            //使能UART0发送功能
        UART0_C2 |= UART_C2_RE_MASK;            //使能UART0接收功能
        UART0_C2 |= UART_C2_RIE_MASK;           //使能UART0接收中断功能
    case UART_1:
        //复用引脚PTC6和PTC7分别为UART1的接收和发送
        #if (UART_1_GROUP==1)
            SIM_PINSEL1 &= ~SIM_PINSEL1_UART1PS_MASK;
        #endif
        //复用引脚PTF2和PTF3分别为UART1的接收和发送
        #if (UART_1_GROUP==2)
            SIM_PINSEL1 |= SIM_PINSEL1_UART1PS_MASK;
        #endif

        SIM_SCGC |= SIM_SCGC_UART1_MASK;        //UART1使能总线时钟
        UART1_C2 |= UART_C2_TE_MASK;            //使能UART1发送功能
        UART1_C2 |= UART_C2_RE_MASK;            //使能UART1接收功能
        UART1_C2 |= UART_C2_RIE_MASK;           //使能UART1接收中断功能

        break;
    case UART_2:
        //复用引脚PTD6和PTD7分别为UART2的接收和发送
        #if (UART_2_GROUP==1)
        SIM_PINSEL1  &= ~ SIM_PINSEL1_UART2PS_MASK;
        #endif
        #if (UART_2_GROUP==2)
            //复用引脚PTI0和PTI1分别为UART2的接收和发送
            SIM_PINSEL1  |= SIM_PINSEL1_UART2PS_MASK;
        #endif

        SIM_SCGC |= SIM_SCGC_UART2_MASK;        //UART2使能总线时钟
        UART2_C2 |= UART_C2_TE_MASK;            //使能UART2发送功能
        UART2_C2 |= UART_C2_RE_MASK;            //使能UART2接收功能
        UART2_C2 |= UART_C2_RIE_MASK;           //使能UART2接收中断功能
        break;

    default:
        break;  //传参错误，返回
    }

     //暂时关闭串口发送与接收功能
    uartch1->C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

    //配置波特率使用 Bus clock = 24M 总线时钟
    //配置串口工作模式,8位无校验模式
    uartch1->C1 = 0;
//    sbr = (uint16_t) ((SYSTEM_CLK_KHZ/2 * 1000) / (baud_rate * 16));
    
    {//设置波特率部分，这括号了是逐飞的。时钟方案1、2都好使。
        sbr = (((DEFAULT_SYSTEM_CLOCK / 2)>>4)*10 / baud_rate + 5)/10;               //四舍五入
        if(sbr > 0x1FFF)sbr = 0x1FFF;                              //SBR 是 13bit，最大为 0x1FFF

        //写 SBR
        uartch1->BDH &= ~UART_BDH_SBR_MASK;                     //清除原来波特率
        uartch1->BDH |= UART_BDH_SBR(sbr>>8);                   //先写入SBR高位
        uartch1->BDL  = UART_BDL_SBR((uint8_t)sbr);               //再写入SBR低位
    }
    
//    temp = UART_BDH_REG(uartch1) & ~(UART_BDH_SBR(0x1F));
//    UART_BDH_REG(uartch1) = temp | UART_BDH_SBR(((sbr & 0x1F00) >> 8));
//    UART_BDL_REG(uartch1) = (uint8_t) (sbr & UART_BDL_SBR_MASK);

    //初始化控制寄存器、清标志位
    uartch1->C1 = 0x00;
    uartch1->C3 = 0x00;
    uartch1->S2 = 0x00;
    //启动发送接收
    uartch1->C2 |= (UART_C2_TE_MASK | UART_C2_RE_MASK);
}
 //==========================================================================
 //函数名称：uart_send1
 //参数说明：uartNo: 串口号:UART_0、UART_1、UART_2
 //       data:要发送的字节
 //函数返回：函数执行状态：0=正常；非0=异常。
 //功能概要：串行发送1个字节
  //=========================================================================
 uint8_t UART_Send_Char(uint8_t uartNo, uint8_t data)
{
   uint8_t t;
   //声明uartch1为UART_MemMapPtr结构体类型指针
   UART_MemMapPtr uartch1 = UART_ARR[uartNo];

   for (t = 0; t < 0xFBBB; t++)//查询指定次数
   {
        if ((uartch1->S1) & UART_S1_TDRE_MASK) //判断发送缓冲区是否为空
        {
            uartch1->D = data;   //获取数据并发送
            break;             //跳出循环
        }

   } //end for
   if (t >= 0xFBBB)
       return 1; //发送超时，发送失败
   else
       return 0; //成功发送
}
 //==========================================================================
 //函数名称：uart_sendN
 //参数说明：uartNo: 串口号:UART_0、UART_1、UART_2
 //      buff: 发送缓冲区
 //      len:发送字节数
 //函数返回： 函数执行状态：0=正常；1=异常。
 //功能概要：串行发送多个字节
 //==========================================================================
 uint8_t uart_sendN (uint8_t uartNo ,uint16_t len ,uint8_t* buff)
{
    uint16_t i;
    for (i = 0; i < len; i++)
    {
        if (UART_Send_Char(uartNo, buff[i])) //发送一个字节数据，失败则跳出循环
        {
            break;
        }
    }
    if (i >= len)
        return 1;   //发送len个字节出错
    else
        return 0;   //发送len个字节成功
}

 //===========================================================================
 //函数名称：uart_send_string
 //参数说明：uartNo:UART模块号:UART_0、UART_1、UART_2
 //          buff:要发送的字符串的首地址
 //函数返回： 函数执行状态：0=正常；非0=异常。
 //功能概要：从指定UART端口发送一个以'\0'结束的字符串(以双引号表达的字符串，即是以'\0'结束的字符串）
 //例：uart_send_string(UART_0,"abcdefg"); 即可发送字符  abcdefg
 //===========================================================================
 uint8_t UART_Send_Str(uint8_t uartNo, uint8_t *buff)
{
    uint16_t i;
    for(i = 0; *(buff+i) != '\0'; i++)  //遍历字符串里的字符
    {
        if (UART_Send_Char(uartNo,*(buff+i)))//发送指针对应的字符
            return 1;  //发送失败
    }
    return 0;         //发送成功
}

//===========================================================================
//函数名称：uart_re1
//参数说明：uartNo: 串口号:UART_0、UART_1、UART_2
//          fp:接收成功标志的指针:*fp=0，成功接收；*fp=1，接收失败
//函数返回：接收返回字节
//功能概要：串行接收1个字节
//===========================================================================
uint8_t uart_re1 (uint8_t uartNo,uint8_t *fp)
{
    uint32_t t;
    uint8_t  dat;
    UART_MemMapPtr uartch1 = UART_ARR[uartNo];//获取UART1或者2基地址

    for (t = 0; t < 0xFBBB; t++)//查询指定次数
    {
        //判断接收缓冲区是否满
        if ((uartch1->S1) & UART_S1_RDRF_MASK)
        {
            dat = uartch1->D; //获取数据
            *fp = 0;  //接受成功
            break;
        }
    }//end for
    if(t >= 0xFBBB)
    {
        dat = 0xFF;
        *fp = 1;    //未收到数据
    }
    return dat;    //返回接收到的数据

}
//===========================================================================
//函数名称：uart_reN
//参数说明：uartNo: 串口号:UART_0、UART_1、UART_2
//          buff: 接收缓冲区
//          len:接收长度
//函数返回：函数执行状态 0=正常;非0=异常
//功能概要：串行 接收n个字节
//===========================================================================
uint8_t uart_reN (uint8_t uartNo ,uint16_t len ,uint8_t* buff)
{
    uint16_t i;
    uint8_t flag = 0;

    //判断是否能接受数据
    for (i = 0; i < len && 0 == flag; i++)
    {
        buff[i] = uart_re1(uartNo, &flag); //接受数据
    }
    if (i >= len)
        return 1; //接收失败
    else
        return 0; //接收成功
}

//===========================================================================
//函数名称：uart_enable_re_int
//参数说明：uartNo: 串口号:UART_0、UART_1、UART_2
//函数返回：无
//功能概要：开串口接收中断
//===========================================================================
void uart_enable_re_int(uint8_t uartNo)
{
    UART_MemMapPtr uartch1 = UART_ARR[uartNo];

    uartch1->C2 |= UART_C2_RIE_MASK;       // 开放UART接收中断
    NVIC_EnableIRQ((IRQn_Type)table_irq_uart[uartNo]);// 开中断控制器IRQ中断
}

//===========================================================================
//函数名称：uart_disable_re_int
//参数说明：uartNo: 串口号 :UART_0、UART_1、UART_2
//函数返回：无
//功能概要：关串口接收中断
//===========================================================================
void uart_disable_re_int(uint8_t uartNo)
{
    UART_MemMapPtr uartch1 = UART_ARR[uartNo];
    uartch1->C2 &= ~UART_C2_RIE_MASK;       // 禁止UART接收中断
    NVIC_DisableIRQ((IRQn_Type)table_irq_uart[uartNo]);// 禁止中断控制器IRQ中断
}
