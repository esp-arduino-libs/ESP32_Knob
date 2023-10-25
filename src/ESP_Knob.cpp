/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include "esp_log.h"
#include "esp_err.h"
#include "ESP_Knob.h"

static const char *TAG = "ESP_Knob";

ESP_Knob::ESP_Knob(uint8_t gpio_encoder_a, uint8_t gpio_encoder_b):
    knob_handle(NULL),
    default_direction(0),
    gpio_encoder_a(gpio_encoder_a),
    gpio_encoder_b(gpio_encoder_b)
{
}

ESP_Knob::ESP_Knob(uint8_t gpio_encoder_a, uint8_t gpio_encoder_b, uint8_t default_direction):
    knob_handle(NULL),
    default_direction(default_direction),
    gpio_encoder_a(gpio_encoder_a),
    gpio_encoder_b(gpio_encoder_b)
{
}

ESP_Knob::~ESP_Knob()
{
    if (knob_handle != NULL) {
        iot_knob_delete(knob_handle);
    }
}

void ESP_Knob::begin()
{
    const knob_config_t knob_cfg = {
        .default_direction = default_direction,
        .gpio_encoder_a = gpio_encoder_a,
        .gpio_encoder_b = gpio_encoder_b,
    };
    knob_handle = iot_knob_create(&knob_cfg);
    if (knob_handle == NULL) {
        ESP_LOGE(TAG, "Error create knob");
    }
}

void ESP_Knob::del()
{
    if (knob_handle != NULL) {
        iot_knob_delete(knob_handle);
        knob_handle = NULL;
    }
}

void ESP_Knob::register_cb(knob_event_t event, knob_cb_t cb, void *usr_data)
{
    esp_err_t err = iot_knob_register_cb(knob_handle, event, cb, usr_data);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error register knob callback");
    }
}

void ESP_Knob::unregister_cb(knob_event_t event)
{
    esp_err_t err = iot_knob_unregister_cb(knob_handle, event);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error unregister knob callback");
    }
}

knob_event_t ESP_Knob::get_event()
{
    return iot_knob_get_event(knob_handle);
}

int ESP_Knob::get_count_value()
{
    return iot_knob_get_count_value(knob_handle);
}

void ESP_Knob::clear_count_value()
{
    iot_knob_clear_count_value(knob_handle);
}
