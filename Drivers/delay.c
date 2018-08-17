#include "delay.h"

/*************************************************************************
*��������  Delay_us
*�������ܣ�PIT��ʱ���ж�����
*��ڲ�����us: ��ʱ���ж�ʱ��
*����ֵ��  ��
*���ߣ�    K
*ʱ�䣺	   2017.11.19
*��ע��	   ��Ȼ��������ĺ�׼�����ҽ�ʡ��Ƭ����Դ����ϵͳ�δ����ĺ���  
**************************************************************************/
void Delay_us(uint32_t us)
{
#if (CLOCK_SETUP == 1) //80M��Ƶ��ʱ����
    for(uint16_t i=0; i<us*2; i++)
#elif (CLOCK_SETUP == 2 && CLOCK_SETUP == 0) //40M��Ƶ��ʱ����
    for(uint16_t i=0; i<us; i++)
#endif
    {
		__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");
        __ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");

    }
}

/*************************************************************************
*��������  Delay_ms
*�������ܣ�PIT��ʱ���ж�����
*��ڲ�����ms: ��ʱ���ж�ʱ��
*����ֵ��  ��
*���ߣ�    K
*ʱ�䣺	   2017.11.19
*��ע��	   ��Ȼ��������ĺ�׼�����ҽ�ʡ��Ƭ����Դ����ϵͳ�δ����ĺ���  
**************************************************************************/
void Delay_ms(uint32_t ms)
{
#if CLOCK_SETUP == 1 //80M��Ƶ�ķ���
    for(uint16_t i=0; i<ms; i++)
#elif CLOCK_SETUP == 2 && CLOCK_SETUP == 0 //40M
    for(uint16_t i=0; i<ms; i++)
#endif
    {
        Delay_us(999);
        __ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");__ASM("nop");
    }
}
