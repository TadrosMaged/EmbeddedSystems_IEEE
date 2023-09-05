#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define GPIO_PORTA_BASE_ADDRESS     0X40010800U
#define GPIO_PORTB_BASE_ADDRESS     0X40010C00U
#define GPIO_PORTC_BASE_ADDRESS     0X40011000U


/***********************GPIO_PORTA_REGISTERS_ADRESSES************************/

#define GPIOA_CRL        (*((volatile u32 *)  (GPIO_PORTA_BASE_ADDRESS+0x00)))
#define GPIOA_CRH        (*((volatile u32 *)  (GPIO_PORTA_BASE_ADDRESS+0x04)))
#define GPIOA_IDR        (*((volatile u32 *)  (GPIO_PORTA_BASE_ADDRESS+0x08)))
#define GPIOA_ODR        (*((volatile u32 *)  (GPIO_PORTA_BASE_ADDRESS+0x0C)))
#define GPIOA_BSRR       (*((volatile u32 *)  (GPIO_PORTA_BASE_ADDRESS+0x10)))
#define GPIOA_BRR        (*((volatile u32 *)  (GPIO_PORTA_BASE_ADDRESS+0x14)))
#define GPIOA_LCKR       (*((volatile u32 *)  (GPIO_PORTA_BASE_ADDRESS+0x18)))



/***********************GPIO_PORTB_REGISTERS_ADRESSES************************/

#define GPIOB_CRL        (*((volatile u32 *)  (GPIO_PORTB_BASE_ADDRESS+0x00)))
#define GPIOB_CRH        (*((volatile u32 *)  (GPIO_PORTB_BASE_ADDRESS+0x04)))
#define GPIOB_IDR        (*((volatile u32 *)  (GPIO_PORTB_BASE_ADDRESS+0x08)))
#define GPIOB_ODR        (*((volatile u32 *)  (GPIO_PORTB_BASE_ADDRESS+0x0C)))
#define GPIOB_BSRR       (*((volatile u32 *)  (GPIO_PORTB_BASE_ADDRESS+0x10)))
#define GPIOB_BRR        (*((volatile u32 *)  (GPIO_PORTB_BASE_ADDRESS+0x14)))
#define GPIOB_LCKR       (*((volatile u32 *)  (GPIO_PORTB_BASE_ADDRESS+0x18)))



/***********************GPIO_PORTC_REGISTERS_ADRESSES************************/

#define GPIOC_CRL        (*((volatile u32 *)  (GPIO_PORTC_BASE_ADDRESS+0x00)))
#define GPIOC_CRH        (*((volatile u32 *)  (GPIO_PORTC_BASE_ADDRESS+0x04)))
#define GPIOC_IDR        (*((volatile u32 *)  (GPIO_PORTC_BASE_ADDRESS+0x08)))
#define GPIOC_ODR        (*((volatile u32 *)  (GPIO_PORTC_BASE_ADDRESS+0x0C)))
#define GPIOC_BSRR       (*((volatile u32 *)  (GPIO_PORTC_BASE_ADDRESS+0x10)))
#define GPIOC_BRR        (*((volatile u32 *)  (GPIO_PORTC_BASE_ADDRESS+0x14)))
#define GPIOC_LCKR       (*((volatile u32 *)  (GPIO_PORTC_BASE_ADDRESS+0x18)))






#endif