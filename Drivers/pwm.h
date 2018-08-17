#ifndef _PWM_H
#define _PWM_H

#include "common.h"
#include "SKEAZ1284.h"
//-----------------------------------  FTM  -----------------------------------

//      模块通道        端口      可选范围                建议
//#define FTM0_CH0_PIN    PTA0        //B2 A0
//#define FTM0_CH1_PIN    PTA1        //B3 A1

//      模块通道        端口      可选范围                建议
#define FTM1_CH0_PIN    PTH2        //H2 C4
#define FTM1_CH1_PIN    PTC5        //E7 C5

//      模块通道        端口      可选范围                建议
#define FTM2_CH0_PIN   PTC0// H0        //C0  H0 F0              
#define FTM2_CH1_PIN   PTC1        //C1  H1 F1  
#define FTM2_CH2_PIN   PTC2// D0        //C2  G4 D0  
#define FTM2_CH3_PIN   PTC3// D1        //C3  G5 D1
#define FTM2_CH4_PIN   PTG6        //B4  G6  
#define FTM2_CH5_PIN   PTB5//  G7        //B5  G7              

//外部计数模块通道      端口      可选范围                建议
#define FTM0_COUNT_PIN  PTE0        //E7 A5  E0             A5不要用（与复位按键冲突）                
                                           
#define FTM1_COUNT_PIN  PTE7        //E0 A5  E7             A5不要用（与复位按键冲突）
                                           
#define FTM2_COUNT_PIN  PTA5        //E0 E7  A5             A5不要用（与复位按键冲突）



typedef enum
{
    ftm0,
    ftm1,
    ftm2,
} FTMn;


typedef enum
{
    ftm_ch0,
    ftm_ch1,
    ftm_ch2,
    ftm_ch3,
    ftm_ch4,
    ftm_ch5,
    ftm_ch6,
    ftm_ch7,
} FTM_CHn;



//------------------------ PWM ------------------------

#define FTM0_PRECISON 1000u     //定义占空比精度，意思即使把一个周期分成多少分，分多越多这样精度越高，设置占空比的时候duty的范围就是0-FTM0_PRECISON
#define FTM1_PRECISON 1000u     //定义占空比精度，意思即使把一个周期分成多少分，分多越多这样精度越高，设置占空比的时候duty的范围就是0-FTM0_PRECISON
#define FTM2_PRECISON 1000u     //定义占空比精度，意思即使把一个周期分成多少分，分多越多这样精度越高，设置占空比的时候duty的范围就是0-FTM0_PRECISON


void ftm_pwm_init(FTMn ftmn, FTM_CHn ch, uint32_t freq, uint32_t duty);
void ftm_pwm_duty(FTMn ftmn, FTM_CHn ch, uint32_t duty);
void ftm_pwm_freq(FTMn ftmn, uint32_t freq) ;
void ftm_count_init(FTMn ftmn);
uint16_t ftm_count_get(FTMn ftmn);
void ftm_count_clean(FTMn ftmn);

void FTM_PWM_set_CnV(FTMn ftmNo, FTM_CHn channel, uint16_t cnv);



#endif

//#ifndef FTM_H_
//#define FTM_H_


//#include "common.h"

//////FTM模块号
////#define FTM_0 0
////#define FTM_1 1
////#define FTM_2 2

//////通道号，FTM0和FTM1：通道0~通道1，FTM2：通道0~通道5
////#define CHANNEL0 0
////#define CHANNEL1 1
////#define CHANNEL2 2
////#define CHANNEL3 3
////#define CHANNEL4 4
////#define CHANNEL5 5

//typedef enum   //FTM模块号
//{
//    FTM_0, FTM_1, FTM_2,
//} FTMn;

//typedef enum   //通道号
//{
//    CH_0, CH_1, CH_2, CH_3, CH_4, CH_5,
//} FTM_CHn;

///*------------------------PWM模式  FTM0通道和引脚选择----------------------*/

////#define FTM0_CHANNEL0_GROUP 0     //FTM0通道0引脚组: 1 PTA0脚, 2 PTB2脚
////#define FTM0_CHANNEL1_GROUP 0     //FTM0通道1引脚组: 1 PTA1脚, 2 PTB3脚

///*------------------------PWM模式  FTM1通道和引脚选择----------------------*/

////#define FTM1_CHANNEL0_GROUP 0     //FTM1通道0引脚组: 1 PTC4脚, 2=PTH2脚
////#define FTM1_CHANNEL1_GROUP 0     //FTM1通道1引脚组: 1 PTC5脚, 2=PTE7脚

