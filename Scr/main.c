#include "common.h" 

int main(void)
{
	OLED_Init();
	
	while ( 1 )
	{
	OLED_Show_Str(30, 30, "HelloWorld!", 12, 1);
	OLED_Refresh_Gram();
	}
}
