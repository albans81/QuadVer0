/**
  ******************************************************************************
  * @file    TIM_PWM_Output/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    19-September-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4_discovery.h"
#include "stm32f4_discovery_lis302dl.h"
#include "main.h"

/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup TIM_PWM_Output
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MEMS_PASSCONDITION              15
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
TIM_OCInitTypeDef  TIM_OCInitStructure;
LIS302DL_InitTypeDef  LIS302DL_InitStruct;
LIS302DL_FilterConfigTypeDef LIS302DL_FilterStruct;
uint16_t CCR1_Val = 200;// esempio 333;
uint16_t CCR2_Val = 200;//esempio 249;
uint16_t CCR3_Val = 200;//esempio 166;
uint16_t CCR4_Val = 200;//esempio 83;
uint16_t PrescalerValue = 0;
uint8_t Counter  = 0xff;
uint8_t Buffer[6];
uint32_t TimingDelay;


/* Private function prototypes -----------------------------------------------*/
void TIM_Config(void);
static void TIM4_Config(void);
void Accelerometer_MEMS_Test(void);
void Delay(__IO uint32_t nTime);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f4xx.c file
  */
  
  /* SysTick end of count event each 10ms */
  RCC_ClocksTypeDef  RCC_Clocks;
  RCC_GetClocksFreq(&RCC_Clocks);
  SysTick_Config(RCC_Clocks.HCLK_Frequency / 100);

  /* Initialize LEDs and User_Button on STM32F4-Discovery --------------------*/
  STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_EXTI); 
  
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);
  
  /* -----------------------------------------------------------------------
    TIM3 Configuration: generate 4 PWM signals with 4 different duty cycles.
    
    In this example TIM3 input clock (TIM3CLK) is set to 2 * APB1 clock (PCLK1), 
    since APB1 prescaler is different from 1.   
      TIM3CLK = 2 * PCLK1  
      PCLK1 = HCLK / 4 
      => TIM3CLK = HCLK / 2 = SystemCoreClock /2
          
    To get TIM3 counter clock at 28 MHz, the prescaler is computed as follows:
       Prescaler = (TIM3CLK / TIM3 counter clock) - 1
       Prescaler = ((SystemCoreClock /2) /28 MHz) - 1
                                              
    To get TIM3 output clock at 30 KHz, the period (ARR)) is computed as follows:
       ARR = (TIM3 counter clock / TIM3 output clock) - 1
           = 665
                  
    TIM3 Channel1 duty cycle = (TIM3_CCR1/ TIM3_ARR)* 100 = 50%
    TIM3 Channel2 duty cycle = (TIM3_CCR2/ TIM3_ARR)* 100 = 37.5%
    TIM3 Channel3 duty cycle = (TIM3_CCR3/ TIM3_ARR)* 100 = 25%
    TIM3 Channel4 duty cycle = (TIM3_CCR4/ TIM3_ARR)* 100 = 12.5%

    Note: 
     SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f4xx.c file.
     Each time the core clock (HCLK) changes, user had to call SystemCoreClockUpdate()
     function to update SystemCoreClock variable value. Otherwise, any configuration
     based on this variable will be incorrect.    
  ----------------------------------------------------------------------- */  
  
  /* TIM Configuration */
  TIM_Config();
  
  /* Compute the prescaler value */
  PrescalerValue = (uint16_t) ((SystemCoreClock /2) / 28000000) - 1;

  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 2000; //665 per 42 Khz dell'esempio, 559 per avere 50Khz
  TIM_TimeBaseStructure.TIM_Prescaler = 840;//prescalerValue;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

  /* PWM1 Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM3, &TIM_OCInitStructure);

  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel2 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR2_Val;

  TIM_OC2Init(TIM3, &TIM_OCInitStructure);

  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel3 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR3_Val;

  TIM_OC3Init(TIM3, &TIM_OCInitStructure);

  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel4 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR4_Val;

  TIM_OC4Init(TIM3, &TIM_OCInitStructure);

  TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM3, ENABLE);

  /* TIM3 enable counter */
  TIM_Cmd(TIM3, ENABLE);
  
  /*Fine parte pwm per i motori*/
    
  /* Move discovery kit to detect negative and positive acceleration values 
      on X, Y and Z axis */
  Accelerometer_MEMS_Test();
  
  /* Configurazione TIM4 per lampeggio led*/
  TIM4_Config();
  
  /*MEMS */
  /* Disable all Timer4 channels */
    TIM_CCxCmd(TIM4, TIM_Channel_1, DISABLE);
    TIM_CCxCmd(TIM4, TIM_Channel_2, DISABLE);
    TIM_CCxCmd(TIM4, TIM_Channel_3, DISABLE);
    TIM_CCxCmd(TIM4, TIM_Channel_4, DISABLE);

    /* MEMS configuration */
    LIS302DL_InitStruct.Power_Mode = LIS302DL_LOWPOWERMODE_ACTIVE;
    LIS302DL_InitStruct.Output_DataRate = LIS302DL_DATARATE_400;
    LIS302DL_InitStruct.Axes_Enable = LIS302DL_XYZ_ENABLE;
    LIS302DL_InitStruct.Full_Scale = LIS302DL_FULLSCALE_2_3;
    LIS302DL_InitStruct.Self_Test = LIS302DL_SELFTEST_NORMAL;
    LIS302DL_Init(&LIS302DL_InitStruct);
    
    /* Required delay for the MEMS Accelerometre: Turn-on time = 3/Output data Rate 
    = 3/100 = 30ms */
    Delay(30);
    
    /* MEMS High Pass Filter configuration */
    LIS302DL_FilterStruct.HighPassFilter_Data_Selection = LIS302DL_FILTEREDDATASELECTION_OUTPUTREGISTER;
    LIS302DL_FilterStruct.HighPassFilter_CutOff_Frequency = LIS302DL_HIGHPASSFILTER_LEVEL_3;
    LIS302DL_FilterStruct.HighPassFilter_Interrupt = LIS302DL_HIGHPASSFILTERINTERRUPT_1_2;
    LIS302DL_FilterConfig(&LIS302DL_FilterStruct);
    
    LIS302DL_Read(Buffer, LIS302DL_OUT_X_ADDR, 6);
    //X_Offset = Buffer[0];
    //Y_Offset = Buffer[2];
    //Z_Offset = Buffer[4];    

  /* qui faccio partire l'interrupt per il controllo dei dati */
  Counter = 0;
  
  while (1)
  {}
}

