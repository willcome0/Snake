#ifndef __KEY_H_
#define __KEY_H_

#include "common.h" 

/*********************各板子的兼容代码**************************/

//#if (PCB_VERSION == 20)    //兼容PCB V2.0 宏定义
//    #define KEY_Up_Port     PTE
//    #define KEY_Up_Pin      PTE4

//    #define KEY_Down_Port   PTD  
//    #define KEY_Down_Pin    PTD3

//    #define KEY_Mid_Port    PTF
//    #define KEY_Mid_Pin     PTF1

//    #define KEY_Left_Port   PTF
//    #define KEY_Left_Pin    PTF0

//    #define KEY_Right_Port  PTD
//    #define KEY_Right_Pin   PTD4
//    
//#elif (PCB_VERSION == 30)  //兼容PCB V3.0 宏定义
//    #define KEY_Up_Port     PTA
//    #define KEY_Up_Pin      PTA7

//    #define KEY_Down_Port   PTA  
//    #define KEY_Down_Pin    PTA6

//    #define KEY_Mid_Port    PTE
//    #define KEY_Mid_Pin     PTE4

//    #define KEY_Left_Port   PTF
//    #define KEY_Left_Pin    PTF2

//    #define KEY_Right_Port  PTF
//    #define KEY_Right_Pin   PTF1
//    
//#elif (PCB_VERSION == 40)  //兼容PCB V3.0 宏定义
    #define KEY_Up_Port     PTA
    #define KEY_Up_Pin      PTA7

    #define KEY_Down_Port   PTA  
    #define KEY_Down_Pin    PTA6

    #define KEY_Mid_Port    PTE
    #define KEY_Mid_Pin     PTE4

    #define KEY_Left_Port   PTF
    #define KEY_Left_Pin    PTF2

    #define KEY_Right_Port  PTF
    #define KEY_Right_Pin   PTF1
	
	#define Reed1_Port		PTF
	#define Reed1_Pin		PTF3
	
	#define Reed2_Port		PTB
	#define Reed2_Pin		PTB0
//#elif (PCB_VERSION == 0)  //兼容开发板 宏定义
//    #define KEY_Up_Port     PTA
//    #define KEY_Up_Pin      PTA7

//    #define KEY_Down_Port   PTA  
//    #define KEY_Down_Pin    PTA6

//    #define KEY_Mid_Port    PTE
//    #define KEY_Mid_Pin     PTE4

//    #define KEY_Left_Port   PTF
//    #define KEY_Left_Pin    PTF2

//    #define KEY_Right_Port  PTF
//    #define KEY_Right_Pin   PTF1
//#endif
/**************************************************************/

/***********************************************************
 * 
 * 定义 按下值
 * 
 **********************************************************/
#define Press_NULL    0
#define Press_Up      1
#define Press_Down    2
#define Press_Mid     3
#define Press_Left    4
#define Press_Right   5


/***********************************************************
 * 
 * 函数声明
 * 
 **********************************************************/
void KEY_Init(void);
uint8_t Get_Key(void);


#endif
