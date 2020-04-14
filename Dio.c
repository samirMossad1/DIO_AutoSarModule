

/************************************************************************************
 *                                 Required Includes                                *
 ************************************************************************************/

/*Include the Development Error Tracer Module to report DET Errors*/
#include "Det.h"

/*Include The DIO Module Header File*/
#include "Dio.h"

/*Include The DIO Module Memory Map File*/
#include "Dio_MemMap.h"



/*************************************************************************************
 *                               Global Static Variables                             *
 *************************************************************************************/

/*Global flag which hold the current status of the DIO Module (initialized/not-initialized)*/
STATIC uint8 DIO_Status=DIO_MODULE_NOT_INITALIZED;


/*Global pointer which holds the address of the post build channels structure*/
STATIC DIO_ConfigChannel* DIO_ChannelListPtr=NULL_PTR;






/*************************************************************************************
 *                           Helper Functions Prototypes                             *
 *************************************************************************************/


/*Function which returns all the required PortInformation*/
STATIC void DIO_returnPortInformation(DIO_PortInformation*);







/*************************************************************************************
 *                           Functions Implementation                                *
 *************************************************************************************/




/********************************************************************************************************************************/


void Dio_init(DIO_ConfigType * DIO_ConfigPtr)
{


#if (DIO_DEV_ERROR_DETECT == STD_ON)

	boolean error=FALSE;


	if(NULL_PTR == DIO_ConfigPtr)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_INIT_SERVICE_ID,
				DIO_E_PARAM_POINTER);

		/*Change the state of error flag*/
		error=TRUE;
	}
	else
	{

	}

#endif



	if(FALSE == error)
	{
		DIO_Status = DIO_MODULE_INITALIZED;

		DIO_ChannelListPtr=DIO_ConfigPtr->DIO_ChannelsRef;
	}
	else
	{

	}




}

/********************************************************************************************************************/

void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{

	DIO_PortInformation PortInfo;


#if (DIO_DEV_ERROR_DETECT == STD_ON)

	boolean error=FALSE;


	if(DIO_MODULE_NOT_INITALIZED == DIO_Status)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_SERVICE_ID,
				DIO_E_UNINIT_MODULE);

		/*Change the state of error flag*/
		error=TRUE;

	}
	else
	{

	}

	if(DIO_MAXIMUM_NUMBER_OF_CONFIGURED_CHANNELS <= ChannelId)
	{

		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_SERVICE_ID,
				DIO_E_PARAM_INVALID_CHANNEL_ID);

		/*Change the state of error flag*/
		error=TRUE;
	}
	else
	{

	}

#endif


	if(FALSE == error)
	{

		PortInfo.Id=DIO_ChannelListPtr[ChannelId].DIO_PortId;

		DIO_returnPortInformation(&PortInfo);


		if(STD_HIGH == Level)
		{


			SET_BIT((*(PortInfo.DataOutRegisterAdd)),(DIO_ChannelListPtr[ChannelId].DIO_ChannelNum));

		}
		else if (STD_LOW == Level)
		{

			CLEAR_BIT((*(PortInfo.DataOutRegisterAdd)),(DIO_ChannelListPtr[ChannelId].DIO_ChannelNum));

		}
		else
		{

		}


	}
	else
	{

	}



}

/********************************************************************************************************************************/



Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
	boolean output=STD_LOW;
	DIO_PortInformation PortInfo;

#if (DIO_DEV_ERROR_DETECT == STD_ON)

	boolean error=FALSE;


	if(DIO_MODULE_NOT_INITALIZED == DIO_Status)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_SERVICE_ID,
				DIO_E_UNINIT_MODULE);

		/*Change the state of error flag*/
		error=TRUE;    }
	else
	{

	}

	if(DIO_MAXIMUM_NUMBER_OF_CONFIGURED_CHANNELS <= ChannelId)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_SERVICE_ID,
				DIO_E_PARAM_INVALID_CHANNEL_ID);

		/*Change the state of error flag*/
		error=TRUE;    }
	else
	{

	}

#endif




	if(FALSE == error)
	{


		PortInfo.Id=DIO_ChannelListPtr[ChannelId].DIO_PortId;

		DIO_returnPortInformation(&PortInfo);


		if(BIT_IS_SET( (*(PortInfo.DataInRegisterAdd)) ,(DIO_ChannelListPtr[ChannelId].DIO_ChannelNum) ) )
		{
			output=STD_HIGH;
		}
		else
		{
			output=STD_LOW;
		}


		return output;


	}
	else
	{

	}

	return STD_LOW;


}

/********************************************************************************************************************************/




