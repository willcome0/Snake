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

#define  SYSTEM_CLK_KHZ   DEFAULT_SYSTEM_CLOCK / 1000// 芯片系统时钟频率(KHz)
#define  CORE_CLK_KHZ     SYSTEM_CLK_KHZ / 1           // 芯片内核时钟频率(KHz)？？？莫名变大了，所以这缩小
#define  BUS_CLK_KHZ      SYSTEM_CLK_KHZ / 2         // 芯片总线时钟频率(KHz)？？？莫名变大了，所以这缩小


#endif
