
#ifndef DIO_REGS_H_
#define DIO_REGS_H_


#define AVR


#ifdef AVR
/************************************************************************************
 *                  Hardware Registers (AVR)                                        *
 ************************************************************************************/

/*The Data Register (Input/Output) Of Port_A*/
#define DIO_PORT_A_DATA_OUT_REGISTER             (*((volatile uint8 * )(0x003B)))

/*The Data Register (Input/Output) Of Port_B*/
#define DIO_PORT_B_DATA_OUT_REGISTER             (*((volatile uint8 * )(0x0038)))

/*The Data Register (Input/Output) Of Port_C*/
#define DIO_PORT_C_DATA_OUT_REGISTER             (*((volatile uint8 * )(0x0035)))

/*The Data Register (Input/Output) Of Port_D*/
#define DIO_PORT_D_DATA_OUT_REGISTER             (*((volatile uint8 * )(0x0032)))


/*The Data Register (Input/Output) Of Port_A*/
#define DIO_PORT_A_DATA_IN_REGISTER             (*((volatile uint8 * )(0x0039)))

/*The Data Register (Input/Output) Of Port_B*/
#define DIO_PORT_B_DATA_IN_REGISTER             (*((volatile uint8 * )(0x0036)))

/*The Data Register (Input/Output) Of Port_C*/
#define DIO_PORT_C_DATA_IN_REGISTER             (*((volatile uint8 * )(0x0033)))

/*The Data Register (Input/Output) Of Port_D*/
#define DIO_PORT_D_DATA_IN_REGISTER             (*((volatile uint8 * )(0x0030)))


/************************************************************************************
 *                               General Masks                                      *
 ************************************************************************************/

/*This mask is used to define the number of I/O Pins of PORT_A*/
#define DIO_PORT_A_DATA_REGISTER_MASK   (uint8)0XFF

/*This mask is used to define the number of I/O Pins of PORT_B*/
#define DIO_PORT_B_DATA_REGISTER_MASK   (uint8)0XFF

/*This mask is used to define the number of I/O Pins of PORT_C*/
#define DIO_PORT_C_DATA_REGISTER_MASK   (uint8)0XFF

/*This mask is used to define the number of I/O Pins of PORT_D*/
#define DIO_PORT_D_DATA_REGISTER_MASK   (uint8)0XFF



#endif








#endif /* DIO_REGS_H_ */
