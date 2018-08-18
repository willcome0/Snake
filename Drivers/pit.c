#include "pit.h"


/*************************************************************************
*函数名：  PIT_Config
*函数功能：PIT定时器中断配置
*入口参数： pitno: PIT号
           ms: 定时器中断时间
           priority: 优先级
*返回值：  无
*测试：    K
*时间：	   2017.11.19
*备注：	   若要获取更短的中断，减小对 PIT_LDVAL(pitno) 的赋值即可。官方的参数设置非常多，有空可以看看。此处是逐飞
*举例：    PIT_Config(PIT_CH1, 1, 1);  PIT_CH1开启1ms中断，优先级为1
**************************************************************************/

void PIT_Config(uint8_t PIT_CHX, uint32_t ms, uint8_t priority)
{
    SIM_SCGC |= SIM_SCGC_PIT_MASK;  //使能PIT时钟门
    PIT_MCR &= ~PIT_MCR_MDIS_MASK;  //使能PIT模块

    NVIC_DisableIRQ((IRQn_Type)(PIT_CH0_IRQn + PIT_CHX));  //禁能该中断

    //配置PIT模块
    PIT_LDVAL(PIT_CHX) = BUS_CLK_KHZ * ms;
    PIT_TCTRL(PIT_CHX) |= (PIT_TCTRL_TIE_MASK);     //开pit模块中断
    PIT_TCTRL(PIT_CHX) |= (PIT_TCTRL_TEN_MASK);     //使能pit模块运行

    NVIC_SetPriority((IRQn_Type)(PIT_CH0_IRQn + PIT_CHX), priority);
    
    NVIC_EnableIRQ((IRQn_Type)(PIT_CH0_IRQn + PIT_CHX));   //使能该中断
}



