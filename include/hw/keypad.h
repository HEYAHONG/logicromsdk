/**
 * @file keypad.h
 * @author Ajay Bhargav (ajay.bhargav@waybyte.in)
 * @brief Keypad driver API
 * 
 * @copyright Copyright (c) 2025 Waybyte Solutions
 * 
 */
#ifndef __HW_KEYPAD_H__
#define __HW_KEYPAD_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum keyevent_e {
    KEYPAD_EVENT_PRESS = 1,
    KEYPAD_EVENT_RELEASE = 2,
};

/**
 * @brief Keypad callback function
 * 
 * @param id		[in] Key ID
 * @param event		[in] Event type @ref keyevent_e
 * @param ctx		[in] User context
 * 
 */
typedef void (*keypad_callback_f)(int id, int event, void *ctx);

/**
 * @brief Initialize keypad function
 * 
 * @param in_mask   [in] bitwise mask for KEYINx (col) pins, unused currently
 * @param out_mask  [in] bitwise mask for KEYOUTx (row) pins, unused currently
 * @return         0 on success, negative value on error
 */
int keypad_init(int in_mask, int out_mask);

/**
 * @brief Set keypad callback function
 * 
 * @param id		[in] Key ID
 * @param cb		[in] Callback function
 * @param mask		[in] Mask for event type @ref keyevent_e
 * @param ctx		[in] User context
 * @return			0 on success, negative value on error
 */
int keypad_set_cb(int id, keypad_callback_f cb, uint32_t mask, void *ctx);

/**
 * @brief Get keypad state
 * 
 * @param id		[in] Key ID
 * @return			true if key is pressed, false if key is released
 */
int keypad_get_state(int id);

/**
 * @brief Deinitialize keypad function
 * 
 * @return         0 on success, negative value on error
 */
int keypad_deinit(void);

#ifdef __cplusplus
}
#endif

#endif /* __HW_KEYPAD_H__ */
