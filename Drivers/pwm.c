

#include "pwm.h"



static FTM_Type * const FTMX[] = FTM_BASES;

void ftm_pwm_mux(FTMn ftmn, FTM_CHn ch)
{
    switch(ftmn)
    {
//        case ftm0:
//        {
//            SIM->SCGC |= SIM_SCGC_FTM0_MASK;                //开启FTM外设时钟
//            switch(ch)
//            {
//                case ftm_ch0:
//                {
//                    if(FTM0_CH0_PIN == PTA0)
//                    {
//                        SIM->PINSEL &= ~SIM_PINSEL_FTM0PS0_MASK;
//                    }
//                    else if(FTM0_CH0_PIN == PTB2)
//                    {
//                        SIM->PINSEL |= SIM_PINSEL_FTM0PS0_MASK;
//                    }
//                }break;
//                
//                case ftm_ch1:
//                {
//                    if(FTM0_CH1_PIN == PTA1)
//                    {
//                        SIM->PINSEL &= ~SIM_PINSEL_FTM0PS1_MASK;
//                    }
//                    else if(FTM0_CH1_PIN == PTB3)
//                    {
//                        SIM->PINSEL |= SIM_PINSEL_FTM0PS1_MASK;
//                    }
//                }break;
//            }
//        }break;
        
        case ftm1:
        {
            SIM->SCGC |= SIM_SCGC_FTM1_MASK;                //开启FTM外设时钟
            switch(ch)
            {
                case ftm_ch0:
                {
                    if(FTM1_CH0_PIN == PTC4)
                    {
                        SIM->PINSEL &= ~SIM_PINSEL_FTM1PS0_MASK;
                    }
                    else if(FTM1_CH0_PIN == PTH2)
                    {
                        SIM->PINSEL |= SIM_PINSEL_FTM1PS0_MASK;
                    }
                }break;

                case ftm_ch1:
                {
                    if(FTM1_CH1_PIN == PTC5)
                    {
                        SIM->PINSEL &= ~SIM_PINSEL_FTM1PS1_MASK;
                    }
                    else if(FTM1_CH1_PIN == PTE7)
                    {
                        SIM->PINSEL |= SIM_PINSEL_FTM1PS1_MASK;
                    }
                }break;
            }
        }break;
        
        case ftm2:
        {
            SIM->SCGC |= SIM_SCGC_FTM2_MASK;                //开启FTM外设时钟
            switch(ch)
            {
                case ftm_ch0:
                {
                    SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS0_MASK;       
                    if(FTM2_CH0_PIN == PTC0)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS0(0);
                    }
                    else if(FTM2_CH0_PIN == PTH0)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS0(1);
                    }
                    else if(FTM2_CH0_PIN == PTF0)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS0(2);
                    }
                }break;
                
                case ftm_ch1:
                {
                    SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS1_MASK;       
                    if(FTM2_CH1_PIN == PTC1)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS1(0);
                    }
                    else if(FTM2_CH1_PIN == PTH1)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS1(1);
                    }
                    else if(FTM2_CH1_PIN == PTF1)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS1(2);
                    }
                }break;
                
                case ftm_ch2:
                {
                    SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS2_MASK;       
                    if(FTM2_CH2_PIN == PTC2)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS2(0);
                    }
                    else if(FTM2_CH2_PIN == PTD0)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS2(1);
                    }
                    else if(FTM2_CH2_PIN == PTG4)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS2(2);
                    }
                }break;
                
                case ftm_ch3:
                {
                    SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS3_MASK;       
                    if(FTM2_CH3_PIN == PTC3)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS3(0);
                    }
                    else if(FTM2_CH3_PIN == PTD1)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS3(1);
                    }
                    else if(FTM2_CH3_PIN == PTG5)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS3(2);
                    }
                }break;
                
                case ftm_ch4:
                { 
                    if(FTM2_CH4_PIN == PTB4)
                    {
                        SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS4_MASK; 
                    }
                    else if(FTM2_CH4_PIN == PTG6)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS4_MASK;
                    }
                }break;
                
                case ftm_ch5:
                {
                    if(FTM2_CH5_PIN == PTB5)
                    {
                        SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS5_MASK;     
                    }
                    else if(FTM2_CH5_PIN == PTG7)
                    {
                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS5_MASK;
                    }
                }break;
            }
 
        }break;
    }
}


