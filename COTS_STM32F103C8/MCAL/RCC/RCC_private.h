#ifndef RCC_PRIVATE
#define RCC_PRIVATE


/*******************RCC_REGISTERS_ADDRESSES********************/

#define RCC_BASE_ADDRESS                 0x40021000
#define RCC_CR                     (*(volatile u32 *)0x40021000)
#define RCC_CFGR                   (*(volatile u32 *)0x40021004)
#define RCC_CIR                    (*(volatile u32 *)0x40021008)
#define RCC_APB2RSTR               (*(volatile u32 *)0x4002100C)
#define RCC_APB1RSTR               (*(volatile u32 *)0x40021010)
#define RCC_AHBENR                 (*(volatile u32 *)0x40021014)
#define RCC_APB2ENR                (*(volatile u32 *)0x40021018)
#define RCC_APB1ENR                (*(volatile u32 *)0x4002101C)
#define RCC_BDCR                   (*(volatile u32 *)0x40021020)



/************************RCC_CR_BITS***************************/

#define RCC_CR_HSION         0
#define RCC_CR_HSIRDY        1
#define RCC_CR_HSEON         16
#define RCC_CR_HSERDY        17
#define RCC_CR_HSEBYP        18
#define RCC_CR_PLLON         24
#define RCC_CR_PLLRDY        25


/***********************RCC_CFGR_BITS**************************/


#define RCC_CFGR_PLLSRC_HSI         16

#define RCC_CFGR_PLLXTPRE       17

#define RCC_AHBENR_DMA1EN       0
#define RCC_AHBENR_DMA2EN       1
#define RCC_AHBENR_SRAMEN       2

#define RCC_APB1_TIM2EN         0
#define RCC_APB1_TIM3EN         1
#define RCC_APB1_TIM4EN         2

#define RCC_APB2_AFIOEN         0
#define RCC_APB2_IOPAEN         2
#define RCC_APB2_IOPBEN         3


/******************SWITCH_CASE_ARGUMENTS*********************/

#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2

#endif