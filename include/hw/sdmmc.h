/*
 * sdmmc.h
 *
 */

#ifndef INCLUDE_HW_SDMMC_H_
#define INCLUDE_HW_SDMMC_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Card Type
 * 
 */
enum cardtype_e {
    CARD_TYPE_EMMC, /**< Card is EMMC, (5.0 supported) */
    CARD_TYPE_SD,   /**< Card is SD or MMC type */
};

enum data_mode_e {
    DATA_MODE_4BIT, /**< 4-bit data mode */
    DATA_MODE_1BIT, /**< 1-bit data mode */
};

/**
 * @brief SDMMC Configuration
 * 
 */
struct sdmmc_cfg_t {
    uint8_t card_type; /**< Card type @ref cardtype_e */
    uint8_t data_mode; /**< Data mode @ref data_mode_e */
    uint32_t reserved; /**< Reserved, keep as 0 */
    uint32_t reserved1; /**< Reserved, keep as 0 */
};

/**
 * @brief Mount an SD card
 * 
 * To support SD card hotplug, Use GPIO for SD card detection
 * Unmount SD card when card is removed and mount again when
 * card is inserted.
 * 
 * On success, SD card is mounted on VFS at path: "/sd"
 * 
 * @note Only supported on 4G Modules
 * 
 * @param cfg SDMMC Configuration @ref sdmmc_cfg_t
 * @return 0 on success, negative on error 
 */
int sdmmc_mount(struct sdmmc_cfg_t *cfg);

/**
 * @brief Unmount SD card
 * 
 * @note Only supported on 4G Modules
 * 
 * @return 0 on success, negative on error
 */
int sdmmc_unmount(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_HW_SDMMC_H_ */
