#include "oled.h"
#include "oledfont.h"


/***************************************/
/*
只有更新显存函数才能刷新屏幕
显示函数都加入了模式选择，即正常显示或白底黑字
待做：图形显示，中文显示
*/

//uint8_t HtoL(uint8_t a)
//{
//    return (a & 0x01)<<7| ((a>>1)&0x01)<<6 |((a>>2)&0x01)<<5 |((a>>3)&0x01)<<4 |((a>>4)&0x01)<<3 |((a>>5)&0x01)<<2 |((a>>6)&0x01)<<1 |((a>>7)&0x01);
//}
    
    
    





volatile uint8_t OLED_GRAM[OLED_X_MAX][8];
uint8_t TEMP_OLED_GRAM[OLED_X_MAX][8];
//uint8_t  oled[OLED_X_MAX][8] = {0};

//void PicChange(void)
//{
//    for(int i=0;i<OLED_X_MAX;i++)
//    {
//        for(int j=0;j<8;j++)
//        {
//           oled[i][j] = HtoL(OLED_GRAM[OLED_X_MAX - i -1][ 7 - j]);
//           // oled[i][j]  = 
//        }
//    }
//return ;
//}




//更新显存到OLED
void OLED_Refresh_Gram(void)
{
//    PicChange();
    
	for(uint8_t i=0; i<8; i++)
	{
		OLED_WR_Byte (0xb0+i,Wirte_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (0x00,Wirte_CMD);      //设置显示位置—列低地址
		OLED_WR_Byte (0x10,Wirte_CMD);      //设置显示位置—列高地址
		for(uint8_t n=0; n<OLED_X_MAX; n++)
			OLED_WR_Byte(OLED_GRAM[n][i], Wirte_DATA);
	}
}
//初始化SSD1306
void OLED_Init(void)
{
    Pin_Output_Config(OLED_D0_Port,  OLED_D0_Pin,  SET);
    Pin_Output_Config(OLED_D1_Port,  OLED_D1_Pin,  SET);
    Pin_Output_Config(OLED_RST_Port, OLED_RST_Pin, SET);
    Pin_Output_Config(OLED_DC_Port,  OLED_DC_Pin,  SET);
    
	OLED_DC_HIGH();
	OLED_RST_LOW();

	for(uint16_t i = 4000; i > 0; i--)	//代替延时100ms
		for(uint16_t j = 100; j > 0; j--);

	OLED_RST_HIGH();

	OLED_WR_Byte(0xAE, Wirte_CMD); //关闭显示
	OLED_WR_Byte(0xD5, Wirte_CMD); //设置时钟分频因子,震荡频率
	OLED_WR_Byte(0x80, Wirte_CMD);   //[3:0],分频因子;[7:4],震荡频率
	OLED_WR_Byte(0xA8, Wirte_CMD); //设置驱动路数
	OLED_WR_Byte(0X3F, Wirte_CMD); //默认0X3F(1/64)
	OLED_WR_Byte(0xD3, Wirte_CMD); //设置显示偏移
	OLED_WR_Byte(0X00, Wirte_CMD); //默认为0

	OLED_WR_Byte(0x40, Wirte_CMD); //设置显示开始行 [5:0],行数.

	OLED_WR_Byte(0x8D, Wirte_CMD); //电荷泵设置
	OLED_WR_Byte(0x14, Wirte_CMD); //bit2，开启/关闭
	OLED_WR_Byte(0x20, Wirte_CMD); //设置内存地址模式
	OLED_WR_Byte(0x02, Wirte_CMD); //[1:0],00，列地址模式;01，行地址模式;10,页地址模式;默认10;
	OLED_WR_Byte(0xA1, Wirte_CMD); //段重定义设置,bit0:0,0->0;1,0->127;
	OLED_WR_Byte(0xC0, Wirte_CMD); //设置COM扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:驱动路数
	OLED_WR_Byte(0xDA, Wirte_CMD); //设置COM硬件引脚配置
	OLED_WR_Byte(0x12, Wirte_CMD); //[5:4]配置

	OLED_WR_Byte(0x81, Wirte_CMD); //对比度设置
	OLED_WR_Byte(0xEF, Wirte_CMD); //1~255;默认0X7F (亮度设置,越大越亮)
	OLED_WR_Byte(0xD9, Wirte_CMD); //设置预充电周期
	OLED_WR_Byte(0xf1, Wirte_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
	OLED_WR_Byte(0xDB, Wirte_CMD); //设置VCOMH 电压倍率
	OLED_WR_Byte(0x30, Wirte_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;

	OLED_WR_Byte(0xA4, Wirte_CMD); //全局显示开启;bit0:1,开启;0,关闭;(白屏/黑屏)
	OLED_WR_Byte(0xA6, Wirte_CMD); //设置显示方式;bit0:1,反相显示;0,正常显示
	OLED_WR_Byte(0xAF, Wirte_CMD); //开启显示
	OLED_Clear();
}
//向SSD1306写入一个字节。
//dat:要写入的数据/命令
//cmd:数据/命令标志 0,表示命令;1,表示数据;
void OLED_WR_Byte(uint8_t dat,uint8_t cmd)
{
	switch(cmd)
	{
		case 0: OLED_DC_LOW();	break;
		case 1: OLED_DC_HIGH();	break;
	}
	for(uint8_t i=0; i<8; i++)
	{
		OLED_SCL_LOW();
		if(dat&0x80)
		{
			OLED_SDA_HIGH();
		}
		else
		{
			OLED_SDA_LOW();
		}
		OLED_SCL_HIGH();
		dat<<=1;
	}
	OLED_DC_HIGH();
}

//开启OLED显示
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,Wirte_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X14,Wirte_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,Wirte_CMD);  //DISPLAY ON
}
//关闭OLED显示
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,Wirte_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X10,Wirte_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,Wirte_CMD);  //DISPLAY OFF
}
//清屏函数，将显示显存全部清除
void OLED_Clear(void)
{
	for(uint8_t i=0; i<8; i++)
		for(uint8_t n=0; n<128; n++)
			OLED_GRAM[n][i]=0X00;
}
//画点函数
//x:0~127
//y:0~63
//mode:0 清空；1 填充
void OLED_DrawPoint(uint8_t x, uint8_t y, uint8_t mode)
{
	if(x>127 || y>63)
		return;
	uint8_t pos = 7 - y/8;
	uint8_t bx = y%8;
	uint8_t temp = 0x01<<(7-bx);
	if(mode)
		OLED_GRAM[x][pos] |= temp;
	else
		OLED_GRAM[x][pos] &= ~temp;
}
//x1,y1,x2,y2 填充区域的对角坐标
//确保点1、点2处于范围中，且点2大于点1
//mode:0 清空; 1 填充
void OLED_Fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t mode)
{
	for(uint8_t x=x1; x<=x2; x++)
	{
		for(uint8_t y=y1; y<=y2; y++)
			OLED_DrawPoint(x, y, mode);
	}
}
//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
//chr:一个字符
//size:选择字体 12/16/24
//mode:0 白底黑字; 1 黑底白字（正常）
void OLED_Show_Char(uint8_t x, uint8_t y, uint8_t chr, uint8_t size, uint8_t mode)
{
	uint8_t temp;
	uint8_t y0 = y;
	uint8_t csize = (size/8+((size%8)?1:0))*(size/2);		//得到字体一个字符对应点阵集所占的字节数
	chr = chr-' ';//得到偏移后的值	，空格在ASCII中十进制为32，而在字库中是第一位
    for(uint8_t t=0; t<csize; t++)
    {
		switch(size)//选择调用的字库
		{
			case 12: temp = asc2_1206[chr][t];	break;
			case 16: temp = asc2_1608[chr][t];	break;
			case 24: temp = asc2_2412[chr][t];	break;
			default:	break;
		}
		for(uint8_t t1=0; t1<8; t1++)
		{
			if(temp&0x80)
				OLED_DrawPoint(x, y, mode);
			else
				OLED_DrawPoint(x, y, !mode);
			temp <<= 1;
			y++;
			if((y-y0) == size)
			{
				y = y0;
				x++;
				break;
			}
		}
    }
}
//m^n函数，主要给下面程序用
uint32_t mypow(uint8_t m,uint8_t n)
{
	uint32_t result = 1;
	while(n--)
		result *= m;
	return result;
}

