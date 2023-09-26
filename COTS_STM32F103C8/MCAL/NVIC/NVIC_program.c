/****************************************************************/
/******* Author    : Tadros Maged Malak         *****************/
/******* Date      : 12 Sep 2023                *****************/
/******* File Name : NVIC_program.c             *****************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"

Std_ReturnType NVIC_EnableIRQ (IRQn_t IRQn)
{
   Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    
   if(IRQn < 32)
    {
        NVIC_ISER0 = (1 << IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (IRQn < 64)
    {
        NVIC_ISER1 = (1 << (IRQn - 32));
        Local_FunctionStatus = E_OK;
    }
    else if (IRQn < 96)
    {
        NVIC_ISER2 = (1 << (IRQn - 64));
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
}

Std_ReturnType NVIC_DisableIRQ (IRQn_t IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

   if(IRQn < 32)
    {
        NVIC_ICER0 = (1 << IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (IRQn < 64)
    {
        NVIC_ICER1 = (1 << (IRQn - 32));
        Local_FunctionStatus = E_OK;
    }
    else if (IRQn < 96)
    {
        NVIC_ICER2 = (1 << (IRQn - 64));
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
}


Std_ReturnType NVIC_SetPendingIRQ (IRQn_t IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

   if(IRQn < 32)
    {
        NVIC_ISPR0 = (1 << IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (IRQn < 64)
    {
        NVIC_ISPR1 = (1 << (IRQn - 32));
        Local_FunctionStatus = E_OK;
    }
    else if (IRQn < 96)
    {
        NVIC_ISPR2 = (1 << (IRQn - 64));
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
}

Std_ReturnType NVIC_GetPendingIRQ (IRQn_t IRQn, IRQn_t *IRQn_PendingFlag)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(IRQn_PendingFlag != NULL)
    {
        if(IRQn < 32)
        {
            if(NVIC_ISPR0 & ( 1 << IRQn ))
            {
                *IRQn_PendingFlag = 1;
                Local_FunctionStatus = E_OK;
            }
            else
            {
                *IRQn_PendingFlag = 0;
                Local_FunctionStatus = E_OK;
            }
        }

        if(IRQn < 64)
        {
            if(NVIC_ISPR1 & ( 1 << (IRQn-32) ))
            {
                *IRQn_PendingFlag = 1;
                Local_FunctionStatus = E_OK;
            }
            else
            {
                *IRQn_PendingFlag = 0;
                Local_FunctionStatus = E_OK;
            }
        }

        if(IRQn < 96)
        {
            if(NVIC_ISPR0 & ( 1 << (IRQn-64) ))
            {
                *IRQn_PendingFlag = 1;
                Local_FunctionStatus = E_OK;
            }
            else
            {
                *IRQn_PendingFlag = 0;
                Local_FunctionStatus = E_OK;
            }
        }
        
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return  Local_FunctionStatus;
}

Std_ReturnType NVIC_ClearPendingIRQ (IRQn_t IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if (IRQn < 32)
    {
        NVIC_ICPR0 = (1U << IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (IRQn < 64)
    {
        NVIC_ICPR1 = (1U << (IRQn - 32));
        Local_FunctionStatus = E_OK;
    }
    else if (IRQn < 96)
    {
        NVIC_ICPR2 = (1U << (IRQn - 64));
        Local_FunctionStatus = E_OK;
    }

    return Local_FunctionStatus;
}

Std_ReturnType NVIC_GetActive (IRQn_t IRQn)
{
    if(IRQn < 32)
    SET_BIT(NVIC_IABR0, IRQn);

    else if(IRQn < 64)
    SET_BIT(NVIC_IABR1, IRQn);

    else if(IRQn < 96)
    SET_BIT(NVIC_IABR2, IRQn);
}

Std_ReturnType NVIC_SetPriority (IRQn_t IRQn, u32 Priority)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    
        if(IRQn < Max_Interrupts && Priority < Max_Priority)
        {
            u32 Local_index = IRQn/4 ;
            NVIC_IPR_BASE_ADDRESS[Local_index] = (Priority << 4);
            Local_FunctionStatus = E_OK;
        }
    return Local_FunctionStatus;
}

Std_ReturnType NVIC_Set_Group_Sub  ()
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

            if(PriorityGrouping == _16GROUP_0SUB)
            {
                SCB_AIRCR = _16GROUP_0SUB;
                Local_FunctionStatus = E_OK;
            }
            else if(PriorityGrouping == _8GROUP_2SUB)
            {
                SCB_AIRCR = _8GROUP_2SUB;
                Local_FunctionStatus = E_OK;
            }
            else if(PriorityGrouping == _4GROUP_4SUB)
            {
                SCB_AIRCR = _4GROUP_4SUB;
                Local_FunctionStatus = E_OK;
            }
            else if(PriorityGrouping == _2GROUP_8SUB)
            {
                SCB_AIRCR = _2GROUP_8SUB;
                Local_FunctionStatus = E_OK;
            }
            else if(PriorityGrouping == _0GROUP_16SUB)
            {
                SCB_AIRCR = _0GROUP_16SUB;
                Local_FunctionStatus = E_OK;
            }
    return Local_FunctionStatus;
}