/**
  * @brief  Configure the TIM3 Ouput Channels.
  * @param  None
  * @retval None
  */
void TIM_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* TIM3 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

  /* GPIOC and GPIOB clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOB, ENABLE);
  
  /* GPIOC Configuration: TIM3 CH1 (PC6) and TIM3 CH2 (PC7) */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOC, &GPIO_InitStructure); 
  
  /* GPIOB Configuration:  TIM3 CH3 (PB0) and TIM3 CH4 (PB1) */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOB, &GPIO_InitStructure); 

  /* Connect TIM3 pins to AF2 */  
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3); 
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_TIM3);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_TIM3); 
}


/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 10 ms.
  * @retval Attento che questo delay è bloccante, non chiamarlo in interrupt!!
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;
  while(TimingDelay != 0);
}

/**
  * @brief  This function handles the test program fail.
  * @param  None
  * @retval None
  */
void Fail_Handler(void)
{  
  while(1)
  {
    /* Toggle Red LED */
    STM_EVAL_LEDToggle(LED5);
    Delay(5);
  }
}


/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;    
  }
}

/**
  * @brief  Configures the TIM Peripheral.
  * @param  None
  * @retval None
  */
static void TIM4_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  
  /* --------------------------- System Clocks Configuration -----------------*/
  /* TIM4 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  
  /* GPIOD clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  /*-------------------------- GPIO Configuration ----------------------------*/
  /* GPIOD Configuration: Pins 12, 13, 14 and 15 in output push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  /* Connect TIM4 pins to AF2 */  
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4); 
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4); 
  
    /* -----------------------------------------------------------------------
    TIM4 Configuration: Output Compare Timing Mode:
    
    In this example TIM4 input clock (TIM4CLK) is set to 2 * APB1 clock (PCLK1), 
    since APB1 prescaler is different from 1 (APB1 Prescaler = 4, see system_stm32f4xx.c file).
      TIM4CLK = 2 * PCLK1  
      PCLK1 = HCLK / 4 
      => TIM4CLK = 2*(HCLK / 4) = HCLK/2 = SystemCoreClock/2
         
    To get TIM4 counter clock at 2 KHz, the prescaler is computed as follows:
       Prescaler = (TIM4CLK / TIM1 counter clock) - 1
       Prescaler = (168 MHz/(2 * 2 KHz)) - 1 = 41999
                                        
    To get TIM4 output clock at 1 Hz, the period (ARR)) is computed as follows:
       ARR = (TIM4 counter clock / TIM4 output clock) - 1
           = 1999
                    
    TIM4 Channel1 duty cycle = (TIM4_CCR1/ TIM4_ARR)* 100 = 50%
    TIM4 Channel2 duty cycle = (TIM4_CCR2/ TIM4_ARR)* 100 = 50%
    TIM4 Channel3 duty cycle = (TIM4_CCR3/ TIM4_ARR)* 100 = 50%
    TIM4 Channel4 duty cycle = (TIM4_CCR4/ TIM4_ARR)* 100 = 50%
    
    ==> TIM4_CCRx = TIM4_ARR/2 = 1000  (where x = 1, 2, 3 and 4).
  
    Note: 
     SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f4xx.c file.
     Each time the core clock (HCLK) changes, user had to call SystemCoreClockUpdate()
     function to update SystemCoreClock variable value. Otherwise, any configuration
     based on this variable will be incorrect.    
  ----------------------------------------------------------------------- */ 
  
  
  /* Compute the prescaler value */
  PrescalerValue = (uint16_t) ((SystemCoreClock /2) / 2000) - 1;
  
  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = TIM_ARR;
  TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
  
  /* Enable TIM4 Preload register on ARR */
  TIM_ARRPreloadConfig(TIM4, ENABLE);
  
  /* TIM PWM1 Mode configuration: Channel */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = TIM_CCR;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  
  /* Output Compare PWM1 Mode configuration: Channel1 */
  TIM_OC1Init(TIM4, &TIM_OCInitStructure);
  TIM_CCxCmd(TIM4, TIM_Channel_1, DISABLE);
  
  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
  
  /* Output Compare PWM1 Mode configuration: Channel2 */
  TIM_OC2Init(TIM4, &TIM_OCInitStructure);
  TIM_CCxCmd(TIM4, TIM_Channel_2, DISABLE);
  
  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
    
  /* Output Compare PWM1 Mode configuration: Channel3 */
  TIM_OC3Init(TIM4, &TIM_OCInitStructure);
  TIM_CCxCmd(TIM4, TIM_Channel_3, DISABLE);
  
  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
  
  /* Output Compare PWM1 Mode configuration: Channel4 */
  TIM_OC4Init(TIM4, &TIM_OCInitStructure);
  TIM_CCxCmd(TIM4, TIM_Channel_4, DISABLE);
  
  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
  
  /* TIM4 enable counter */
  TIM_Cmd(TIM4, ENABLE);
}

