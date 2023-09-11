#ifndef NVIC_PRIVATE
#define NVIC_PRIVATE

typedef struct{

    volatile u32 ISER[3];
    volatile u32 RESERVED_0[29];

    volatile u32 ICER[3];
    volatile u32 RESERVED_1[29];

    volatile u32 ISPR[3];
    volatile u32 RESERVED_2[29];

    volatile u32 ICPR[3];
    volatile U32 RESERVED_3[29];

    volatile u32 IABR[3];
    volatile u32 RESERVED_4[29];

    volatile u8 IPR[84];
    volatile u32 RESERVED_5[695];

    volatile u32 STIR;
    


}


#endif