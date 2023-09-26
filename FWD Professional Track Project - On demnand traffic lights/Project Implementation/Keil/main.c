#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"



  u8 YellowLED_Status=GPIO_LOW;
  void EXTI0_IRQHandler(void);


		
	int main()
	{
		MCAL_RCC_InitSysClock();
		MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
		MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPBEN);


		MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT_PUSH_PULL_2MHZ);
		MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT_PUSH_PULL_2MHZ);
		MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUT_PUSH_PULL_2MHZ);
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN0,GPIO_INPUT_PULL_UP_MOD);
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN1,GPIO_OUTPUT_PUSH_PULL_2MHZ);
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN2,GPIO_OUTPUT_PUSH_PULL_2MHZ);
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN3,GPIO_OUTPUT_PUSH_PULL_2MHZ);
		

		MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
		EXTI_vInit();
		EXTI_InitForGPIO(GPIO_PIN0, GPIO_PORTB);
		EXTI_SetTrigger( EXTI_LINE0 , EXTI_RISING_EDGE);
		EXTI_EnableLine(EXTI_LINE0);
		
		MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_OUTPUT_PUSH_PULL_2MHZ);  //test


		while(1)
		{
			
			
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
		  	MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_HIGH);
				MCAL_STK_SetDelay_ms(10000);
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_LOW);
				
				YellowLED_Status=GPIO_HIGH;
				for(u32 i=0;i<4;++i)
				{
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_HIGH);
				MCAL_STK_SetDelay_ms(1000);
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_LOW);
				MCAL_STK_SetDelay_ms(1000);
				}
				YellowLED_Status=GPIO_LOW;
				
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
		  	MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, GPIO_HIGH);
				MCAL_STK_SetDelay_ms(10000);
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, GPIO_LOW);
				
				for(u32 i=0;i<4;++i)
				{
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_HIGH);
				MCAL_STK_SetDelay_ms(1000);
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_LOW);
				MCAL_STK_SetDelay_ms(1000);
				}
				
				
			
		}
		
			
		return 0;
	}
	
	
	
	
	 void EXTI0_IRQHandler(void)
	{
		u8 ButtonValue;

		for(u32 i=0;i<50000;i++);
		MCAL_GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0, &ButtonValue);
		
		
		if(ButtonValue == GPIO_LOW)
		{
			u8 Pedestrian_RedLED_Value;

			MCAL_GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN1, &Pedestrian_RedLED_Value);
			
			if(Pedestrian_RedLED_Value == GPIO_HIGH)
			{
				
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_LOW);
				
				for(u32 i=0;i<4;i++)
				{
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_HIGH);
					for(u32 j=0;j<30000;j++);
					
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_LOW);
					for(u32 j=0;j<30000;j++);
				}
				
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
		  	MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_HIGH);
				for(u32 i=0;i<250000;i++);
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_LOW);
				
				for(u32 i=0;i<4;i++)
				{
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_HIGH);
					for(u32 j=0;j<30000;j++);
					
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_LOW);
					for(u32 j=0;j<30000;j++);
					
				}
				
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
		  	MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, GPIO_HIGH);
				for(u32 i=0;i<250000;i++);
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, GPIO_LOW);
				
				EXTI_CLR_Pending(EXTI_LINE0);
				MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
				
				
				
			}  //if(Cars_RedLED_Value == GPIO_HIGH)
		
			
			else if(YellowLED_Status == GPIO_HIGH)
			{
				
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_LOW);
				
				for(u32 i=0;i<4;i++)
				{
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_HIGH);
					for(u32 j=0;j<30000;j++);
					
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_LOW);
					for(u32 j=0;j<30000;j++);
					
				}
				
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
		  	MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_HIGH);
				for(u32 i=0;i<250000;i++);
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_LOW);
				
				for(u32 i=0;i<4;i++)
				{
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_HIGH);
					for(u32 j=0;j<30000;j++);
					
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_LOW);
					for(u32 j=0;j<30000;j++);
					
				}
				
				EXTI_CLR_Pending(EXTI_LINE0);
				MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
				
			}  //if((YellowLED_Status == GPIO_HIGH)
			
			else
			{
				EXTI_CLR_Pending(EXTI_LINE0);
				MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
			}
		
		
		}  //if(ButtonValue == GPIO_LOW)
		else
		{
			EXTI_CLR_Pending(EXTI_LINE0);
			MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
		}
		
	} //handler
