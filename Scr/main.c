#include "common.h" 

int main(void)
{
	OLED_Init();
	KEY_Init();
	UART_Init(UART_1, 115200);
	PIT_Config(PIT_CH0, 100, 0);
	
	g_Head[X] = 10;
	g_Head[Y] = 10;
			
	while ( 1 )
	{
//		OLED_Show_Str(30, 30, "HelloWorld!", 12, 1);

//		for (int i=0; i<110; i++)
//		{
//			Snake_DrawPoint(&g_Head[X], &g_Head[Y], 1);
//			OLED_Refresh_Gram();
//		}
//		Snake_ShowBody(3);
//		Snake_Turn();
		
		Snake_Turn();
		OLED_Refresh_Gram();
	}
}
