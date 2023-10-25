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
    ESP_Knob(uint8_t gpio_encoder_a, uint8_t gpio_encoder_b);

    /**
     * @brief Construct a new esp knob object
     *
     * @param gpio_encoder_a Encoder Pin A
     * @param gpio_encoder_b Encoder Pin B
     * @param default_direction 0:positive increase   1:negative increase
     */
    ESP_Knob(uint8_t gpio_encoder_a, uint8_t gpio_encoder_b, uint8_t default_direction);

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
     * @brief Register the knob event callback function
     *
     * @param event Knob event
     * @param cb Callback function
     * @param usr_data user data
     */
    void register_cb(knob_event_t event, knob_cb_t cb, void *usr_data);

    /**
     * @brief Unregister the knob event callback function
     *
     * @param event Knob event
     */
    void unregister_cb(knob_event_t event);

    /**
     * @brief Get esp knob event
     *
     * @return knob_event_t Knob event
     */
    knob_event_t get_event(void);

    /**
     * @brief Get esp knob count value
     *
     */
    int get_count_value(void);

    /**
     * @brief Clear esp knob cout value to zero
     *
     */
    void clear_count_value(void);

private:
    knob_handle_t knob_handle; /**< Knob handle */

    uint8_t default_direction;          /*!< 0:positive increase   1:negative increase */
    uint8_t gpio_encoder_a;             /*!< Encoder Pin A */
    uint8_t gpio_encoder_b;             /*!< Encoder Pin B */
};
