#ifndef _GPIO_H_
#define _GPIO_H_

#include "common.h" 


/***********************************************************
 * 
 * 映射到GPIOA，GPIOB和GPIOC寄存器的端口
 * 
 **********************************************************/
#define PTA     GPIOA_BASE_PTR
#define PTB     GPIOA_BASE_PTR
#define PTC     GPIOA_BASE_PTR
#define PTD     GPIOA_BASE_PTR

#define PTE     GPIOB_BASE_PTR
#define PTF		GPIOB_BASE_PTR
#define PTG		GPIOB_BASE_PTR
#define PTH		GPIOB_BASE_PTR

#define PTI		GPIOC_BASE_PTR

/***********************************************************
 * 
 * 输入输出宏定义
 * 
 **********************************************************/
#define OUTPUT  1
#define INPUT	0

#define Pull_Up    1
#define Pull_Down  0

#define SET    1
#define RESET  0
/*************************************************************************
*函数名：  Pin_Output_Config
*函数功能：引脚输出初始化配置
*入口参数： port: 端口
           port_pin: 端口号
           state:  1 输出高;  0 输出低
*返回值：  无
*检验：    K
*时间：	   2017.11.18
*备注：	   出问题了去官方例程里看看
*举例：    Pin_Output_Config(PTD, PTD3, OUTPUT);   设置PD3脚输出高
**************************************************************************/

#define Pin_Output_Config(port,port_pin,state)      (port->PDDR |= ((uint32_t)1 << port_pin)); \
                                                    (state == 0) ? (port->PCOR |=((uint32_t)1<<port_pin)) : (port->PSOR |=((uint32_t)1<<port_pin))
                                                                                                  
/*************************************************************************
*函数名：  Pin_Pull_State
*函数功能：引脚输入初始化配置
*入口参数： port: 端口
           port_pin: 端口号
           state:  1 上拉;  0 呃呃，非上拉
*返回值：  无
*检验：    K
*时间：	   2017.11.20
*备注：	   state为0时，不知是否为下拉，配置的是上拉禁能。官方里除了上拉，
           就是禁能上拉。
*举例：    Pin_Pull_State(PTD, PTD3, Pull_Up);   设置PD3脚上拉
**************************************************************************/                                                   
                                                        
#define Pin_Pull_State(port,port_pin,state)         if(state == 0) \
                                                        if(port==GPIOA_BASE_PTR){PORT_BASE_PTR->PUE0 &=~ ((uint32_t)1<<port_pin);} \
                                                        else if(port==GPIOB_BASE_PTR){PORT_BASE_PTR->PUE1 &=~ ((uint32_t)1<<port_pin);} \
                                                        else {PORT_BASE_PTR->PUE2 &=~((uint32_t)1<<port_pin);} \
                                                    else \
                                                        if(port==GPIOA_BASE_PTR){PORT_BASE_PTR->PUE0 |= ((uint32_t)1<<port_pin);} \
                                                        else if(port==GPIOB_BASE_PTR){PORT_BASE_PTR->PUE1|=((uint32_t)1<<port_pin);} \
                                                        else {PORT_BASE_PTR->PUE2|=((uint32_t)1<<port_pin);}
                                                        
/*************************************************************************
*函数名：  Pin_Input_Config
*函数功能：引脚输入初始化配置
*入口参数： port: 端口
           port_pin: 端口号
           state:  1 上拉;  0 呃呃，非上拉
*返回值：  无
*检验：    K
*时间：	   2017.11.18
*备注：	   state为0时，不知是否为下拉，配置的是上拉禁能。官方里除了上拉，
           就是禁能上拉。
*举例：    Pin_Output_Config(PTD, PTD3, Pull_Up);   设置PD3脚输出高    ( port->PDDR &= (1<<port_pin)); \
**************************************************************************/

#define Pin_Input_Config(port,port_pin,state)       (port->PIDR &=~ ((uint32_t)1<<port_pin)); \
                                                    ( port->PDDR &= ~((uint32_t)1<<port_pin)); \
                                                    Pin_Pull_State(port,port_pin,state)
                                                    
                                                    
/*************************************************************************
*函数名：  Pin_Output_Set
*函数功能：引脚输出配置（已初始化）
*入口参数： port: 端口
           port_pin: 端口号
           state:  1 输出高;  0 输出低
*返回值：  无
*检验：    K
*时间：	   2017.11.18
*备注：	   出问题了去官方例程里看看
*举例：    Pin_Output_Set(PTH, PTH1, 1);   PH1脚输出高
**************************************************************************/
                                                        
#define Pin_Output_Set(port,port_pin,state)         (state == 0) ? (port->PCOR |=((uint32_t)1<<port_pin)) : (port->PSOR |=((uint32_t)1<<port_pin)) 

/*************************************************************************
*函数名：  Pin_Output_Toggle
*函数功能：引脚输出状态反转
*入口参数： port: 端口
           port_pin: 端口号
*返回值：  无
*检验：    K
*时间：	   2017.11.18
*备注：	   出问题了去官方例程里看看
*举例：    Pin_Output_Toggle(PTH, PTH1);   
**************************************************************************/

#define Pin_Output_Toggle(port,port_pin)            port->PTOR |=((uint32_t)1<<port_pin)

/*************************************************************************
*函数名：  Pin_Output_Toggle
*函数功能：读取引脚输入状态
*入口参数： port: 端口
           port_pin: 端口号
*返回值：  无
*检验：    K
*时间：	   2017.11.18
*备注：	   出问题了去官方例程里看看
*举例：    Read_Input_State(PTD, PTD2);   
**************************************************************************/

#define Read_Input_State(port,port_pin)             (port->PDIR & GPIO_PDIR_PDI((uint32_t)1<<port_pin))

/**************************************************************************/

enum GPIOA_Register {
PTA0 = 0,	
PTA1 = 1,
PTA2 = 2,
PTA3 = 3,
PTA4 = 4,
PTA5 = 5,
PTA6 = 6,
PTA7 = 7,
PTB0 = 8,	
PTB1 = 9,
PTB2 = 10,
PTB3 = 11,
PTB4 = 12,
PTB5 = 13,
PTB6 = 14,
PTB7 = 15,
PTC0 = 16,	
PTC1 = 17,
PTC2 = 18,
PTC3 = 19,
PTC4 = 20,
PTC5 = 21,
PTC6 = 22,
PTC7 = 23,
PTD0 = 24,	
PTD1 = 25,
PTD2 = 26,
PTD3 = 27,
PTD4 = 28,
PTD5 = 29,
PTD6 = 30,
PTD7 = 31,
};

enum GPIOB_Register {
PTE0 = 0,	
PTE1 = 1,
PTE2 = 2,
PTE3 = 3,
PTE4 = 4,
PTE5 = 5,
PTE6 = 6,
PTE7 = 7,
PTF0 = 8,	
PTF1 = 9,
PTF2 = 10,
PTF3 = 11,
PTF4 = 12,
PTF5 = 13,
PTF6 = 14,
PTF7 = 15,
PTG0 = 16,	
PTG1 = 17,
PTG2 = 18,
PTG3 = 19,
PTG4 = 20,
PTG5 = 21,
PTG6 = 22,
PTG7 = 23,
PTH0 = 24,	
PTH1 = 25,
PTH2 = 26,
PTH3 = 27,
PTH4 = 28,
PTH5 = 29,
PTH6 = 30,
PTH7 = 31,
};

enum GPIOC_Register {
PTI0 = 0,	
PTI1 = 1,
PTI2 = 2,
PTI3 = 3,
PTI4 = 4,
PTI5 = 5,
PTI6 = 6,
};




#endif
