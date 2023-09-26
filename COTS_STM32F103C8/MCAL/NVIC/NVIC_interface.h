/****************************************************************/
/******* Author    : Tadros Maged Malak         *****************/
/******* Date      : 12 Sep 2023                *****************/
/******* File Name : NVIC_interface.h           *****************/
/****************************************************************/
#ifndef NVIC_INTERFACE
#define NVIC_INTERFACE

#include "STD_TYPES.h"

Std_ReturnType NVIC_EnableIRQ            (IRQn_t IRQn);

Std_ReturnType NVIC_DisableIRQ           (IRQn_t IRQn);

Std_ReturnType NVIC_SetPendingIRQ        (IRQn_t IRQn, IRQn_t *IRQn_PendingFlag);

Std_ReturnType NVIC_GetPendingIRQ        (IRQn_t IRQn);

Std_ReturnType NVIC_ClearPendingIRQ      (IRQn_t IRQn);

Std_ReturnType NVIC_GetActive            (IRQn_t IRQn);

Std_ReturnType NVIC_SetPriority          (IRQn_t IRQn, u32 Priority);

Std_ReturnType NVIC_Set_Group_Sub        (void);

Std_ReturnType NVIC_SetPriorityGrouping  (u32 priority_grouping);

Std_ReturnType NVIC_GetPriority          (IRQn_t IRQn);

Std_ReturnType NVIC_SystemReset          (void);
#endif