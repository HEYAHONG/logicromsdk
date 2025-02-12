/*
 * fota.h
 *
 */

#ifndef INCLUDE_FOTA_H_
#define INCLUDE_FOTA_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Add fota command to CLI
 * 
 * Usage:
 * fota=[url]
 * 
 * @return returns 0
 */
int fota_init(void);

/**
 * Start Firmware Update
 * @param in_url	[in] HTTP URL to download firmware
 * @return			0 on success, negative value on error
 */
int fota_start(const char *in_url);

/**
 * @brief Request to abort firmware update
 * 
 * @return return 0 on success, negative value on error
 */
int fota_abort(void);

/**
 * Get OTA status
 * @return			Return 1 if FOTA in progress, 0 otherwise
 */
int fota_in_progress(void);

/**
 * @brief Register with Logicrom FOTA server for automatic firmware
 * updates via Device management console. Automatic firmware update
 * is checked once a day on Waybyte server. This function also enable
 * core firmware update checks.
 * 
 * This function also add additional options in "fota" command
 * 
 * To check update on server\n
 * fota=check
 * 
 * To force download firmware\n
 * fota=download
 * 
 * To manually update firmware\n
 * fota=update
 *
 * @param code		Firmware code to identify application
 * @param ver		current firmware version
 * @return			return 0 on success, negative value on failure
 */
int logicrom_fota_register(const char *code, const char *ver);

/**
 * @brief Set fota check interval
 * 
 * @param hours interval value in hours
 * @return return 0 on success, negative value on error
 */
int fota_set_interval(int hours);

/**
 * @brief Get current fota check interval
 * 
 * @return return fota interval in hours
 */
int fota_get_interval(void);

/**
 * @defgroup APPFOTA FOTA Interface
 * 
 * @brief These functions are used to update application firmware
 * from external source. User can write their own update interface
 * and use these function to interface with low level firmware update.
 * 
 * @{
 */

/**
 * @brief Initialize application firmware update
 * 
 * @param handle [out] handle to use in subsequent calls
 * @return return 0 on success, negative value on error
 */
int appfota_init(int *handle);

/**
 * @brief Write firmware data to application firmware update
 * 
 * @param handle [in] handle returned by appfota_init()
 * @param buff [in] buffer containing firmware data
 * @param len [in] length of buffer
 * @return return 0 on success, negative value on error
 */
int appfota_write(int handle, const void *buff, size_t len);

/**
 * @brief Finish application firmware update, If the firmware binary
 * is valid, system will enter bootloader and update firmware. If the
 * firmware binary is invalid, an error will be returned.
 * 
 * @param handle [in] handle returned by appfota_init()
 * @return return negative value on error
 */
int appfota_finish(int handle);

/** @} */

#ifdef __cplusplus
}
#endif
#endif	/* INCLUDE_FOTA_H_ */

