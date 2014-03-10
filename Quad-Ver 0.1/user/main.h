/**
  ******************************************************************************
  * @file    main.h 
  ******************************************************************************
*/
extern uint16_t CCR1_Val;
extern uint16_t CCR2_Val;
extern uint16_t CCR3_Val;
extern uint16_t CCR4_Val;
extern uint32_t TimingDelay;
extern uint8_t Antirimbalzo;

/* Exported functions ------------------------------------------------------- */
void TimingDelay_Decrement(void);
void DelayBotton(__IO uint32_t nTime);