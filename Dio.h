

#ifndef DIO_H_
#define DIO_H_


/*
 * DIO MODULE Vendor ID
 * */
#define DIO_VENDOR_ID    (100U)

/*DIO Module ID*/
#define DIO_MODULE_ID    (120U)

/*DIO Instance ID*/
#define DIO_INSTANCE_ID  (1U)


/*
 * Module Version
 */

#define DIO_SW_MAJOR_RELEASE_VERSION       (1U)
#define DIO_SW_MINOR_RELEASE_VERSION       (0U)
#define DIO_SW_PATCH_RELEASE_VERSION       (0U)


/*
 * AUTOSAR Version
 */

#define DIO_AR_MAJOR_RELEASE_VERSION       (4U)
#define DIO_AR_MINOR_RELEASE_VERSION       (3U)
#define DIO_AR_PATCH_RELEASE_VERSION       (1U)



/*Include the general standard types*/
#include "Std_types.h"



/*
 * AUTOSAR version checking between DIO Module and Standard Types file
 * */

#if ((DIO_AR_MAJOR_RELEASE_VERSION!=STD_TYPES_AR_MAJOR_RELEASE_VERSION)\
        ||(DIO_AR_MINOR_RELEASE_VERSION!=STD_TYPES_AR_MINOR_RELEASE_VERSION)\
        ||(DIO_AR_PATCH_RELEASE_VERSION!=STD_TYPES_AR_PATCH_RELEASE_VERSION))

#error "The autosar versions of the DIO module and the Std_types file are not compatible"
#endif


/*Include the pre-compile configurations of the DIO Module*/
#include "DIO_Cfg.h"


/*
 * AUTOSAR version checking between DIO Module Configurations and Standard Types file
 * */
#if ((DIO_CFG_AR_MAJOR_RELEASE_VERSION!=STD_TYPES_AR_MAJOR_RELEASE_VERSION)\
        ||(DIO_CFG_AR_MINOR_RELEASE_VERSION!=STD_TYPES_AR_MINOR_RELEASE_VERSION)\
        ||(DIO_CFG_AR_PATCH_RELEASE_VERSION!=STD_TYPES_AR_PATCH_RELEASE_VERSION))

#error "The autosar versions of the Socket Adaptor configurations and the Std_types files are not compatible"
#endif


/*
 * Software version checking between DIO Module and its Configurations
 * */

#if ((DIO_SW_MAJOR_RELEASE_VERSION!=DIO_CFG_SW_MAJOR_RELEASE_VERSION)\
        ||(DIO_SW_MINOR_RELEASE_VERSION!=DIO_CFG_SW_MINOR_RELEASE_VERSION)\
        ||(DIO_SW_PATCH_RELEASE_VERSION!=DIO_CFG_SW_PATCH_RELEASE_VERSION))

#error "The software versions of the Socket Adaptor module and configurations file are not compatible"
#endif


/*Include The DIO Module Hardware Registers*/
#include "Dio_Regs.h"


/*Include The DIO Module Types*/
#include "DIO_Types.h"


/************************************************************************************
 *                                 General Macros                                   *
 ************************************************************************************/

/*
 * DIO Module Status
 */

#define DIO_MODULE_INITALIZED           TRUE
#define DIO_MODULE_NOT_INITALIZED       FALSE



/*************************************************************************************
 *                           Service Id Macros                                       *
 *************************************************************************************/


/*Service ID for DIO ReadChannel Service*/
#define DIO_READ_CHANNEL_SERVICE_ID              0x00

/*Service ID for DIO WriteChannel Service*/
#define DIO_WRITE_CHANNEL_SERVICE_ID             0x01

/*Service ID for DIO FlipChannel Service*/
#define DIO_FLIP_CHANNEL_SERVICE_ID              0x11

/*Service ID for DIO ReadChannelGroup Service*/
#define DIO_READ_CHANNEL_GROUP_SERVICE_ID        0x04

/*Service ID for DIO WriteChannelGroupService*/
#define DIO_WRITE_CHANNEL_GROUP_SERVICE_ID       0x05

/*Service ID for DIO ReadPort Service*/
#define DIO_READ_PORT_SERVICE_ID                 0x02

/*Service ID for DIO WritePort Service*/
#define DIO_WRITE_PORT_SERVICE_ID                0x03

/*Service ID for DIO GetVersionInfo Service*/
#define DIO_GET_VERSION_INFO_SERVICE_ID          0x12

/*Service ID for DIO Init Service (Not Autosar)*/
#define DIO_INIT_SERVICE_ID                      0xFF



/*************************************************************************************
 *                      Development Errors IDs                                       *
 *************************************************************************************/


/*DET code to report invalid channel requested id*/
#define DIO_E_PARAM_INVALID_CHANNEL_ID      0x0A

