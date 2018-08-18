#include "pit.h"


/*************************************************************************
*��������  PIT_Config
*�������ܣ�PIT��ʱ���ж�����
*��ڲ����� pitno: PIT��
           ms: ��ʱ���ж�ʱ��
           priority: ���ȼ�
*����ֵ��  ��
*���ԣ�    K
*ʱ�䣺	   2017.11.19
*��ע��	   ��Ҫ��ȡ���̵��жϣ���С�� PIT_LDVAL(pitno) �ĸ�ֵ���ɡ��ٷ��Ĳ������÷ǳ��࣬�пտ��Կ������˴������
*������    PIT_Config(PIT_CH1, 1, 1);  PIT_CH1����1ms�жϣ����ȼ�Ϊ1
**************************************************************************/

void PIT_Config(uint8_t PIT_CHX, uint32_t ms, uint8_t priority)
{
    SIM_SCGC |= SIM_SCGC_PIT_MASK;  //ʹ��PITʱ����
    PIT_MCR &= ~PIT_MCR_MDIS_MASK;  //ʹ��PITģ��

    NVIC_DisableIRQ((IRQn_Type)(PIT_CH0_IRQn + PIT_CHX));  //���ܸ��ж�

    //����PITģ��
    PIT_LDVAL(PIT_CHX) = BUS_CLK_KHZ * ms;
    PIT_TCTRL(PIT_CHX) |= (PIT_TCTRL_TIE_MASK);     //��pitģ���ж�
    PIT_TCTRL(PIT_CHX) |= (PIT_TCTRL_TEN_MASK);     //ʹ��pitģ������

    NVIC_SetPriority((IRQn_Type)(PIT_CH0_IRQn + PIT_CHX), priority);
    
    NVIC_EnableIRQ((IRQn_Type)(PIT_CH0_IRQn + PIT_CHX));   //ʹ�ܸ��ж�
}



