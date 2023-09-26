/****************************************************************/
/******* Author    : Tadros Maged Malak         *****************/
/******* Date      : 12 Sep 2023                *****************/
/******* File Name : NVIC_private.h             *****************/
/****************************************************************/


#ifndef NVIC_PRIVATE
#define NVIC_PRIVATE

typedef  u8                        IRQn_t;

#define  NVIC_BASE_ADDRESS         (*((volatile u32 *) 0xE000E100))

#define  NVIC_ISER0                (*((volatile u32 *) 0xE000E100))
#define  NVIC_ISER1                (*((volatile u32 *) 0xE000E104))
#define  NVIC_ISER2                (*((volatile u32 *) 0xE000E108))
            
#define  NVIC_ICER0                (*((volatile u32 *) 0xE000E180))
#define  NVIC_ICER1                (*((volatile u32 *) 0xE000E184))
#define  NVIC_ICER2                (*((volatile u32 *) 0xE000E188))
            
#define  NVIC_ISPR0                (*((volatile u32 *) 0xE000E200))
#define  NVIC_ISPR1                (*((volatile u32 *) 0xE000E204))
#define  NVIC_ISPR2                (*((volatile u32 *) 0xE000E208))
            
#define  NVIC_ICPR0                (*((volatile u32 *) 0xE000E280))
#define  NVIC_ICPR1                (*((volatile u32 *) 0xE000E284))
#define  NVIC_ICPR2                (*((volatile u32 *) 0xE000E288))
            
#define  NVIC_IABR0                (*((volatile u32 *) 0xE000E300))
#define  NVIC_IABR1                (*((volatile u32 *) 0xE000E304))
#define  NVIC_IABR2                (*((volatile u32 *) 0xE000E308))

#define NVIC_IPR_BASE_ADDRESS      ((volatile u32 *)    0xE000E400)

#define SCB_BASE_ADDRESS           (*((volatile u32 *) 0xE000E008))
#define SCB_AIRCR                  (*((volatile u32 *) 0xE000E014))

/**********************Priority Groups and Sub**********************/

#define _16GROUP_0SUB              0x05FA0300
#define _8GROUP_2SUB               0x05FA0400
#define _4GROUP_4SUB               0x05FA0500
#define _2GROUP_8SUB               0x05FA0600
#define _0GROUP_16SUB              0x05FA0700




#endif