/**
  * @brief Test MEMS Hardware
  *   The main objectif of this test is to check the hardware connection of the 
  *   MEMS peripheral.
  * @param None
  * @retval None
  */
void Accelerometer_MEMS_Test(void)
{
  uint8_t temp, memsteststatus = 0x00;
  uint8_t xdata, ydata = 0;
  
  /* MEMS configuration ------------------------------------------------------*/
  /* Set configuration of LIS302DL*/
  LIS302DL_InitStruct.Power_Mode = LIS302DL_LOWPOWERMODE_ACTIVE;
  LIS302DL_InitStruct.Output_DataRate = LIS302DL_DATARATE_100;
  LIS302DL_InitStruct.Axes_Enable = LIS302DL_X_ENABLE | LIS302DL_Y_ENABLE;
  LIS302DL_InitStruct.Full_Scale = LIS302DL_FULLSCALE_2_3;
  LIS302DL_InitStruct.Self_Test = LIS302DL_SELFTEST_M;
  LIS302DL_Init(&LIS302DL_InitStruct);
  
  /* Set configuration of Internal High Pass Filter of LIS302DL*/
  LIS302DL_FilterStruct.HighPassFilter_Data_Selection = LIS302DL_FILTEREDDATASELECTION_OUTPUTREGISTER;
  LIS302DL_FilterStruct.HighPassFilter_CutOff_Frequency = LIS302DL_HIGHPASSFILTER_LEVEL_1;
  LIS302DL_FilterStruct.HighPassFilter_Interrupt = LIS302DL_HIGHPASSFILTERINTERRUPT_1_2;
  LIS302DL_FilterConfig(&LIS302DL_FilterStruct);
  
  /* Required delay for the MEMS Accelerometre: Turn-on time = 3/Output data Rate 
                                                             = 3/100 = 30ms */
  Delay(30);
  
  /* Read WHO_AM_I register */
  LIS302DL_Read(&temp, LIS302DL_WHO_AM_I_ADDR, 1);
  
  /* Check device identification register, this register should contains 
  the device identifier that for LIS302DL is set to 0x3B */
  if (temp != 0x3B)
  {
    Fail_Handler();
  }

  TimingDelay = 2000;
  /* Wait until detecting all MEMS direction or timeout */
  while((memsteststatus == 0x00)&&(TimingDelay != 0x00))
  {
    LIS302DL_Read(Buffer, LIS302DL_OUT_X_ADDR, 4);
    xdata = ABS((int8_t)(Buffer[0]));
    ydata = ABS((int8_t)(Buffer[2]));
    /* Check test PASS condition */   
    if ((xdata > MEMS_PASSCONDITION) || (ydata > MEMS_PASSCONDITION)) 
    {
      /* MEMS Test PASS */
      memsteststatus = 0x01;
    }
  }
  
  /* MEMS test status: PASS */ 
  if(memsteststatus != 0x00)
  {
    /* Turn Green LED ON: signaling MEMS Test PASS */
    STM_EVAL_LEDOn(LED4);
    
    /* Waiting User Button is pressed */
    while (STM_EVAL_PBGetState(BUTTON_USER) == Bit_RESET)
    {}
    
    /* Waiting User Button is Released */
    while (STM_EVAL_PBGetState(BUTTON_USER) == Bit_SET)
    {}
    
    /* Turn Green LED OFF: signaling the end of MEMS Test and switching to 
       the next Sub Test */
    STM_EVAL_LEDOff(LED4);
  }
  /* MEMS test status: Timeout occurs */
  else
  {
    Fail_Handler();
  }
}


/**
  * @brief  MEMS accelerometre management of the timeout situation.
  * @param  None.
  * @retval None.
  */
uint32_t LIS302DL_TIMEOUT_UserCallback(void)
{
    /* Timeout error occured for SPI TXE/RXNE flags waiting loops.*/
  Fail_Handler();    

  return 0;  
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  while (1)
  {}
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
