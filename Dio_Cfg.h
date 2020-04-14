#ifndef DIO_CFG_H_
#define DIO_CFG_H_



/*
 * Module's Configurations Version
 * */

#define DIO_CFG_SW_MAJOR_RELEASE_VERSION   (1U)
#define DIO_CFG_SW_MINOR_RELEASE_VERSION   (0U)
#define DIO_CFG_SW_PATCH_RELEASE_VERSION   (0U)

/*
 * AUTOSAR Version
 * */

#define DIO_CFG_AR_MAJOR_RELEASE_VERSION   (4U)
#define DIO_CFG_AR_MINOR_RELEASE_VERSION   (3U)
#define DIO_CFG_AR_PATCH_RELEASE_VERSION   (1U)





/************************************************************************************
 *                Pre-Compile Module Configurations                                 *
 ************************************************************************************/


/*To turn on/off the development errors*/
#define DIO_DEV_ERROR_DETECT              STD_ON

/*To define the maximum number of configured channels*/
#define DIO_MAXIMUM_NUMBER_OF_CONFIGURED_CHANNELS     (2U)

/*To define the maximum number of ports configured for the hardware target*/
#define DIO_MAXIMUM_NUMBER_OF_CONFIGURED_PORTS        (2U)

/*To turn on/off the VersionInfo API*/
#define DIO_VERSION_INFO_API              STD_ON

/*To turn on/off the FlipChannel API*/
#define DIO_FLIP_CHANNEL_API              STD_ON






#endif /* DIO_CFG_H_ */
