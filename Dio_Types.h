
#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_


/*************************************************************************************
 *                              DIO Module TypeDefs                                  *
 *************************************************************************************/



/*Type Definition of Dio_ChannelType Which Maps To The ChannelId*/
typedef uint8 Dio_ChannelType;


/*Type Definition of Dio_PortType Which Maps To The PortId*/
typedef uint8 Dio_PortType;


/*Type Definition of Dio_LevelType Which Maps To The Levels Of A DIO Pin*/
typedef uint8 Dio_LevelType;


/*Type Definition of Dio_PortLevelType Which Maps To The Value Of All Port Pins*/
typedef uint8 Dio_PortLevelType;



/*************************************************************************************
 *                               DIO Module Enumerations                             *
 *************************************************************************************/



/*Enumeration to determine if the Id is a portId or channelId*/
typedef enum
{
	PORT_TRUE_CHANNEL_FALSE,        /*The Id is a PortId and not a ChannelId*/
	PORT_FALSE_CHANNEL_TRUE         /*The Id is a ChannelId and not a PortId*/

}DIO_Port_Or_Channel;



/*************************************************************************************
 *                               DIO Module Structures                               *
 *************************************************************************************/


/*Structure to hold all the required port information*/
typedef struct
{

#ifdef AVR
	volatile uint8*    DataOutRegisterAdd;            /*It holds the address of the data (output) register of the relative portId*/
	volatile uint8*    DataInRegisterAdd;             /*It holds the address of the data (input) register of the relative portId*/
#endif
	uint8               RegisterMask;      			 /*It hold the mask which defines the number of pins of the relative portId*/
	uint8               Id;                 		 /*It hold the channelId or PortId*/

}DIO_PortInformation;



/*Structure to hold the configurations of a DIO Channel*/
typedef struct
{
	Dio_PortType    DIO_PortId;             /*It holds the PortId of the relative channel*/
	Dio_ChannelType DIO_ChannelNum;         /*It hold the ChannelId*/

}DIO_ConfigChannel;



typedef struct
{

	Dio_PortType        port_id;            /*It holds the PortId of the relative channel*/
	uint8               offset;             /*It holds the offset of the first channel*/
	uint8               mask;               /*It holds the mask to clear all the channel group values*/

}Dio_ChannelGroupType;



/*Structure to hold all the configured Channels and their relative PortId*/
typedef struct
{

	DIO_ConfigChannel*   DIO_ChannelsRef;     	   /*Reference to the array which holds all the pre-configured channels*/
	Dio_ChannelType		DIO_ChannelNum;			   /*The maximum number of configured channels*/

}DIO_ConfigType;




#endif /* DIO_TYPES_H_ */
