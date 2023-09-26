/****************************************************************/
/******* Author    : Tadros Maged Malak         *****************/
/******* Date      : 12 Sep 2023                *****************/
/******* File Name : NVIC_config.h              *****************/
/****************************************************************/

#define Max_Interrupts           81
#define Max_Priority             16


/**
 * Priority config
 * your options: _16GROUP_0SUB
                 _8GROUP_2SUB 
                 _4GROUP_4SUB 
                 _2GROUP_8SUB 
                 _0GROUP_16SUB
*/

#define PriorityGrouping    _8GROUP_2SUB