//显示2个数字
//x,y :起点坐标
//num:数值(0~4294967295);
//len :数字的位数
//size:字体大小
//mode:0 白底黑字; 1 黑底白字(正常)
void OLED_Show_Num(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size, uint8_t mode)
{
	uint8_t enshow = 0;
	for(uint8_t t=0; t<len; t++)
	{
		uint8_t temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_Show_Char(x+(size/2)*t, y, ' ', size, mode);
				continue;
			}
			else
				enshow=1;
		}
	 	OLED_Show_Char(x+(size/2)*t, y, temp+'0', size, mode); //temp+'0'：数字转字符
	}
}
//显示字符串
//x,y:起点坐标
//size:字体大小
//*ch:字符串起始地址
//mode:0 白底黑字; 1 黑底白字(正常)
void OLED_Show_Str(uint8_t x, uint8_t y, const uint8_t *ch, uint8_t size, uint8_t mode)
{
    while((*ch<='~')&&(*ch>=' '))//判断是不是非法字符
    {
//        if(x > (128-(size/2)))
//				{
//					x = 0;
//					y += size;
//				}
//        if(y > (64-size))
//				{
//					y = x = 0;
//					OLED_Clear();
//				}
        OLED_Show_Char(x, y, *ch, size, mode);
        x += size/2;
        ch++;
    }
}




