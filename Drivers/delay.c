#include "delay.h"

/*************************************************************************
*函数名：  Delay_us
*函数功能：PIT定时器中断配置
*入口参数：us: 定时器中断时间
*返回值：  无
*作者：    K
*时间：	   2017.11.19
*备注：	   虽然垃圾但真的很准，而且节省单片机资源。比系统滴答做的好用  
**************************************************************************/
void Delay_us(uint32_t us)
{
#if (CLOCK_SETUP == 1) //80M主频延时方案
    for(uint16_t i=0; i<us*2; i++)
#elif (CLOCK_SETUP == 2 && CLOCK_SETUP == 0) //40M主频延时方案
    for(uint16_t i=0; i<us; i++)
#endif
    {
		__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");
        __ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");

    }
}

/*************************************************************************
*函数名：  Delay_ms
*函数功能：PIT定时器中断配置
*入口参数：ms: 定时器中断时间
*返回值：  无
*作者：    K
*时间：	   2017.11.19
*备注：	   虽然垃圾但真的很准，而且节省单片机资源。比系统滴答做的好用  
**************************************************************************/
void Delay_ms(uint32_t ms)
{
#if CLOCK_SETUP == 1 //80M主频的方案
    for(uint16_t i=0; i<ms; i++)
#elif CLOCK_SETUP == 2 && CLOCK_SETUP == 0 //40M
    for(uint16_t i=0; i<ms; i++)
#endif
    {
        Delay_us(999);
        __ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");
    }
}