///*------------------------PWM模式  FTM2通道和引脚选择-----------------------*/

//#define FTM2_CHANNEL0_GROUP  1    //FTM2通道0引脚组: 1 PTC0脚, 2 PTH0脚, 3 PTF0脚
//#define FTM2_CHANNEL1_GROUP  1    //FTM2通道1引脚组: 1 PTC1脚, 2 PTH1脚, 3 PTF1脚
//#define FTM2_CHANNEL2_GROUP  1    //FTM2通道2引脚组: 1 PTC2脚, 2 PTD0脚, 3 PTG4脚
//#define FTM2_CHANNEL3_GROUP  1    //FTM2通道3引脚组: 1 PTC3脚, 2 PTD1脚, 3 PTG5脚
//#define FTM2_CHANNEL4_GROUP  1    //FTM2通道4引脚组: 1 PTB4脚, 2 PTG6脚
//#define FTM2_CHANNEL5_GROUP  1    //FTM2通道5引脚组: 1 PTB5脚, 2 PTG7脚

///*------------------------计数模式  通道和引脚选择-----------------------*/

//#define FTM0_COUNT_PIN  PTE0        //PTE7  PTA5  PTE0             A5不要用（与复位按键冲突）                                                  
//#define FTM1_COUNT_PIN  PTE7        //PTE0  PTA5  PTE7             A5不要用（与复位按键冲突）                         
//#define FTM2_COUNT_PIN  PTA5        //PTE0  PTE7  PTA5             A5不要用（与复位按键冲突）


//void FTM_PWM_init(FTMn ftmNo, FTM_CHn channel, float freq, float duty);
//void FTM_PWM_set_duty(FTMn ftmNo, FTM_CHn channel, float duty);
//void FTM_PWM_set_CnV(FTMn ftmNo, FTM_CHn channel, uint16_t cnv);
//void FTM_Count_Mux(FTMn ftmn);

//#endif

////#ifndef _PWM_H
////#define _PWM_H

////#include "common.h"
////#include "SKEAZ1284.h"


/////***************************模块通道选择*******************************************/

//////      模块通道        端口      可选范围
////#define FTM0_CH0_PIN    PTA0        //PTB2 PTA0
////#define FTM0_CH1_PIN    PTA1        //PTB3 PTA1

////#define FTM1_CH0_PIN    PTH2        //PTH2 PTC4
////#define FTM1_CH1_PIN    PTC5        //PTE7 PTC5

////#define FTM2_CH0_PIN    PTC0        //PTC0  PTH0  PTF0              
////#define FTM2_CH1_PIN    PTC1        //PTC1  PTH1  PTF1 

////#define FTM2_CH2_PIN    PTC2        //PTC2  PTG4  PTD0  
////#define FTM2_CH3_PIN    PTC3        //PTC3  PTG5  PTD1
////#define FTM2_CH4_PIN    PTB4        //PTB4  PTG6  
////#define FTM2_CH5_PIN    PTB5        //PTB5  PTG7             

/////********************************************************************************/
//////外部计数模块通道        端口        可选范围                           建议

////#define FTM0_COUNT_PIN  PTE0        //PTE7  PTA5  PTE0             A5不要用（与复位按键冲突）                                                  
////#define FTM1_COUNT_PIN  PTE7        //PTE0  PTA5  PTE7             A5不要用（与复位按键冲突）                         
////#define FTM2_COUNT_PIN  PTA5        //PTE0  PTE7  PTA5             A5不要用（与复位按键冲突）





//////------------------------ PWM ------------------------

////#define FTM0_PRECISON 10000u     //定义占空比精度，意思即使把一个周期分成多少分，分多越多这样精度越高，设置占空比的时候duty的范围就是0-FTM0_PRECISON
////#define FTM1_PRECISON 10000u     //定义占空比精度，意思即使把一个周期分成多少分，分多越多这样精度越高，设置占空比的时候duty的范围就是0-FTM0_PRECISON
////#define FTM2_PRECISON 10000u     //定义占空比精度，意思即使把一个周期分成多少分，分多越多这样精度越高，设置占空比的时候duty的范围就是0-FTM0_PRECISON


////void ftm_pwm_init(FTMn ftmn, FTM_CHn ch, uint32_t freq, uint32_t duty);
////void ftm_pwm_duty(FTMn ftmn, FTM_CHn ch, uint32_t duty);
////void ftm_pwm_freq(FTMn ftmn, uint32_t freq) ;
////void ftm_count_init(FTMn ftmn);
////uint16_t ftm_count_get(FTMn ftmn);
////void ftm_count_clean(FTMn ftmn);



////#endif