uint16_t period_[3];
//-------------------------------------------------------------------------------------------------------------------
//  @brief      FTM初始化
//  @param      ftmn            选择模块
//  @param      ch              选择通道
//  @param      freq            需要设置的频率（单位HZ）
//  @param      duty            需要设置的占空比
//  @return     void
//  @since      v2.0
//  Sample usage:               ftm_pwm_init(ftm0,ftm_ch0,50,500);		//ftm0模块，0通道，50HZ，百分之50的占空比
//-------------------------------------------------------------------------------------------------------------------
void ftm_pwm_init(FTMn ftmn, FTM_CHn ch, uint32_t freq, uint32_t duty)
{
    uint32_t clk_hz ;
    uint16_t mod;
    uint8_t  ps;
    uint16_t cv;
    
    ftm_pwm_mux(ftmn,ch);
    
    // 以 CPWMS = 0 ，边沿对齐
    clk_hz = 40000*1000;
    //clk_hz/(ps*mod) = freq        =>>     clk_hz/freq = (ps*mod)      =>>
    //clk_hz/freq < ((1<<n)*65536)  =>>    (clk_hz/freq)/65536 < (1>>n) =>> ((clk_hz/freq)/65536)>>n < 1
    mod = (clk_hz >> 16 ) / freq ;          // 临时用 mod 缓存一下
    ps = 0;
    while((mod >> ps) >= 1)                 // 等 (mod >> ps) < 1 才退出 while 循环 ，即求 PS 的最小值
        ps++;
    if(ps>0x07) return ;                    //超出设置范围，直接不设置跳出本函数，原因一般是由于PWM频率太低，或者总线频率太高导致
    
    mod = (clk_hz >> ps) / freq;            // 求 MOD 的值
    period_[ftmn] = mod;
    switch(ftmn)                            // 初值 CNTIN 设为0 ，脉冲宽度：CnV - CNTIN ，即 CnV 就是 脉冲宽度了。
    {
        // EPWM的周期 ： MOD - CNTIN + 0x0001 == MOD - 0 + 1
        // 则 CnV = (MOD - 0 + 1) * 占空比 = (MOD - 0 + 1) * duty/ FTM_PRECISON
		case ftm0:
			cv = (duty * (mod - 0 + 1)) / FTM0_PRECISON;
			break;

		case ftm1:
			cv = (duty * (mod - 0 + 1)) / FTM1_PRECISON;
			break;

		case ftm2:
			cv = (duty * (mod - 0 + 1)) / FTM2_PRECISON;
			break;
		default:
			break;
    }
    
//    FTMX[ftmn]->MOD = mod;                  //设置PWM周期
    FTMX[ftmn]->MOD = 3199;                  //设置PWM周期
    
    FTMX[ftmn]->CONTROLS[ch].CnSC &= ~FTM_CnSC_ELSA_MASK;
    FTMX[ftmn]->CONTROLS[ch].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
    
    // set FTM clock to system clock 
    FTMX[ftmn]->SC = ( 0
                       //| FTM_SC_CPWMS_MASK       //0：边沿对齐 ，1： 中心对齐 （注释了表示 0）
//                       | FTM_SC_PS(ps)             //分频因子，分频系数 = 2^PS
                       | FTM_SC_PS(0)             //分频因子，分频系数 = 2^PS
                       | FTM_SC_CLKS(1)            //时钟选择， 0：没选择时钟，禁用； 1：bus 时钟； 2：MCGFFCLK； 3：EXTCLK（ 由SIM_SOPT4 选择输入管脚 FTM_CLKINx）
                       //| FTM_SC_TOIE_MASK        //溢出中断使能（注释了表示 禁止溢出中断）
                     );

    
    if(ftm2 == ftmn)FTMX[ftmn]->CNTIN = 0;         //设置计数器初值，一般没特殊用途就清零
//    FTMX[ftmn]->CONTROLS[ch].CnV = cv;             //设置占空比
	cv = 1600;
    FTMX[ftmn]->CONTROLS[ch].CnV = cv;             //设置占空比
    
    FTMX[ftmn]->CNT = 0;                           //计数器，写任意值都会加载CNTIN的值
    
}

const FTM_MemMapPtr FTM_ARR[]={FTM0_BASE_PTR,FTM1_BASE_PTR,FTM2_BASE_PTR};