/* 定义十进制(0-7)==>十六进制位转换表，由于显示
点数据是由左到右，所以十六进制位顺序是倒的 */
const uint8_t DCB2HEX_TAB[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

uint8_t OLED_JudgeOver(uint8_t x, uint8_t y)//判断输入坐标是否超过OLED像素边界
{
	if(x > (OLED_X_MAX-32))
		return 1;
	if(y > (OLED_Y_MAX-32))
		return 1;
    return 0;
}
void OLED_Show_Char24_32(uint8_t x, uint8_t y, uint8_t ch, uint8_t mode)
{
	uint8_t   font_date;
	uint8_t   i, j, k;

   //坐标越界则退出显示

	for(i=0; i<14; i++)//一个个查找字库
	{
		if(FONT24x32_TAB[i]==ch)
			break;
	}
	ch = i;

	for(i=0; i<32; i++)      // 显示共32行
	{
		for(j=0; j<3; j++)     // 每行共3字节
		{
//			font_date = FONT24x32[ch][i*3+j];

			for(k=0; k<8; k++)
			{
				if( font_date & DCB2HEX_TAB[k] )
					OLED_DrawPoint(x, y, mode);//灭
				else
					OLED_DrawPoint(x, y, !mode);//点亮，此处就得用"!"，而不是"~"。
				x++;
			}
		}
		y++;    // 指向下一行
		x -= 24;    // 恢复x值
   }
}
void OLED_Show_Char48_64(uint8_t x, uint8_t y, uint8_t ch, uint8_t mode)
{
	uint8_t   font_date;
	uint8_t   i, j, k;


	for(i=0; i<9; i++)//一个个查找字库,找不到的话显示字库中最后一个
	{
		if(FONT48x64_TAB[i]==ch)
			break;
	}
	ch = i;

	for(i=0; i<64; i++)      // 显示共32行
	{
		for(j=0; j<6; j++)     // 每行共3字节
		{
			font_date = FONT48x64[ch][i*6+j];

			for(k=0; k<8; k++)
			{
				if( font_date & DCB2HEX_TAB[k] )
					OLED_DrawPoint(x, y, mode);//灭
				else
					OLED_DrawPoint(x, y, !mode);//点亮，此处就得用"!"，而不是"~"。
				x++;
			}
		}
		y++;    // 指向下一行
		x -= 48;    // 恢复x值
   }
}

/*取字模时宽必须为8的倍数，这次取字模相当于是16x12*/
void OLED_Show_ZH12_12(uint8_t x, uint8_t y, uint8_t ch1, uint8_t ch2, uint8_t mode)
{
	uint8_t   font_dat;
	uint8_t   i, j, k;

   for(i=0; i<ZH_Num; i+=2)//一个个查找字库
   {  //需同时判断汉字的低字节和高字节
      if(FONT12x12_TAB[i]==ch1 && FONT12x12_TAB[i+1]==ch2)
         break;
   }
   ch1 = i/2;

   for(i=0; i<12; i++)//显示共12行
   {
      for(j=0; j<2; j++) //每行2字节
      {
         font_dat = FONT12x12[ch1][i*2+j];
         for(k=0; k<8; k++)
         {  /* 设置相应的点为color或为back_color */
            if( font_dat & DCB2HEX_TAB[k] )
               OLED_DrawPoint(x, y, mode);
            else
               OLED_DrawPoint(x, y, !mode);
            x++;
         }
      }
      y++;									// 指向下一行
      x -= 16;								// 恢复x值
   }
}
void  OLED_Show_StrAll(uint8_t x, uint8_t y, uint8_t *str, uint8_t mode)
{  
    while(1)
    {  
        if( (*str)=='\0' )
            break;
        if((*str<='~')&&(*str>=' '))
        {
            OLED_Show_Char(x, y, *str, 12, mode);
            x+=6;
            str++;
        }
        else
        {
            OLED_Show_ZH12_12(x, y, *str, *(str+1), mode);
            x+=12;
            str+=2;
        }
    }
}
//void OLED_Show_ZH14_16(uint8_t x, uint8_t y, uint8_t ch, uint8_t mode)
//{
//	uint8_t   font_dat;
//	uint8_t   i, j, k;

//   for(i=0; i<15; i++)//一个个查找字库
//   {
//      if(FONT24x32_TAB[i]==ch)
//         break;
//   }
//   ch = i;

//   for(i=0; i<16; i++)//显示共16行
//   {
//      for(j=0; j<2; j++) //每行2字节
//      {
//         font_dat = FONT24x32[ch][i*2+j];
//         for(k=0; k<8; k++)
//         {  /* 设置相应的点为color或为back_color */
//            if( font_dat & DCB2HEX_TAB[k] )
//               OLED_DrawPoint(x, y, mode);
//            else
//               OLED_DrawPoint(x, y, !mode);
//            x++;
//         }
//      }
//      y++;									// 指向下一行
//      x -= 16;								// 恢复x值
//   }
//}

/****************************************************************************
* 名称：GUI_LoadLine()
* 功能：输出单色图形的一行数据。
* 入口参数： x		指定显示位置，x坐标
*           y		指定显示位置，y坐标
*           data		要输出显示的数据。
*           x_num      要显示此行的点个数
* 出口参数：返回值为1时表示操作成功，为0时表示操作失败。
* 说明：操作失败原因是指定地址超出有效范围。
****************************************************************************/
void  OLED_Show_PicLine(uint8_t x, uint8_t y, uint8_t *data, uint32_t x_num, uint8_t mode)
{
	uint8_t bit_data=0;

	for(uint8_t i=0; i<x_num; i++)
	{
		if(0 == (i%8))	//判断是否要读取点阵数据
			bit_data = *data++;
		if( bit_data & DCB2HEX_TAB[i&0x07] )
			OLED_DrawPoint(x, y, mode);//灭
		else
			OLED_DrawPoint(x, y, !mode);//点亮，此处就得用"!"，而不是"~"。
		x++;
	}
}
/****************************************************************************
* 名称：GUI_LoadPic()
* 功能：输出单色图形数据。
* 入口参数： x		指定显示位置，x坐标
*           y		指定显示位置，y坐标
*           dat		要输出显示的数据
*           hno     要显示此行的点个数
*           lno     要显示此列的点个数
* 出口参数：无
* 说明：操作失败原因是指定地址超出有效范围。
****************************************************************************/
void  OLED_Show_Pic(uint8_t x, uint8_t y, uint8_t *data, uint8_t x_num, uint8_t y_num, uint8_t mode)
{
	for(uint8_t i=0; i<y_num; i++)
	{
		OLED_Show_PicLine(x, y, data, x_num, mode);// 输出一行数据
		y++;										// 显示下一行
		data = data + (x_num>>3);// 计算下一行的数据
		data++;
	}
}



//OLED的显存
//存放格式如下.
//[0]0 1 2 3 ... 127
//[1]0 1 2 3 ... 127
//[2]0 1 2 3 ... 127
//[3]0 1 2 3 ... 127
//[4]0 1 2 3 ... 127
//[5]0 1 2 3 ... 127
//[6]0 1 2 3 ... 127
//[7]0 1 2 3 ... 127


/*
    1、要赋入参数：
		{
			uint8_t ch[25] = "";
			sprintf(ch, "                     ", 赋入参数);	          "                     "
			OLED_ShowString(0, 0, ch, 12, 1);
		}
		2、直接显示：
		OLED_ShowString(0, 0, "                     ", 12);

		OLED_Show_Str(0,  0, "MJMJMJMJMJMJMJMJMJMJM", 12, 1);
		OLED_Show_Str(0, 13, "MJMJMJMJMJMJMJMJMJMJM", 12, 1);
		OLED_Show_Str(0, 26, "MJMJMJMJMJMJMJMJMJMJM", 12, 1);
		OLED_Show_Str(0, 39, "MJMJMJMJMJMJMJMJMJMJM", 12, 1);
		OLED_Show_Str(0, 52, "MJMJMJMJMJMJMJMJMJMJM", 12, 1);
*/


