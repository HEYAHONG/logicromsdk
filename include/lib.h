/*
 * lib.h
 *
 */

#ifndef INCLUDE_LIB_H_
#define INCLUDE_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Library URC events
 */
enum {
	URC_FILE_DOWNLOAD_STATUS = 500,/**< File download status event @see wget_init() */
	URC_FOTA_STARTED,              /**< FOTA start event */
	URC_FOTA_FINISHED,             /**< FOTA file download finished */
	URC_FOTA_FAILED,               /**< FOTA failed */
	URC_DEV_REBOOT_REQUEST,        /**< System reboot requested (generated if reboot command is executed) */
};

/**
 * Debug Log levels
 */
enum loglevel_e {
	/* Library Debug levels */
	DBG_OFF = 0,                 /**< Default loglevel, equivalent to printf */
	DBG_INFO,                    /**< Log level info */
	DBG_VERBOSE,                 /**< Log level verbose for more information */

	/* User application Debug levels must start at DBG_USER_START */
	DBG_LIB_END = 24,
	DBG_USER_START = DBG_LIB_END,/**< Start of Application log levels */
};

#ifndef _DOXYGEN_
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#ifndef null
#define null ((void *)0)
#endif
#endif

/**
 * @brief Reboot reasons
 * 
 */
enum reboot_reason_e {
	RESET_REASON_REBOOT, /**< Reboot command or sys_reset() */
	RESET_REASON_NOSIM, /**< Reboot due to No SIM card */
	RESET_REASON_NETWORKFAIL, /**< Reboot due to network registration failure */
	RESET_REASON_DATAFAIL, /**< Reboot due to data connection failure */
	RESET_REASON_FOTA, /**< Reboot due to FOTA update */
	RESET_REASON_PARAMRESET, /**< Reboot due to parameter reset */
	RESET_REASON_SYSFORMAT, /**< Reboot due to system memory format */
};

/**
 * Unsolicited response code handler callback
 * @param urc_code			URC code @ref sysurc_e
 * @param urc_param			URC parameter
 */
typedef void (*urc_callback_f)(unsigned int urc_code, unsigned int urc_param);

/**
 * Reboot callback function called when reboot is issued by the system.
 * this callback can be used to confirm or deny reboot.
 * 
 * @param reason	[in] Reboot reason @ref reboot_reason_e
 * 
 * @return	True if reboot is allowed, false otherwise
 */
typedef int (*reboot_confirm_callback_f)(int reason);

/**
 * Initialize Logicrom OpenCPU SDK library
 * @param stdio			[in] STDIO port (e.g. /dev/ttyUSB0), can be NULL if STDIO is not required
 * @param handler		[in] Function pointer for handling unsolicited responses @ref urc_callback_f
 */
void logicrom_init(const char *stdio, urc_callback_f handler);

/**
 * Get device serial number
 * @return		Serial number of device. Buffer is statically allocated, do not free
 */
const char *system_getserial(void);

/**
 * Get SDK library version
 * @return		Library version string.
 */
const char *get_logicrom_version(void);

/**
 * Set system time-zone in +/-HH:MM format (e.g. +5:30)
 * @param tz	[in] Timezone value
 */
void system_settz(const char *tz);

/**
 * Get current time-zone
 * @param tz	[out] Buffer to store timezone
 * @param size	[in] Size of buffer
 */
void system_gettz(char *tz, int size);

/**
 * Set reboot confirm callback
 * @param callback	[in] Callback function pointer
 */
int system_set_reboot_callback(reboot_confirm_callback_f callback);

#ifdef SOC_RDA8955
/**
 * Set debug() out on RDA8955 debug trace port.
 * default is off
 * @param en	[in] true to enable, false to disable
 * @return 		0 on success, -ve for error
 */
int system_set_debug_trace(int en);
#endif

/**
 * Debug printf with debug level.
 * 
 * Can be used to print messages at specific loglevel\n
 * e.g.
 * 
 * 		debug(DBG_INFO, "Hello\n");
 * 
 * Message will print if loglevel is set to 1
 *
 * @param level		[in] Debug level
 * @param fmt		[in] String format
 * @return			Number of bytes printed
 */
int debug(int level, const char *fmt, ...);

/**
 * Format Filesystem
 * @param path		[in] Mount point of filesystem
 * @return			0 on success, -ve for error
 */
int formatfs(const char * path);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_LIB_H_ */