#if(DIO_FLIP_CHANNEL_API == STD_ON)
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId )
{

	boolean output=STD_LOW;
	DIO_PortInformation PortInfo;


#if (DIO_DEV_ERROR_DETECT == STD_ON)

	boolean error=FALSE;



	if(DIO_MODULE_NOT_INITALIZED == DIO_Status)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_FLIP_CHANNEL_SERVICE_ID,
				DIO_E_UNINIT_MODULE);

		/*Change the state of error flag*/
		error=TRUE;    }
	else
	{

	}

	if(DIO_MAXIMUM_NUMBER_OF_CONFIGURED_CHANNELS < ChannelId)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_FLIP_CHANNEL_SERVICE_ID,
				DIO_E_PARAM_INVALID_CHANNEL_ID);

		/*Change the state of error flag*/
		error=TRUE;
	}
	else
	{

	}

#endif



	if(FALSE == error)
	{

		PortInfo.Id=DIO_ChannelListPtr[ChannelId].DIO_PortId;

		DIO_returnPortInformation(&PortInfo);


		if(BIT_IS_SET( (*(PortInfo.DataOutRegisterAdd)) ,(DIO_ChannelListPtr[ChannelId].DIO_ChannelNum) ) )
		{

			CLEAR_BIT( (*(PortInfo.DataOutRegisterAdd)) ,(DIO_ChannelListPtr[ChannelId].DIO_ChannelNum) );
			output=STD_LOW;

		}
		else
		{

			SET_BIT( (*(PortInfo.DataOutRegisterAdd)) ,(DIO_ChannelListPtr[ChannelId].DIO_ChannelNum) );
			output=STD_HIGH;
		}



	}
	else
	{


	}

	return output;

}
#endif


/********************************************************************************************************************************/



Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId)
{
	DIO_PortInformation PortInfo;
	Dio_PortLevelType levelReturn=STD_LOW;

#if (DIO_DEV_ERROR_DETECT == STD_ON)

	boolean error=FALSE;


	if(DIO_MODULE_NOT_INITALIZED == DIO_Status)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_READ_PORT_SERVICE_ID,
				DIO_E_UNINIT_MODULE);

		/*Change the state of error flag*/
		error=TRUE;
	}
	else
	{

	}

	if(DIO_MAXIMUM_NUMBER_OF_CONFIGURED_PORTS < PortId)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_READ_PORT_SERVICE_ID,
				DIO_E_PARAM_INVALID_PORT_ID);

		/*Change the state of error flag*/
		error=TRUE;
	}
	else
	{

	}

#endif

	if(FALSE == error)
	{

		PortInfo.Id=PortId;

		DIO_returnPortInformation(&PortInfo);


		levelReturn=((*(PortInfo.DataInRegisterAdd))&(PortInfo.RegisterMask));


	}
	else
	{


	}


	return levelReturn;

}


/********************************************************************************************************************************/


void Dio_WritePort( Dio_PortType PortId , Dio_PortLevelType Level)
{

	DIO_PortInformation PortInfo;

#if (DIO_DEV_ERROR_DETECT == STD_ON)

	boolean error=FALSE;


	if(DIO_MODULE_NOT_INITALIZED == DIO_Status)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_WRITE_PORT_SERVICE_ID,
				DIO_E_UNINIT_MODULE);

		/*Change the state of error flag*/
		error=TRUE;
	}
	else
	{

	}

	if(DIO_MAXIMUM_NUMBER_OF_CONFIGURED_PORTS <= PortId)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_WRITE_PORT_SERVICE_ID,
				DIO_E_PARAM_INVALID_PORT_ID);

		/*Change the state of error flag*/
		error=TRUE;
	}
	else
	{

	}

#endif

	if(FALSE == error)
	{


		PortInfo.Id=PortId;

		DIO_returnPortInformation(&PortInfo);


		(*((uint8 *)(PortInfo.DataOutRegisterAdd))) = ( (Level) & (PortInfo.RegisterMask) );



	}
	else
	{

	}




}


/********************************************************************************************************************************/



Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr)
{


	DIO_PortInformation PortInfo;
	Dio_PortLevelType OutputValue=STD_LOW;

#if (DIO_DEV_ERROR_DETECT == STD_ON)

	boolean error=FALSE;


	if(NULL_PTR == ChannelGroupIdPtr)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_GROUP_SERVICE_ID,
				DIO_E_PARAM_POINTER);

		/*Change the state of error flag*/
		error=TRUE;
	}
	else
	{

	}