void FTM_PWM_set_CnV(FTMn ftmNo, FTM_CHn channel, uint16_t cnv)
{
    FTMX[ftmNo]->CONTROLS[channel].CnV = cnv;
//    FTM_CnV_REG(FTM_ARR[ftmNo], channel) = cnv;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      占空比设置
//  @param      ftmn            选择模块
//  @param      ch              选择通道
//  @param      duty            需要设置的占空比
//  @return     void
//  @since      v2.0
//  Sample usage:               ftm_pwm_duty(ftm0,ftm_ch0,500);		//ftm0模块，0通道，百分之50的占空比
//-------------------------------------------------------------------------------------------------------------------
void ftm_pwm_duty(FTMn ftmn, FTM_CHn ch, uint32_t duty)
{
    uint32_t cv;
    //占空比 = (CnV-CNTIN)/(MOD-CNTIN+1)
    switch(ftmn)
    {
    case ftm0:
        cv = (duty * (period_[ftmn] - 0 + 1)) / FTM0_PRECISON;
        break;

    case ftm1:
        cv = (duty * (period_[ftmn] - 0 + 1)) / FTM1_PRECISON;
        break;

    case ftm2:
        cv = (duty * (period_[ftmn] - 0 + 1)) / FTM2_PRECISON;
        break;

    default:
        break;
    }
    
    FTMX[ftmn]->CONTROLS[ch].CnV = cv;      //设置占空比
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      频率设置
//  @param      ftmn            选择模块
//  @param      freq            需要设置的频率（单位HZ）
//  @return     void
//  @since      v2.0
//  Sample usage:               ftm_pwm_freq(ftm0,50);		//ftm0模块，50HZ
//-------------------------------------------------------------------------------------------------------------------
void ftm_pwm_freq(FTMn ftmn, uint32_t freq)
{
    uint32_t clk_hz;        //bus频率/2
    uint32_t mod;
    uint8_t ps;

    // 以 CPWMS = 0 ，边沿对齐
    clk_hz = 40000 * 1000 ;
    
    //clk_hz/(ps*mod) = freq        =>>     clk_hz/freq = (ps*mod)      =>>
    //clk_hz/freq < ((1<<n)*65536)  =>>    (clk_hz/freq)/65536 < (1>>n) =>> ((clk_hz/freq)/65536)>>n < 1
    mod = (clk_hz >> 16 ) / freq ;          // 临时用 mod 缓存一下
    ps = 0;
    while((mod >> ps) >= 1)                 // 等 (mod >> ps) < 1 才退出 while 循环 ，即求 PS 的最小值
        ps++;
    if(ps>0x07) return ;                    //超出设置范围，直接不设置跳出本函数，原因一般是由于PWM频率太低，或者总线频率太高导致
    
    mod = (clk_hz >> ps) / freq;            // 求 MOD 的值
    period_[ftmn] = mod;
    
    
    FTMX[ftmn]->MOD = mod;                  //设置PWM周期
    
    // set FTM clock to system clock 
    FTMX[ftmn]->SC = ( 0
                       //| FTM_SC_CPWMS_MASK       //0：边沿对齐 ，1： 中心对齐 （注释了表示 0）
                       | FTM_SC_PS(ps)             //分频因子，分频系数 = 2^PS
                       | FTM_SC_CLKS(1)            //时钟选择， 0：没选择时钟，禁用； 1：bus 时钟； 2：MCGFFCLK； 3：EXTCLK（ 由SIM_SOPT4 选择输入管脚 FTM_CLKINx）
                       //| FTM_SC_TOIE_MASK        //溢出中断使能（注释了表示 禁止溢出中断）
                     );

    
    if(ftm2 == ftmn)FTMX[ftmn]->CNTIN = 0;  //设置计数器初值，一般没特殊用途就清零
    FTMX[ftmn]->CNT = 0;                    //计数器，写任意值都会架在CNTIN的值
}


void ftm_count_mux(FTMn ftmn)
{
    
    switch(ftmn)
    {
        case ftm0:
        {
            SIM->SCGC |= SIM_SCGC_FTM0_MASK;                //开启FTM外设时钟
            SIM->PINSEL &= ~SIM_PINSEL_FTM0CLKPS_MASK;      //清除外部时钟引脚选择
            if(FTM0_COUNT_PIN == PTA5)
            {
                 Pin_Output_Config(PTA, PTA5, Pull_Up);
							
                SIM->PINSEL |= SIM_PINSEL_FTM0CLKPS(0);     //选择外部时钟输入引脚 A5
            }
            
            else if(FTM0_COUNT_PIN == PTE0)
            {
             
							 Pin_Output_Config(PTE, PTE0, Pull_Up);
                SIM->PINSEL |= SIM_PINSEL_FTM0CLKPS(1);     //选择外部时钟输入引脚 E0
            }
            
            else if(FTM0_COUNT_PIN == PTE7)
            {  
           
							  Pin_Output_Config(PTE, PTE7, Pull_Up);
                SIM->PINSEL |= SIM_PINSEL_FTM0CLKPS(2);     //选择外部时钟输入引脚 E7
            }
        }break;
        
        case ftm1:
        {
            SIM->SCGC |= SIM_SCGC_FTM1_MASK;                //开启FTM外设时钟
            SIM->PINSEL &= ~SIM_PINSEL_FTM1CLKPS_MASK;      //清除外部时钟引脚选择
            if(FTM1_COUNT_PIN == PTA5)
            {
                Pin_Output_Config(PTA, PTA5, Pull_Up);
                SIM->PINSEL |= SIM_PINSEL_FTM1CLKPS(0);     //选择外部时钟输入引脚 A5
            }
            
            else if(FTM1_COUNT_PIN == PTE0)
            {
                 Pin_Output_Config(PTE, PTE0, Pull_Up);
                SIM->PINSEL |= SIM_PINSEL_FTM1CLKPS(1);     //选择外部时钟输入引脚 E0
            }
            
            else if(FTM1_COUNT_PIN == PTE7)
            {
                Pin_Output_Config(PTE, PTE7, Pull_Up);
                SIM->PINSEL |= SIM_PINSEL_FTM1CLKPS(2);     //选择外部时钟输入引脚 E7
            }
        }break;
        
        case ftm2:
        {
            SIM->SCGC |= SIM_SCGC_FTM2_MASK;                //开启FTM外设时钟
            SIM->PINSEL &= ~SIM_PINSEL_FTM2CLKPS_MASK;      //清除外部时钟引脚选择
            FTM2->CNTIN = 0;
            if(FTM2_COUNT_PIN == PTA5)
            {
                Pin_Output_Config(PTA, PTA5, Pull_Up);
                SIM->PINSEL |= SIM_PINSEL_FTM2CLKPS(0);     //选择外部时钟输入引脚 A5
            }
            
            else if(FTM2_COUNT_PIN == PTE0)
            {
               Pin_Output_Config(PTE, PTE0, Pull_Up);
                SIM->PINSEL |= SIM_PINSEL_FTM2CLKPS(1);     //选择外部时钟输入引脚 E0
            }
            
            else if(FTM2_COUNT_PIN == PTE7)
            {
                 Pin_Output_Config(PTE, PTE7, Pull_Up);
                SIM->PINSEL |= SIM_PINSEL_FTM2CLKPS(2);     //选择外部时钟输入引脚 E7
            }
        }break;
        
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      外部计数初始化  获取计数值、用于编码器测速，无法识别方向只能计数，建议使用带方向输出的编码器
//  @param      ftmn            选择模块
//  @return     void
//  @since      v2.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void ftm_count_init(FTMn ftmn)
{
    ftm_count_mux(ftmn);                                    //引脚复用 开启上拉 开启对应外设时钟
    
    FTMX[ftmn]->SC |= FTM_SC_PS(0);	                        //分频系数	
    FTMX[ftmn]->SC |= FTM_SC_CLKS(3);                       //选择外部时钟作为FTM输入时钟
                
    FTMX[ftmn]->CNT = 0;                                    //加载初始化值
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      获取计数值      用于编码器测速，无法识别方向只能计数，建议使用带方向输出的编码器
//  @param      ftmn            选择模块
//  @return     uint16          返回计数值
//  @since      v2.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
uint16_t ftm_count_get(FTMn ftmn)
{
    return FTMX[ftmn]->CNT ;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      清除计数值      用于编码器测速，无法识别方向只能计数，建议使用带方向输出的编码器
//  @param      ftmn            选择模块
//  @since      v2.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void ftm_count_clean(FTMn ftmn)
{
    FTMX[ftmn]->CNT = 0;
}


//#include "pwm.h"

////FTM0、FTM1、FTM2地址映射
//const FTM_MemMapPtr FTM_ARR[]={FTM0_BASE_PTR,FTM1_BASE_PTR,FTM2_BASE_PTR};
//static FTM_Type * const FTMX[] = FTM_BASES;

//static uint16_t MOD_VALUE;


////============================================================================
////函数名称：FTM_PWM_init
////函数返回：无
////参数说明：ftmNo:FTM模块号：FTM_0、FTM_1、FTM_2
////          channel:选择通道号：FTM0和FTM1：通道0、通道1
////                             FTM2:通道0、1、2、3、4、5
////          freq：设置PWM的频率，单位为KHz。取值从0.012到1500
////          duty：占空比：精度取决于设置的freq值，精度为freq/1500。
////功能概要：初始化PWM模块
////============================================================================
//void FTM_PWM_init(FTMn ftmNo, FTM_CHn channel, float freq, float duty)
//{
//	uint16_t duty_channel;
//	uint16_t mod;

//	//防止模块号越界
//		if(ftmNo>2) ftmNo=2;

//	//计算mod值，周期（ms) = MOD / 1500
//	if(freq <= 0.012)
//		mod = 0xFFFF;
//	else if(freq>1500)
//		mod=0;
//	else
//		mod = 1500 / freq;

//	//防止周期越界
//	if(duty > 100)
//		duty = 100;
//	if(duty < 0)
//		duty = 0;

//	switch(ftmNo)
//	{
//		case FTM_0:

//			#if(FTM0_CHANNEL0_GROUP == 1)
//				//复用引脚PTA0为FTM0通道0功能
//				SIM_PINSEL0 &= ~SIM_PINSEL_FTM0PS0_MASK;
//			#endif

//			#if(FTM0_CHANNEL0_GROUP == 2)
//				//复用引脚PTB2为FTM0通道0功能
//				SIM_PINSEL0 |= SIM_PINSEL_FTM0PS0_MASK;
//			#endif

//			#if(FTM0_CHANNEL1_GROUP == 1)
//				//复用引脚PTA1为FTM0通道1功能
//				SIM_PINSEL0 &= ~SIM_PINSEL_FTM0PS1_MASK;
//			#endif

//			#if(FTM0_CHANNEL1_GROUP == 2)
//			    //复用引脚PTB3为FTM0通道1功能
//			    SIM_PINSEL0 |= SIM_PINSEL_FTM0PS1_MASK;
//			#endif

//			//使能FTM0的总线时钟
//			SIM_SCGC |= SIM_SCGC_FTM0_MASK;
//			break;

//		case FTM_1:
//            #if(FTM1_CHANNEL0_GROUP==1)     //复用引脚PTC4为FTM1通道0功能
//				SIM_PINSEL0 &= ~SIM_PINSEL_FTM1PS0_MASK;
//			#endif

//			#if(FTM1_CHANNEL0_GROUP==2)     //复用引脚PTH2为FTM1通道0功能
//				SIM_PINSEL0 |= SIM_PINSEL_FTM1PS0_MASK;
//			#endif

//			#if(FTM1_CHANNEL1_GROUP==1)     //复用引脚PTC5为FTM1通道1功能
//				SIM_PINSEL0 &= ~SIM_PINSEL_FTM1PS1_MASK;
//			#endif

//			#if(FTM1_CHANNEL1_GROUP==2)     //复用引脚PTE7为FTM1通道1功能
//				SIM_PINSEL0 |= SIM_PINSEL_FTM1PS1_MASK;
//			#endif

//			SIM_SCGC |= SIM_SCGC_FTM1_MASK; //使能FTM1的总线时钟
//			break;

//		case FTM_2:
///**FTM2 CH_0***************************************************/
//			#if(FTM2_CHANNEL0_GROUP==1)     //复用引脚PTC0为FTM2通道0功能
//				SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS0_MASK;
//			#endif

//			#if(FTM2_CHANNEL0_GROUP==2)     //复用引脚PTH0为FTM2通道0功能
//				SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS0(1);
//			#endif

//			#if(FTM2_CHANNEL0_GROUP==3)     //复用引脚PTF0为FTM2通道0功能
//				SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS0(2);
//			#endif
//        
///**FTM2 CH_1***************************************************/
//			#if(FTM2_CHANNEL1_GROUP==1)      //复用引脚PTC1为FTM2通道1功能
//				SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS1_MASK;
//			#endif

//			#if(FTM2_CHANNEL1_GROUP==2)      //复用引脚PTH1为FTM2通道1功能
//				SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS1(1);
//            #endif
//  
//		    #if(FTM2_CHANNEL1_GROUP==3)      //复用引脚PTF1为FTM2通道1功能
//                SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS1(2);
//            #endif
//            
///**FTM2 CH_2***************************************************/
//            #if(FTM2_CHANNEL2_GROUP==1)      //复用引脚PTC2为FTM2通道2功能
//				SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS2_MASK;
//			#endif

//			#if(FTM2_CHANNEL2_GROUP==2)      //复用引脚PTD0为FTM2通道2功能
//				SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS2(1);
//            #endif

//            #if(FTM2_CHANNEL2_GROUP==3)      //复用引脚PTG4为FTM2通道2功能
//			       SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS2(2);
//            #endif

///**FTM2 CH_3***************************************************/
//			#if(FTM2_CHANNEL3_GROUP==1)      //复用引脚PTC3为FTM2通道3功能
//				SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS3_MASK;
//			#endif
//            
//			#if(FTM2_CHANNEL3_GROUP==2)      //复用引脚PTD1为FTM2通道3功能
//				SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS3(1);
//			#endif

//			#if(FTM2_CHANNEL3_GROUP==3)      //复用引脚PTG5为FTM2通道3功能
//			   SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS3(2);
//			#endif
//            
///**FTM2 CH_4***************************************************/
//			#if(FTM2_CHANNEL4_GROUP==1)      //复用引脚PTB4为FTM2通道4功能
//				SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS4_MASK;
//			#endif

//			#if(FTM2_CHANNEL4_GROUP==2)      //复用引脚PTG6为FTM2通道4功能
//				SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS4_MASK;
//			#endif
//            
///**FTM2 CH_5***************************************************/
//			#if(FTM2_CHANNEL5_GROUP==1)      //复用引脚PTB5为FTM2通道5功能
//				SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS5_MASK;
//			#endif

//			#if(FTM2_CHANNEL5_GROUP==2)      //复用引脚PTG7为FTM2通道5功能
//				SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS5_MASK;
//			#endif

//			SIM_SCGC |= SIM_SCGC_FTM2_MASK;  //使能FTM2的总线时钟
//			break;
//	}

//    //写保护禁止
//    FTM_ARR[ftmNo]->MODE |= FTM_MODE_WPDIS_MASK;
//    //总线时钟频率24MHz,分频因子16,分频后为1.5MHz
////    FTM_ARR[ftmNo]->SC |= FTM_SC_PS(4);
//    FTM_ARR[ftmNo]->SC |= FTM_SC_PS(0);
//    //左对齐，先高电平后低电平
//    FTM_CnSC_REG(FTM_ARR[ftmNo], channel) |= FTM_CnSC_ELSB_MASK;
//    //边沿对齐
//    FTM_CnSC_REG(FTM_ARR[ftmNo], channel) &= ~FTM_CnSC_ELSA_MASK;
//    FTM_CnSC_REG(FTM_ARR[ftmNo], channel) |= FTM_CnSC_MSB_MASK;
//    //计数器清零
//    FTM_ARR[ftmNo]->CNT=0;
//    //中断禁止
//    FTM_ARR[ftmNo]->SC &=  ~FTM_SC_TOIE_MASK;
//    //FTM2使能
//    FTM_ARR[ftmNo]->MODE &= ~FTM_MODE_FTMEN_MASK;
//    //启用需要的输出通道，屏蔽其他通道
//    FTM_ARR[ftmNo]->OUTMASK = (0xFE << channel);
//    //禁止双边沿捕捉模式
//    FTM_ARR[ftmNo]->COMBINE = 0;
//    //FTM2计数初始值为0
//    FTM_ARR[ftmNo]->CNTIN = 0;
//    //周期=(MOD-CNTIN+1)*时钟周期=2.5ms
//    FTM_ARR[ftmNo]->MOD = mod;
////    FTM_ARR[ftmNo]->MOD = 1599;
//    MOD_VALUE = mod;
//    //计算通道寄存器的值，设置占空比
//    duty_channel = (uint16_t)((float)mod * duty / 100);
//    //设置通道值寄存器
//    FTM_CnV_REG(FTM_ARR[ftmNo], channel) = duty_channel;
////    FTM_CnV_REG(FTM_ARR[ftmNo], channel) = 800;
//    //使用总线时钟
//    FTM_ARR[ftmNo]->SC |= FTM_SC_CLKS(1);
//}

////============================================================================
////函数名称：FTM_PWM_set_duty
////函数返回：无
////参数说明：ftmNo:FTM模块号：FTM_0、FTM_1、FTM_2
////          channel:选择通道号：FTM0和FTM1：通道0、通道1
////                             FTM2:通道0、1、2、3、4、5
////          duty：占空比：精度取决于设置的mod值，精度为1/mod。
////功能概要：初始化PWM模块
////============================================================================
//void FTM_PWM_set_duty(FTMn ftmNo, FTM_CHn channel, float duty)
//{
//	uint16_t duty_channel;

//	if(duty > 100)
//		duty = 100;
//	if(duty < 0)
//		duty = 0;
//    //写保护禁止
//    // FTM_ARR[ftmNo]->MODE |= FTM_MODE_WPDIS_MASK;
//    //计算通道寄存器的值，设置占空比
//    duty_channel = (uint16_t)((float)MOD_VALUE * duty / 100);
//    //设置通道值寄存器
//    FTM_CnV_REG(FTM_ARR[ftmNo], channel) = duty_channel;
//}

//void FTM_PWM_set_CnV(FTMn ftmNo, FTM_CHn channel, uint16_t cnv)
//{
//    FTM_CnV_REG(FTM_ARR[ftmNo], channel) = cnv;
//}
/////*********************************************************************************************************************
//// * COPYRIGHT NOTICE
//// * Copyright (c) 2017,逐飞科技
//// * All rights reserved.
//// * 技术讨论QQ群：179029047
//// *
//// * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
//// * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
//// *
//// * @file       		KEA128_ftm
//// * @company	   		成都逐飞科技有限公司
//// * @author     		逐飞科技(QQ3184284598)
//// * @version    		v2.0
//// * @Software 		IAR 7.7 or MDK 5.23
//// * @Target core		S9KEA128AMLK
//// * @Taobao   		https://seekfree.taobao.com/
//// * @date       		2017-11-6
//// ********************************************************************************************************************/

////#include "pwm.h"




////static FTM_Type * const FTMX[] = FTM_BASES;

////void ftm_pwm_mux(FTMn FTM_X, FTM_CHn CH_X)
////{
////    switch(FTM_X)
////    {
////        case FTM_0:
////        {
////            SIM->SCGC |= SIM_SCGC_FTM0_MASK;                //开启FTM外设时钟
////            switch(CH_X)
////            {
////                case CH_0:
////                {
////                    if(FTM0_CH0_PIN == PTA0)
////                    {
////                        SIM->PINSEL &= ~SIM_PINSEL_FTM0PS0_MASK;
////                    }
////                    else if(FTM0_CH0_PIN == PTB2)
////                    {
////                        SIM->PINSEL |= SIM_PINSEL_FTM0PS0_MASK;
////                    }
////                }break;
////                
////                case CH_1:
////                {
////                    if(FTM0_CH1_PIN == PTA1)
////                    {
////                        SIM->PINSEL &= ~SIM_PINSEL_FTM0PS1_MASK;
////                    }
////                    else if(FTM0_CH1_PIN == PTB3)
////                    {
////                        SIM->PINSEL |= SIM_PINSEL_FTM0PS1_MASK;
////                    }
////                }break;
////            }
////        }break;
////        
////        case FTM_1:
////        {
////            SIM->SCGC |= SIM_SCGC_FTM1_MASK;                //开启FTM外设时钟
////            switch(CH_X)
////            {
////                case CH_0:
////                {
////                    if(FTM1_CH0_PIN == PTC4)
////                    {
////                        SIM->PINSEL &= ~SIM_PINSEL_FTM1PS0_MASK;
////                    }
////                    else if(FTM1_CH0_PIN == PTH2)
////                    {
////                        SIM->PINSEL |= SIM_PINSEL_FTM1PS0_MASK;
////                    }
////                }break;

////                case CH_1:
////                {
////                    if(FTM1_CH1_PIN == PTC5)
////                    {
////                        SIM->PINSEL &= ~SIM_PINSEL_FTM1PS1_MASK;
////                    }
////                    else if(FTM1_CH1_PIN == PTE7)
////                    {
////                        SIM->PINSEL |= SIM_PINSEL_FTM1PS1_MASK;
////                    }
////                }break;
////            }
////        }break;
////        
////        case FTM_2:
////        {
////            SIM->SCGC |= SIM_SCGC_FTM2_MASK;                //开启FTM外设时钟
////            switch(CH_X)
////            {
////                case CH_0:
////                {
////                    SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS0_MASK;       
////                    if(FTM2_CH0_PIN == PTC0)
////                    {
////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS0(0);
////                    }
////                    else if(FTM2_CH0_PIN == PTH0)
////                    {
////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS0(1);
////                    }
////                    else if(FTM2_CH0_PIN == PTF0)
////                    {
////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS0(2);
////                    }
////                }break;
////                
////                case CH_1:
////                {
////                    SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS1_MASK;       
////                    if(FTM2_CH1_PIN == PTC1)
////                    {
////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS1(0);
////                    }
////                    else if(FTM2_CH1_PIN == PTH1)
////                    {
////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS1(1);
////                    }
////                    else if(FTM2_CH1_PIN == PTF1)
////                    {
////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS1(2);
////                    }
////                }break;
////                
////                case CH_2:
////                {
////                    SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS2_MASK;       
//////                    if(FTM2_CH2_PIN == PTC2)
////                    if(1)
////                    {
////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS2(0);
////                    }
//////                    else if(FTM2_CH2_PIN == PTD0)
//////                    {
//////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS2(1);
//////                    }
//////                    else if(FTM2_CH2_PIN == PTG4)
//////                    {
//////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS2(2);
//////                    }
////                }break;
////                
////                case CH_3:
////                {
////                    SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS3_MASK;       
//////                    if(FTM2_CH3_PIN == PTC3)
////                    if(1)
////                    {
////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS3(0);
////                        
////                    }
//////                    else if(FTM2_CH3_PIN == PTD1)
//////                    {
//////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS3(1);
//////                    }
//////                    else if(FTM2_CH3_PIN == PTG5)
//////                    {
//////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS3(2);
//////                    }
////                }break;
////                
////                case CH_4:
////                { 
//////                    if(FTM2_CH4_PIN == PTB4)
////                    if(1)
////                    {
////                        SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS4_MASK; 
////                    }
//////                    else if(FTM2_CH4_PIN == PTG6)
//////                    {
//////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS4_MASK;
//////                    }
////                }break;
////                
////                case CH_5:
////                {
//////                    if(FTM2_CH5_PIN == PTB5)
////                    if(1)
////                    {
////                        SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS5_MASK;
//////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS5_MASK;                        
////                    }
//////                    else if(FTM2_CH5_PIN == PTG7)
//////                    {
//////                        SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS5_MASK;
//////                    }
////                }break;
////            }
//// 
////        }break;
////    }
////}


////uint16_t perioddd[3];
//////-------------------------------------------------------------------------------------------------------------------
//////  @brief      FTM初始化
//////  @param      ftmn            选择模块
//////  @param      ch              选择通道
//////  @param      freq            需要设置的频率（单位HZ）
//////  @param      duty            需要设置的占空比
//////  @return     void
//////  @since      v2.0
//////  Sample usage:               ftm_pwm_init(ftm0,ftm_ch0,50,500);		//ftm0模块，0通道，50HZ，百分之50的占空比
//////   ！！！！！！！！！！！！有待精简，暂时先不改
//////-------------------------------------------------------------------------------------------------------------------
////void ftm_pwm_init(FTMn FTM_X, FTM_CHn ch, uint32_t freq, uint32_t duty)
////{
////    uint32_t clk_hz ;
////    uint16_t mod;
////    uint8_t  ps;
////    uint16_t cv;
////    
////    ftm_pwm_mux(FTM_X, ch);
////    
////    // 以 CPWMS = 0 ，边沿对齐
////    clk_hz = DEFAULT_SYSTEM_CLOCK/2;  //总线时钟为系统时钟的一半
////    //clk_hz/(ps*mod) = freq        =>>     clk_hz/freq = (ps*mod)      =>>
////    //clk_hz/freq < ((1<<n)*65536)  =>>    (clk_hz/freq)/65536 < (1>>n) =>> ((clk_hz/freq)/65536)>>n < 1
////    mod = (clk_hz >> 16 ) / freq ;          // 临时用 mod 缓存一下
////    ps = 0;
////    while((mod >> ps) >= 1)                 // 等 (mod >> ps) < 1 才退出 while 循环 ，即求 PS 的最小值
////        ps++;
////    if(ps>0x07) return ;                    //超出设置范围，直接不设置跳出本函数，原因一般是由于PWM频率太低，或者总线频率太高导致
////    
////    mod = (clk_hz >> ps) / freq;            // 求 MOD 的值
////    perioddd[FTM_X] = mod;
////    switch(FTM_2)                            // 初值 CNTIN 设为0 ，脉冲宽度：CnV - CNTIN ，即 CnV 就是 脉冲宽度了。
////    {
////        // EPWM的周期 ： MOD - CNTIN + 0x0001 == MOD - 0 + 1
////        // 则 CnV = (MOD - 0 + 1) * 占空比 = (MOD - 0 + 1) * duty/ FTM_PRECISON
////    case FTM_0:
////        cv = (duty * (mod - 0 + 1)) / FTM0_PRECISON;
////        break;

////    case FTM_1:
////        cv = (duty * (mod - 0 + 1)) / FTM1_PRECISON;
////        break;

////    case FTM_2:
////        cv = (duty * (mod - 0 + 1)) / FTM2_PRECISON;
////        break;
////    default:
////        break;
////    }
////    
////    FTMX[FTM_X]->MOD = mod;                  //设置PWM周期
////    
////    FTMX[FTM_X]->CONTROLS[ch].CnSC &= ~FTM_CnSC_ELSA_MASK;
////    FTMX[FTM_X]->CONTROLS[ch].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
////    
////    //设置FTM时钟
////    FTMX[FTM_X]->SC = ( 0
////                       //| FTM_SC_CPWMS_MASK       //0：边沿对齐 ，1： 中心对齐 （注释了表示 0）
////                       | FTM_SC_PS(ps)             //分频因子，分频系数 = 2^PS
////                       | FTM_SC_CLKS(1)            //时钟选择， 0：没选择时钟，禁用； 1：bus 时钟； 2：MCGFFCLK； 3：EXTCLK（ 由SIM_SOPT4 选择输入管脚 FTM_CLKINx）
////                       //| FTM_SC_TOIE_MASK        //溢出中断使能（注释了表示 禁止溢出中断）
////                     );

////    
////    if(FTM_2 == FTM_X)
////        FTMX[FTM_X]->CNTIN = 0;         //设置计数器初值，一般没特殊用途就清零
////    FTMX[FTM_X]->CONTROLS[ch].CnV = cv;             //设置占空比
////    FTMX[FTM_X]->CNT = 0;                           //计数器，写任意值都会加载CNTIN的值
////    
////}


//////-------------------------------------------------------------------------------------------------------------------
//////  @brief      占空比设置
//////  @param      ftmn            选择模块
//////  @param      ch              选择通道
//////  @param      duty            需要设置的占空比
//////  @return     void
//////  @since      v2.0
//////  Sample usage:               ftm_pwm_duty(ftm0,ftm_ch0,500);		//ftm0模块，0通道，百分之50的占空比
//////-------------------------------------------------------------------------------------------------------------------
////void ftm_pwm_duty(FTMn FTM_X, FTM_CHn ch, uint32_t duty)
////{
////    uint32_t cv;
////    //占空比 = (CnV-CNTIN)/(MOD-CNTIN+1)
////    switch(FTM_X)
////    {
////    case FTM_0:
////        cv = (duty * (perioddd[FTM_X] - 0 + 1)) / FTM0_PRECISON;
////        break;

////    case FTM_1:
////        cv = (duty * (perioddd[FTM_X] - 0 + 1)) / FTM1_PRECISON;
////        break;

////    case FTM_2:
////        cv = (duty * (perioddd[FTM_X] - 0 + 1)) / FTM2_PRECISON;
////        break;

////    default:
////        break;
////    }
////    
////    FTMX[FTM_X]->CONTROLS[ch].CnV = cv;      //设置占空比
////}

//////-------------------------------------------------------------------------------------------------------------------
//////  @brief      频率设置
//////  @param      ftmn            选择模块
//////  @param      freq            需要设置的频率（单位HZ）
//////  @return     void
//////  @since      v2.0
//////  Sample usage:               ftm_pwm_freq(ftm0,50);		//ftm0模块，50HZ
//////-------------------------------------------------------------------------------------------------------------------
////void ftm_pwm_freq(FTMn FTM_X, uint32_t Freq)
////{
////    uint32_t Mod;
////    uint8_t Div = 0;

////    Mod = (BUS_CLK_KHZ >> 16 ) / Freq ;   // 临时用 mod 缓存一下

////    while((Mod >> Div) >= 1)              // 等 (mod >> ps) < 1 才退出 while 循环 ，即求 PS 的最小值
////        Div++;
////    if(Div>0x07)                          //超出设置范围，直接不设置跳出本函数，原因一般是由于PWM频率太低，或者总线频率太高导致
////        return ;
////    
////    Mod = (BUS_CLK_KHZ >> Div) / Freq;            // 求 MOD 的值
////    perioddd[FTM_X] = Mod;
////    
////    
////    FTMX[FTM_X]->MOD = Mod;                  //设置PWM周期
////    
////    // set FTM clock to system clock 
////    FTMX[FTM_X]->SC = ( 0
////                       //| FTM_SC_CPWMS_MASK       //0：边沿对齐 ，1： 中心对齐 （注释了表示 0）
////                       | FTM_SC_PS(Div)             //分频因子，分频系数 = 2的Div次方
////                       | FTM_SC_CLKS(1)            //时钟选择， 0：没选择时钟，禁用； 1：bus 时钟； 2：MCGFFCLK； 3：EXTCLK（ 由SIM_SOPT4 选择输入管脚 FTM_CLKINx）
////                       //| FTM_SC_TOIE_MASK        //溢出中断使能（注释了表示 禁止溢出中断）
////                     );

////    
////    if(FTM_2 == FTM_X)            //设置计数器初值，一般没特殊用途就清零
////        FTMX[FTM_X]->CNTIN = 0;
////    FTMX[FTM_X]->CNT = 0;         //计数器，写任意值都会架在CNTIN的值
////}

//////#define PTX(PTX_n)  (PTX_n>>5)  //获取模块号 PTX_n/32
//////#define PTn(PTX_n)  (PTX_n&0x1f)//获取引脚号 PTX_n%32


//void FTM_Count_Mux(FTMn ftmn)
//{
////    switch(ftmn)
////    {
////        case FTM_0:
////        {
////            SIM->SCGC |= SIM_SCGC_FTM0_MASK;                //开启FTM外设时钟
////            SIM->PINSEL &= ~SIM_PINSEL_FTM0CLKPS_MASK;      //清除外部时钟引脚选择
////            if(FTM0_COUNT_PIN == PTA5)
////            {
////                Pin_Pull_State(PTA, PTA5, Pull_Up);
////                SIM->PINSEL |= SIM_PINSEL_FTM0CLKPS(0);     //选择外部时钟输入引脚 A5
////            }
////            
////            else if(FTM0_COUNT_PIN == PTE0)
////            {
////                Pin_Pull_State(PTE, PTE0, Pull_Up);
////                SIM->PINSEL |= SIM_PINSEL_FTM0CLKPS(1);     //选择外部时钟输入引脚 E0
////            }
////            
////            else if(FTM0_COUNT_PIN == PTE7)
////            {
////                Pin_Pull_State(PTE, PTE7, Pull_Up);
////                SIM->PINSEL |= SIM_PINSEL_FTM0CLKPS(2);     //选择外部时钟输入引脚 E7
////            }
////        }break;
////        
////        case FTM_1:
////        {
////            SIM->SCGC |= SIM_SCGC_FTM1_MASK;                //开启FTM外设时钟
////            SIM->PINSEL &= ~SIM_PINSEL_FTM1CLKPS_MASK;      //清除外部时钟引脚选择
////            if(FTM1_COUNT_PIN == PTA5)
////            {
////                Pin_Pull_State(PTA, PTA5, Pull_Up);
////                SIM->PINSEL |= SIM_PINSEL_FTM1CLKPS(0);     //选择外部时钟输入引脚 A5
////            }
////            
////            else if(FTM1_COUNT_PIN == PTE0)
////            {
////                Pin_Pull_State(PTE, PTE0, Pull_Up);
////                SIM->PINSEL |= SIM_PINSEL_FTM1CLKPS(1);     //选择外部时钟输入引脚 E0
////            }
////            
////            else if(FTM1_COUNT_PIN == PTE7)
////            {
////                Pin_Pull_State(PTE, PTE7, Pull_Up);
////                SIM->PINSEL |= SIM_PINSEL_FTM1CLKPS(2);     //选择外部时钟输入引脚 E7
////            }
////        }break;
////        
////        case FTM_2:
////        {
////            SIM->SCGC |= SIM_SCGC_FTM2_MASK;                //开启FTM外设时钟
////            SIM->PINSEL &= ~SIM_PINSEL_FTM2CLKPS_MASK;      //清除外部时钟引脚选择
////            FTM2->CNTIN = 0;
////            if(FTM2_COUNT_PIN == PTA5)
////            {
////                Pin_Pull_State(PTA, PTA5, Pull_Up);
////                SIM->PINSEL |= SIM_PINSEL_FTM2CLKPS(0);     //选择外部时钟输入引脚 A5
////            }
////            
////            else if(FTM2_COUNT_PIN == PTE0)
////            {
////                Pin_Pull_State(PTE, PTE0, Pull_Up);
////                SIM->PINSEL |= SIM_PINSEL_FTM2CLKPS(1);     //选择外部时钟输入引脚 E0
////            }
////            
////            else if(FTM2_COUNT_PIN == PTE7)
////            {
////                Pin_Pull_State(PTE, PTE7, Pull_Up);
////                SIM->PINSEL |= SIM_PINSEL_FTM2CLKPS(2);     //选择外部时钟输入引脚 E7
////            }
////        }break;
////    }
//    switch(ftmn)
//    {
//        case FTM_0:
//        {
//            SIM->SCGC |= SIM_SCGC_FTM0_MASK;                //开启FTM外设时钟
//            SIM->PINSEL &= ~SIM_PINSEL_FTM0CLKPS_MASK;      //清除外部时钟引脚选择
//            if(FTM0_COUNT_PIN == PTA5)
//            {
//                Pin_Pull_State(PTA, PTA5, Pull_Up);
//                SIM->PINSEL |= SIM_PINSEL_FTM0CLKPS(0);     //选择外部时钟输入引脚 A5
//            }
//            
//            else if(FTM0_COUNT_PIN == PTE0)
//            {
//                Pin_Pull_State(PTE, PTE0, Pull_Up);
//                SIM->PINSEL |= SIM_PINSEL_FTM0CLKPS(1);     //选择外部时钟输入引脚 E0
//            }
//            
//            else if(FTM0_COUNT_PIN == PTE7)
//            {
//                Pin_Pull_State(PTE, PTE7, Pull_Up);
//                SIM->PINSEL |= SIM_PINSEL_FTM0CLKPS(2);     //选择外部时钟输入引脚 E7
//            }
//        }break;
//        
//        case FTM_1:
//        {
//            SIM->SCGC |= SIM_SCGC_FTM1_MASK;                //开启FTM外设时钟
//            SIM->PINSEL &= ~SIM_PINSEL_FTM1CLKPS_MASK;      //清除外部时钟引脚选择
//            if(FTM1_COUNT_PIN == PTA5)
//            {
//                Pin_Pull_State(PTA, PTA5, Pull_Up);
//                SIM->PINSEL |= SIM_PINSEL_FTM1CLKPS(0);     //选择外部时钟输入引脚 A5
//            }
//            
//            else if(FTM1_COUNT_PIN == PTE0)
//            {
//                Pin_Pull_State(PTE, PTE0, Pull_Up);
//                SIM->PINSEL |= SIM_PINSEL_FTM1CLKPS(1);     //选择外部时钟输入引脚 E0
//            }
//            
//            else if(FTM1_COUNT_PIN == PTE7)
//            {
//                Pin_Pull_State(PTE, PTE7, Pull_Up);
//                SIM->PINSEL |= SIM_PINSEL_FTM1CLKPS(2);     //选择外部时钟输入引脚 E7
//            }
//        }break;
//        
//        case FTM_2:
//        {
//            SIM->SCGC |= SIM_SCGC_FTM2_MASK;                //开启FTM外设时钟
//            SIM->PINSEL &= ~SIM_PINSEL_FTM2CLKPS_MASK;      //清除外部时钟引脚选择
//            FTM2->CNTIN = 0;
//            if(FTM2_COUNT_PIN == PTA5)
//            {
//                Pin_Pull_State(PTA, PTA5, Pull_Up);
//                SIM->PINSEL |= SIM_PINSEL_FTM2CLKPS(0);     //选择外部时钟输入引脚 A5
//            }
//            
//            else if(FTM2_COUNT_PIN == PTE0)
//            {
//                Pin_Pull_State(PTE, PTE0, Pull_Up);
//                SIM->PINSEL |= SIM_PINSEL_FTM2CLKPS(1);     //选择外部时钟输入引脚 E0
//            }
//            
//            else if(FTM2_COUNT_PIN == PTE7)
//            {
//                Pin_Pull_State(PTE, PTE7, Pull_Up);
//                SIM->PINSEL |= SIM_PINSEL_FTM2CLKPS(2);     //选择外部时钟输入引脚 E7
//            }
//        }break;
//    }
//}

//////-------------------------------------------------------------------------------------------------------------------
//////  @brief      外部计数初始化  获取计数值、用于编码器测速，无法识别方向只能计数，建议使用带方向输出的编码器
//////  @param      ftmn            选择模块
//////  @return     void
//////  @since      v2.0
//////  Sample usage:               
//////-------------------------------------------------------------------------------------------------------------------
//void ftm_count_init(FTMn ftmn)
//{
//    FTM_Count_Mux(ftmn);                                    //引脚复用 开启上拉 开启对应外设时钟
//    
//    FTMX[ftmn]->SC |= FTM_SC_PS(0);	                        //分频系数	
//    FTMX[ftmn]->SC |= FTM_SC_CLKS(3);                       //选择外部时钟作为FTM输入时钟
//                
//    FTMX[ftmn]->CNT = 0;                                    //加载初始化值
//}

//////-------------------------------------------------------------------------------------------------------------------
//////  @brief      获取计数值      用于编码器测速，无法识别方向只能计数，建议使用带方向输出的编码器
//////  @param      ftmn            选择模块
//////  @return     uint16_t          返回计数值
//////  @since      v2.0
//////  Sample usage:               
//////-------------------------------------------------------------------------------------------------------------------
//uint16_t ftm_count_get(FTMn ftmn)
//{
//    return FTMX[ftmn]->CNT ;
//}

//////-------------------------------------------------------------------------------------------------------------------
//////  @brief      清除计数值      用于编码器测速，无法识别方向只能计数，建议使用带方向输出的编码器
//////  @param      ftmn            选择模块
//////  @since      v2.0
//////  Sample usage:               
//////-------------------------------------------------------------------------------------------------------------------
//void ftm_count_clean(FTMn ftmn)
//{
//    FTMX[ftmn]->CNT = 0;
//}