/*DET code to report invalid port requested id*/
#define DIO_E_PARAM_INVALID_PORT_ID         0x14

/*DET code to report invalid group requested id*/
#define DIO_E_PARAM_INVALID_GROUP           0x1F

/*DET code to report a null pointer*/
#define DIO_E_PARAM_POINTER                 0x20

/*DET code to report a not initialized DIO Module (not stated in the sws)*/
#define DIO_E_UNINIT_MODULE                 0XFF



/*************************************************************************************
 *                     DIO Module Functions Prototypes                               *
 *************************************************************************************/


/*
 * Service Name: Dio_init
 *
 * Service ID: 0xFF
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Reentrant
 *
 * Parameters (in): - DIO_ConfigPtr
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value: None
 *
 * Description: Initialize the DIO Module
 *
 **/
void Dio_init(DIO_ConfigType * DIO_ConfigPtr);



/*
 * Service Name: Dio_ReadChannel
 *
 * Service ID: 0x00
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Reentrant
 *
 * Parameters (in): - ChannelId
 *                          ID of DIO channel
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value:    - Dio_LevelType
 *                      STD_HIGH The physical level of the corresponding Pin is STD_HIGH
 *                      STD_LOW The physical level of the corresponding Pin is  STD_LOW
 *
 * Description: Returns the value of the specified DIO channel.
 *
 **/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType);


/*
 * Service Name: Dio_WriteChannel
 *
 * Service ID: 0x01
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Reentrant
 *
 * Parameters (in): - ChannelId
 *                        ID of DIO channel
 *                  - Level
 *                        Value to be written
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value: None
 *
 * Description: Service to set a level of a channel.
 *
 **/
void Dio_WriteChannel( Dio_ChannelType, Dio_LevelType );



/*Check if the FlipChannel API enabled/disabled*/
#if (DIO_FLIP_CHANNEL_API == STD_ON)
/*
 * Service Name: Dio_FlipChannel
 *
 * Service ID: 0x11
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Reentrant
 *
 * Parameters (in): - ChannelId
 *                        ID of DIO channel
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value:    - Dio_LevelType
 *                          STD_HIGH: The physical level of the corresponding Pin is STD_HIGH.
 *                          STD_LOW: The physical level of the corresponding Pin is STD_LOW.
 *
 * Description: Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip
 *
 **/
Dio_LevelType Dio_FlipChannel( Dio_ChannelType );
#endif


/*
 * Service Name: SoAd_MainFunction
 *
 * Service ID: 0x19
 *
 * Sync/Async: N/A
 *
 * Reentrancy: N/A
 *
 * Parameters (in): None
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value: None
 *
 * Description: Schedules the Socket Adaptor. (Entry point for scheduling)
 *
 **/
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType*);


/*
 * Service Name: SoAd_MainFunction
 *
 * Service ID: 0x19
 *
 * Sync/Async: N/A
 *
 * Reentrancy: N/A
 *
 * Parameters (in): None
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value: None
 *
 * Description: Schedules the Socket Adaptor. (Entry point for scheduling)
 *
 **/
void Dio_WriteChannelGroup( const Dio_ChannelGroupType* , Dio_PortLevelType );


/*
 * Service Name: Dio_ReadPort
 *
 * Service ID: 0x02
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Reentrant
 *
 * Parameters (in): - PortId
 *                          ID of DIO Port
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value:    - Dio_PortLevelType
 *                      Level of all channels of that port
 *
 * Description: Returns the level of all channels of that port..
 *
 **/
Dio_PortLevelType Dio_ReadPort( Dio_PortType);



/*
 * Service Name: Dio_WritePort
 *
 * Service ID: 0x03
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Reentrant
 *
 * Parameters (in):     - PortId
 *                          ID of DIO Port
 *                      - Level
 *                          Value to be written
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value: None
 *
 * Description: Service to set a value of the port.
 *
 **/
void Dio_WritePort( Dio_PortType , Dio_PortLevelType);




/*Check if the VersionInfo enabled/disabled*/
#if (DIO_VERSION_INFO_API == STD_ON)
/*
 * Service Name: DIO_GetVersionInfo
 *
 * Service ID:  0x12
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Reentrant
 *
 * Parameters (in): None
 *
 * Parameters (inout): None
 *
 * Parameters (out): - versioninfo
 *                       Pointer to where to store the version information of this module.
 *
 * Return Value: None
 *
 * Description: Returns the version information.
 *
 **/
void Dio_GetVersionInfo( Std_VersionInfoType* );
#endif




/*************************************************************************************
 *                                  Externed Variables                               *
 *************************************************************************************/


/*The Externed Post Build Configuration Structure*/
extern DIO_ConfigType DIO_configStruct;



#endif /* DIO_H_ */