#endif


	if(FALSE == error)
	{

		PortInfo.Id=ChannelGroupIdPtr->port_id;

		DIO_returnPortInformation(&PortInfo);

		OutputValue=((*(PortInfo.DataInRegisterAdd))&(PortInfo.RegisterMask));

		OutputValue&=(ChannelGroupIdPtr->mask);

		OutputValue= OutputValue >> (ChannelGroupIdPtr->offset);

	}
	else
	{

	}

	return OutputValue;



}


/********************************************************************************************************************************/


void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr , Dio_PortLevelType Level )
{

	DIO_PortInformation PortInfo;
	Dio_PortLevelType PortValue;


#if (DIO_DEV_ERROR_DETECT == STD_ON)

	boolean error=FALSE;


	if(NULL_PTR == ChannelGroupIdPtr)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_GROUP_SERVICE_ID,
				DIO_E_PARAM_POINTER);

		/*Change the state of error flag*/
		error=TRUE;
	}
	else
	{

	}

#endif


	if(FALSE == error)
	{

		PortInfo.Id=ChannelGroupIdPtr->port_id;

		DIO_returnPortInformation(&PortInfo);

		PortValue=((*(PortInfo.DataOutRegisterAdd))&(PortInfo.RegisterMask));

		PortValue&=(~(ChannelGroupIdPtr->mask));


		PortValue|=( (Level<<ChannelGroupIdPtr->offset) & ( (ChannelGroupIdPtr->mask)) );

		(*(PortInfo.DataOutRegisterAdd))=PortValue;

	}
	else
	{


	}



}



/********************************************************************************************************************************/


#if(DIO_VERSION_INFO_API==STD_ON)
void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo)
{

#if (DIO_DEV_ERROR_DETECT == STD_ON)

	boolean error=FALSE;

	if(NULL_PTR != VersionInfo)
	{
		/*Report the Error through the Development Error Tracer Module*/
		Det_ReportError(DIO_MODULE_ID,
				DIO_INSTANCE_ID,
				DIO_GET_VERSION_INFO_SERVICE_ID,
				DIO_E_PARAM_POINTER);

		/*Change the state of error flag*/
		error=TRUE;
	}
	else
	{

	}

#endif



	if(FALSE == error)
	{

		VersionInfo->vendorID=          (uint16)DIO_VENDOR_ID;
		VersionInfo->moduleID=          (uint16)DIO_MODULE_ID;
		VersionInfo->sw_major_version=  (uint8)DIO_SW_MAJOR_RELEASE_VERSION;
		VersionInfo->sw_minor_version=  (uint8)DIO_SW_MINOR_RELEASE_VERSION;
		VersionInfo->sw_patch_version=  (uint8)DIO_SW_PATCH_RELEASE_VERSION;

	}
	else
	{


	}


}

#endif


/********************************************************************************************************************************/




/************************************************************************************
 *                             Helper Functions                                     *
 ************************************************************************************/

/********************************************************************************************************************************/

void DIO_returnPortInformation(DIO_PortInformation* PortInfo)
{


	switch(PortInfo->Id)
	{

	case 0 :
		PortInfo->DataOutRegisterAdd=&DIO_PORT_A_DATA_OUT_REGISTER;
		PortInfo->DataInRegisterAdd=&DIO_PORT_A_DATA_IN_REGISTER;
		PortInfo->RegisterMask=DIO_PORT_A_DATA_REGISTER_MASK;
		break;

	case 1 :
		PortInfo->DataOutRegisterAdd=&DIO_PORT_B_DATA_OUT_REGISTER;
		PortInfo->DataInRegisterAdd=&DIO_PORT_B_DATA_IN_REGISTER;
		PortInfo->RegisterMask=DIO_PORT_B_DATA_REGISTER_MASK;
		break;

	case 2 :
		PortInfo->DataOutRegisterAdd=&DIO_PORT_C_DATA_OUT_REGISTER;
		PortInfo->DataInRegisterAdd=&DIO_PORT_C_DATA_IN_REGISTER;
		PortInfo->RegisterMask=DIO_PORT_C_DATA_REGISTER_MASK;
		break;

	case 3 :
		PortInfo->DataOutRegisterAdd=&DIO_PORT_D_DATA_OUT_REGISTER;
		PortInfo->DataInRegisterAdd=&DIO_PORT_D_DATA_IN_REGISTER;
		PortInfo->RegisterMask=DIO_PORT_D_DATA_REGISTER_MASK;
		break;

	default:
		PortInfo->DataOutRegisterAdd=&DIO_PORT_B_DATA_OUT_REGISTER;
		PortInfo->DataInRegisterAdd=&DIO_PORT_B_DATA_IN_REGISTER;
		PortInfo->RegisterMask=DIO_PORT_B_DATA_REGISTER_MASK;
		break;
	}


}

/********************************************************************************************************************************/
