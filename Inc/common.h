#ifndef __COMMON_H_
#define __COMMON_H_

#include "SKEAZ1284.h" 

#include <stdio.h> 
#include <string.h> 

#include "gpio.h" 
#include "uart.h"
#include "delay.h"
#include "upper.h"

#include "oled.h"
#include "key.h"
#include "pit.h"
#include "snake.h"

#define  SYSTEM_CLK_KHZ   DEFAULT_SYSTEM_CLOCK / 1000// оƬϵͳʱ��Ƶ��(KHz)
#define  CORE_CLK_KHZ     SYSTEM_CLK_KHZ / 1           // оƬ�ں�ʱ��Ƶ��(KHz)������Ī������ˣ���������С
#define  BUS_CLK_KHZ      SYSTEM_CLK_KHZ / 2         // оƬ����ʱ��Ƶ��(KHz)������Ī������ˣ���������С


#endif
