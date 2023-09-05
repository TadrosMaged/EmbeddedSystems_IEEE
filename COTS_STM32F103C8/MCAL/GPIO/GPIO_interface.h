#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


Std_ReturnType MCAL_GPIO_SetPinMode(u8 CopyPortId, u8 CopyPinId, u8 CopyPinMode); 

Std_ReturnType MCAL_GPIO_DeterminePinValue(u8 CopyPortId, u8 CopyPinId, u8 CopyPinMode);

Std_ReturnType MCAL_GPIO_GetPinMode(u8 CopyPortId, u8 CopyPinId, u8 *CopyPinReturnMode);

/****************************GPIO_PORTID****************************/

#define GPIO_PORTA   0
#define GPIO_PORTB   1
#define GPIO_PORTC   2

/****************************GPIO_PINID****************************/

#define  GPIO_PIN0         0
#define  GPIO_PIN1         1
#define  GPIO_PIN2         2
#define  GPIO_PIN3         3
#define  GPIO_PIN4         4
#define  GPIO_PIN5         5
#define  GPIO_PIN6         6
#define  GPIO_PIN7         7
#define  GPIO_PIN8         8
#define  GPIO_PIN9         9
#define  GPIO_PIN10        10
#define  GPIO_PIN11        11
#define  GPIO_PIN12        12
#define  GPIO_PIN13        13
#define  GPIO_PIN14        14
#define  GPIO_PIN15        15

/****************************GPIO_PINMODE****************************/

#define GPIO_PINMODE_IP_ANALOG          0b0000
#define GPIO_PINMODE_IP_FLOATING        0b0100
#define GPIO_PINMODE_IP_PULL_UpDown     0b1000



#define GPIO_PINMODE_OP_PUSH_PULL_10MHZ                  0b0001
#define GPIO_PINMODE_OP_OPEN_DRAIN_10MHZ                 0b0101
#define GPIO_PINMODE_OP_AF_PUSH_PULL_10MHZ               0b1001
#define GPIO_PINMODE_OP_AF_OPEN_DRAIN_10MHZ              0b1101

#define GPIO_PINMODE_OP_PUSH_PULL_2MHZ                   0b0010
#define GPIO_PINMODE_OP_OPEN_DRAIN_2MHZ                  0b0110
#define GPIO_PINMODE_OP_AF_PUSH_PULL_2MHZ                0b1010
#define GPIO_PINMODE_OP_AF_OPEN_DRAIN_2MHZ               0b1110

#define GPIO_PINMODE_OP_PUSH_PULL_50MHZ                  0b0011 
#define GPIO_PINMODE_OP_OPEN_DRAIN_50MHZ                 0b0111 
#define GPIO_PINMODE_OP_AF_PUSH_PULL_50MHZ               0b1011 
#define GPIO_PINMODE_OP_AF_OPEN_DRAIN_50MHZ              0b1111


/****************************GPIO_PinMode****************************/
#define PinMode_High  0
#define PinMode_LOW  1

#endif