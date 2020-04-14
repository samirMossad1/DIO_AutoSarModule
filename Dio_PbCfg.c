
#include "Dio.h"



DIO_ConfigChannel DioModuleChannelsList[DIO_MAXIMUM_NUMBER_OF_CONFIGURED_CHANNELS]=
{
		{
				.DIO_ChannelNum=PIN_0,     /*PIN_0*/
				.DIO_PortId=PORT_A          /*PORT_A*/
		}
		,
		{
				.DIO_ChannelNum=PIN_1,   /*PIN_0*/
				.DIO_PortId=PORT_B        /*PORT_B*/

		}

};


DIO_ConfigType DIO_configStruct=
{
		.DIO_ChannelsRef=DioModuleChannelsList,
		.DIO_ChannelNum=DIO_MAXIMUM_NUMBER_OF_CONFIGURED_CHANNELS

};


