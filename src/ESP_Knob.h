/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdint.h>
#include "base/iot_knob.h"

class ESP_Knob {
public:

    /**
     * @brief Construct a new esp knob object
     *
     * @param gpio_encoder_a Encoder Pin A
     * @param gpio_encoder_b Encoder Pin B
     */
    ESP_Knob(int gpio_encoder_a, int gpio_encoder_b);

    /**
     * @brief Construct a new esp knob object
     *
     * @param gpio_encoder_a Encoder Pin A
     * @param gpio_encoder_b Encoder Pin B
     * @param default_direction 0:positive increase   1:negative increase
     */
    ESP_Knob(int gpio_encoder_a, int gpio_encoder_b, int default_direction);

    /**
     * @brief Destroy the esp knob object
     *
     */
    ~ESP_Knob(void);

    /**
     * @brief create a esp knob
     *
     */
    void begin(void);

    /**
     * @brief Delete a esp knob
     *
     */
    void del(void);

    /**
     * @brief Register the knob left callback function
     *
     * @param cb Callback function
     * @param usr_data user data
     */
    void registerLeftCb(knob_cb_t cb, void *usr_data);

    /**
     * @brief Register the knob right callback function
     *
     * @param cb Callback function
     * @param usr_data user data
     */
    void registerRightCb(knob_cb_t cb, void *usr_data);

    /**
     * @brief Register the knob count reaches maximum limit callback function
     *
     * @param cb Callback function
     * @param usr_data user data
     */
    void registerHighLimitCb(knob_cb_t cb, void *usr_data);

    /**
     * @brief Register the knob count reaches minimum limit callback function
     *
     * @param cb Callback function
     * @param usr_data user data
     */
    void registerLowLimitCb(knob_cb_t cb, void *usr_data);

    /**
     * @brief Register the knob count reaches zero callback function
     *
     * @param cb Callback function
     * @param usr_data user data
     */
    void registerZeroCb(knob_cb_t cb, void *usr_data);

    /**
     * @brief Register the knob event callback function
     *
     * @param event Knob event
     * @param cb Callback function
     * @param usr_data user data
     */
    void registerEvent(knob_event_t event, knob_cb_t cb, void *usr_data);

    /**
     * @brief Unregister the knob left callback function
     *
     */
    void unregisterLeftCb(void);

    /**
     * @brief Unregister the knob right callback function
     *
     */
    void unregisterRightCb(void);

    /**
     * @brief Unregister the knob count reaches maximum limit callback function
     *
     */
    void unregisterHighLimitCb(void);

    /**
     * @brief Unregister the knob count reaches minimum limit callback function
     *
     */
    void unregisterLowLimitCb(void);

    /**
     * @brief Unregister the knob count reaches zero callback function
     *
     */
    void unregisterZeroCb(void);

    /**
     * @brief Unregister the knob event callback function
     *
     * @param event Knob event
     */
    void unregisterEvent(knob_event_t event);

    /**
     * @brief Get esp knob event
     *
     * @return knob_event_t Knob event
     */
    knob_event_t getEvent(void);

    /**
     * @brief Get esp knob count value
     *
     */
    int getCountValue(void);

    /**
     * @brief Clear esp knob cout value to zero
     *
     */
    void clearCountValue(void);

private:
    knob_handle_t knob_handle; /**< Knob handle */

    int default_direction;          /*!< 0:positive increase   1:negative increase */
    int gpio_encoder_a;             /*!< Encoder Pin A */
    int gpio_encoder_b;             /*!< Encoder Pin B */
};
