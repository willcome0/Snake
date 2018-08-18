#include "key.h"

void KEY_Init(void)
{
    Pin_Input_Config(KEY_Up_Port,    KEY_Up_Pin,    1);
    Pin_Input_Config(KEY_Down_Port,  KEY_Down_Pin,  1);
    Pin_Input_Config(KEY_Mid_Port,   KEY_Mid_Pin,   1);
    Pin_Input_Config(KEY_Left_Port,  KEY_Left_Pin,  1);
    Pin_Input_Config(KEY_Right_Port, KEY_Right_Pin, 1);
}


uint8_t Get_Key(void)
{
    static uint8_t Key_Delay = 50;
    
    volatile uint8_t temp_return = 0;
    
	if(0 == Read_Input_State(KEY_Up_Port, KEY_Up_Pin))
	{
		Delay_ms(Key_Delay);
		if(0 == Read_Input_State(KEY_Up_Port, KEY_Up_Pin))
		{
            temp_return = Press_Up; 
		}
        return temp_return;
	}
	
	else if(0 == Read_Input_State(KEY_Down_Port, KEY_Down_Pin))
	{
		Delay_ms(Key_Delay);
		if(0 == Read_Input_State(KEY_Down_Port, KEY_Down_Pin))
		{
            temp_return = Press_Down;  
		}
        return temp_return;
	}
	
	else if(0 == Read_Input_State(KEY_Mid_Port, KEY_Mid_Pin))
	{
		Delay_ms(Key_Delay);
		if(0 == Read_Input_State(KEY_Mid_Port, KEY_Mid_Pin))
		{
            temp_return = Press_Mid;
		}
        return temp_return;
	}
	
	else if(0 == Read_Input_State(KEY_Left_Port, KEY_Left_Pin))
	{
		Delay_ms(Key_Delay);
		if(0 == Read_Input_State(KEY_Left_Port, KEY_Left_Pin))
		{
            temp_return = Press_Left;
		}
        return temp_return;
	}
	
	else if(0 == Read_Input_State(KEY_Right_Port, KEY_Right_Pin))
	{
		Delay_ms(Key_Delay);
		if(0 == Read_Input_State(KEY_Right_Port, KEY_Right_Pin))
		{
            temp_return = Press_Right;
		}
	}
	else
		temp_return = 0;


	return temp_return;
}


