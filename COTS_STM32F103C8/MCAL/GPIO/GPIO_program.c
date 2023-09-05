#ifndef GPIO_PROGRAM_C
#define GPIO_PROGRAM_C

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

Std_ReturnType MCAL_GPIO_SetPinMode(u8 CopyPortId, u8 CopyPinId, u8 CopyPinMode){

    Std_ReturnType Local_Function_Status = E_NOT_OK; 
    switch(CopyPortId)
    {
        case GPIO_PORTA:
        if(CopyPinId < 8)
        {
            GPIOA_CRL &= ~((0b1111))<<CopyPinId;
            GPIOA_CRL |= ((CopyPinMode)) << (CopyPinId*4) ;
            Local_Function_Status = E_OK;
        }
        else if(CopyPinId < 16)
        {
            GPIOA_CRH &= ~((0b1111))<<CopyPinId;
            GPIOA_CRH |= ((CopyPinMode)) << (CopyPinId*4) ;
            Local_Function_Status = E_OK;
        }
        else
          Local_Function_Status= E_NOT_OK;
        break;

        case GPIO_PORTB:
        if(CopyPinId < 8)
        {
            GPIOB_CRL &= ~((0b1111))<<CopyPinId;
            GPIOB_CRL |= ((CopyPinMode)) << (CopyPinId*4) ;
            Local_Function_Status = E_OK;
        }
        else if(CopyPinId < 16)
        {
            GPIOB_CRH &= ~((0b1111))<<CopyPinId;
            GPIOB_CRH |= ((CopyPinMode)) << (CopyPinId*4) ;
            Local_Function_Status = E_OK;
        }
        else
          Local_Function_Status= E_NOT_OK;
        break;

        case GPIO_PORTC:
        if(CopyPinId < 8)
        {
            GPIOC_CRL &= ~((0b1111))<<CopyPinId;
            GPIOC_CRL |= ((CopyPinMode)) << (CopyPinId*4) ;
            Local_Function_Status = E_OK;
        }
        else if(CopyPinId < 16)
        {
            GPIOC_CRH &= ~((0b1111))<<CopyPinId;
            GPIOC_CRH |= ((CopyPinMode)) << (CopyPinId*4) ;
            Local_Function_Status = E_OK;
        }
        else
          Local_Function_Status= E_NOT_OK; 
        break;

        default: Local_Function_Status = E_NOT_OK;
    }
}


Std_ReturnType MCAL_GPIO_DeterminePinValue(u8 CopyPortId, u8 CopyPinId, u8 CopyPinMode)
{
    Std_ReturnType Local_Function_Status=E_NOT_OK;   

    switch(CopyPortId){
        case GPIO_PORTA:

            switch (CopyPinMode)
            {
            case PinMode_High:
                SET_BIT(GPIOA_ODR,CopyPinId);
                Local_Function_Status=E_OK;
            break;
            case PinMode_LOW:
                CLR_BIT(GPIOA_ODR,CopyPinId);
                Local_Function_Status=E_OK;
            break;
            }
            
        break;

        case GPIO_PORTB:

            switch (CopyPinMode)
            {
            case PinMode_High:
                SET_BIT(GPIOB_ODR,CopyPinId);
                Local_Function_Status=E_OK;
            break;
            case PinMode_LOW:
                CLR_BIT(GPIOB_ODR,CopyPinId);
                Local_Function_Status=E_OK;
            break;
            }
            
        break;

        case GPIO_PORTC:

            switch (CopyPinMode)
            {
            case PinMode_High:
                SET_BIT(GPIOC_ODR,CopyPinId);
                Local_Function_Status=E_OK;
            break;
            case PinMode_LOW:
                CLR_BIT(GPIOC_ODR,CopyPinId);
                Local_Function_Status=E_OK;
            break; 
            }
            
        break;
    default: Local_Function_Status=E_NOT_OK;
    }

    return Local_Function_Status;
}

Std_ReturnType MCAL_GPIO_GetPinMode(u8 CopyPortId, u8 CopyPinId, u8 *CopyPinReturnMode)
{
    Std_ReturnType Local_Function_Status = E_NOT_OK;

    if(CopyPinReturnMode!=NULL)
    {
        switch(CopyPortId)
        {
         case GPIO_PORTA : 
                *CopyPinReturnMode = GET_BIT(GPIOA_IDR,CopyPinId);
         break;

         case GPIO_PORTB : 
                *CopyPinReturnMode = GET_BIT(GPIOB_IDR,CopyPinId);
         break;

         case GPIO_PORTC : 
                *CopyPinReturnMode = GET_BIT(GPIOC_IDR,CopyPinId);
         break;

        default: Local_Function_Status=E_NOT_OK;
        }
    }
    else  Local_Function_Status=E_NOT_OK;

    return Local_Function_Status;
}


#endif