/*
 * iomux.h
 *
 */

#ifndef __HW_IOMUX_H__
#define __HW_IOMUX_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef PLATFORM_EC200U
/**
 * @brief Configure IOMUX for SPI port
 * @note Only applicable to EC200U modules
 * 
 * @param port			[in] SPI Port Number (@ref spiport_e)
 * @param select		[in] IOMUX pin selection
 * @return 0 on success, negative value on error
 */
int spi_hw_setiomux(int port, int select);


/**
 * @brief Configure the IOMUX for UART1. This function must
 * be called before using UART2.
 * 
 * Group 1: UART1_TXD: Pin 
 * 
 * @note only applicable to EC200U modules
 * 
 * @param select 0 to select group 1, 1 to select group 2
 * 
 * @return 0 on success, -1 on failure
 */
int uart1_setiomux(int select);

#endif

#ifdef __cplusplus
}
#endif

#endif // __HW_IOMUX_H__
