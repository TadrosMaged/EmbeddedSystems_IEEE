#ifndef RCC_CONFIG
#define RCC_CONFIG

/**
*@brief
*Choose system clock
*your options : RCC_HSI
                RCC_HSE
                RCC_PLL
*/

#define RCC_SYSCLK    RCC_HSE

/**
*@brief
*Choose external clock source
*your options : RCC_CR_HSE_RC
                RCC_CR_HSE_CRYSTAL
*/

#define RCC_CR_HSE_SOURCE    RCC_CR_HSE_RC

/**
*@brief
*Choose PLL clock source
*your options : RCC_CFGR_PLLSRC_HSI
                RCC_CFGR_PLLSRC_PREDIV1
*/

#define RCC_CFGR_PLLSRC     PLLSRC_HSI


#endif