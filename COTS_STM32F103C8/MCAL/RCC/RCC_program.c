/****************************************************************/
/******* Author    : Tadros Maged Malak         *****************/
/******* Date      : 20 Aug 2023                *****************/
/******* File Name : RCC_program.c              *****************/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


Std_ReturnType Mcal_Rcc_InitSysClk(void)
{

    Std_ReturnType Local_Function_Status=E_NOT_OK;  

#if   RCC_SYSCLK == RCC_HSI

        SET_BIT(RCC_CR,RCC_CR_HSION);
        while (!GET_BIT(RCC_CR,RCC_CR_HSIRDY));
        RCC_CFGR=0x00000000;
        
        Local_Function_Status=E_OK;

#elif RCC_SYSCLK == RCC_HSE

        #if  RCC_CR_HSE_SOURCE == RCC_CR_HSE_RC
            SET_BIT(RCC_CR,RCC_CR_HSEBYP);

        #elif  RCC_CR_HSE_SOURCE == RCC_CR_HSE_CRYSTAL
            CLR_BIT(RCC_CR,RCC_CR_HSEBYP);
         
        #else 
            #error "Undefined selection for external clock source"
        #endif

        SET_BIT(RCC_CR,RCC_CR_HSEON);
        while (!GET_BIT(RCC_CR,RCC_CR_HSERDY));
        RCC_CFGR=0x00000001;

        Local_Function_Status=E_OK;

#elif RCC_SYSCLK == RCC_PLL
        
        /*choose pll multiply value*/
        //switch(RCC_CFGR_PLLMUL)

        /*choose pll source*/
        #if RCC_CFGR_PLLSRC == RCC_CFGR_PLLSRC_HSI
            CLR_BIT(RCC_CFGR,RCC_CFGR_PLLSRC)

        #elif RCC_CFGR_PLLSRC == RCC_CFGR_PLLSRC_PREDIV1
            SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC)
            

        #endif



        SET_BIT(RCC_CR,RCC_CR_PLLON);
        while(!GET_BIT(RCC_CR,RCC_CR_PLLRDY));
        RCC_CFGR=0x00000010;


        Local_Function_Status=E_OK;



#else 
        #error "Undefined selection for system clock"
        return Local_Function_Status;

#endif

}

Std_ReturnType Mcal_Rcc_EnablePeripheral( u8 PeripheralId, u8 BusId )
{
    Std_ReturnType Local_Function_Status=E_NOT_OK;

    switch (BusId)
    {
    case RCC_AHB: SET_BIT(RCC_AHBENR,PeripheralId); 
                  Local_Function_Status=E_OK;
        break;

    case RCC_APB1:  SET_BIT(RCC_APB1ENR,PeripheralId);
                    Local_Function_Status=E_OK;
        break;

    case RCC_APB2:  SET_BIT(RCC_APB2ENR,PeripheralId);
                    Local_Function_Status=E_OK;
        break;
    
    default:    Local_Function_Status=E_NOT_OK;
        break;
    }

    return Local_Function_Status;

}

Std_ReturnType Mcal_Rcc_DisablePeripheral( u8 PeripheralId, u8 BusId )
{
    Std_ReturnType Local_Function_Status=E_NOT_OK;

    switch (BusId)
    {
    case RCC_AHB: CLR_BIT(RCC_AHBENR,PeripheralId); 
                  Local_Function_Status=E_OK;
        break;

    case RCC_APB1:  CLR_BIT(RCC_APB1ENR,PeripheralId);
                    Local_Function_Status=E_OK;
        break;

    case RCC_APB2:  CLR_BIT(RCC_APB2ENR,PeripheralId);
                    Local_Function_Status=E_OK;
        break;
    
    default:    Local_Function_Status=E_NOT_OK;
        break;
    }

    return Local_Function_Status;

}