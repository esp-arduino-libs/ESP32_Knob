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

ESP_Knob::ESP_Knob(int gpio_encoder_a, int gpio_encoder_b):
    knob_handle(NULL),
    default_direction(0),
    gpio_encoder_a(gpio_encoder_a),
    gpio_encoder_b(gpio_encoder_b)
{
}

ESP_Knob::ESP_Knob(int gpio_encoder_a, int gpio_encoder_b, int default_direction):
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
        .default_direction = (uint8_t)default_direction,
        .gpio_encoder_a = (uint8_t)gpio_encoder_a,
        .gpio_encoder_b = (uint8_t)gpio_encoder_b,
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

void ESP_Knob::registerLeftCb(knob_cb_t cb, void *usr_data)
{
    esp_err_t err = iot_knob_register_cb(knob_handle, KNOB_LEFT, cb, usr_data);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error register knob left callback");
    }
}

void ESP_Knob::unregisterLeftCb()
{
    esp_err_t err = iot_knob_unregister_cb(knob_handle, KNOB_LEFT);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error unregister knob left callback");
    }
}

void ESP_Knob::registerRightCb(knob_cb_t cb, void *usr_data)
{
    esp_err_t err = iot_knob_register_cb(knob_handle, KNOB_RIGHT, cb, usr_data);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error register knob right callback");
    }
}

void ESP_Knob::unregisterRightCb()
{
    esp_err_t err = iot_knob_unregister_cb(knob_handle, KNOB_RIGHT);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error unregister knob right callback");
    }
}

void ESP_Knob::registerHighLimitCb(knob_cb_t cb, void *usr_data)
{
    esp_err_t err = iot_knob_register_cb(knob_handle, KNOB_H_LIM, cb, usr_data);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error register knob high limit callback");
    }
}

void ESP_Knob::unregisterHighLimitCb()
{
    esp_err_t err = iot_knob_unregister_cb(knob_handle, KNOB_H_LIM);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error unregister knob high limit callback");
    }
}

void ESP_Knob::registerLowLimitCb(knob_cb_t cb, void *usr_data)
{
    esp_err_t err = iot_knob_register_cb(knob_handle, KNOB_L_LIM, cb, usr_data);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error register knob low limit callback");
    }
}

void ESP_Knob::unregisterLowLimitCb()
{
    esp_err_t err = iot_knob_unregister_cb(knob_handle, KNOB_L_LIM);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error unregister knob low limit callback");
    }
}

void ESP_Knob::registerZeroCb(knob_cb_t cb, void *usr_data)
{
    esp_err_t err = iot_knob_register_cb(knob_handle, KNOB_ZERO, cb, usr_data);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error register knob zero callback");
    }
}

void ESP_Knob::unregisterZeroCb()
{
    esp_err_t err = iot_knob_unregister_cb(knob_handle, KNOB_ZERO);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error unregister knob zero callback");
    }
}

void ESP_Knob::registerEvent(knob_event_t event, knob_cb_t cb, void *usr_data)
{
    esp_err_t err = iot_knob_register_cb(knob_handle, event, cb, usr_data);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error register knob callback");
    }
}

void ESP_Knob::unregisterEvent(knob_event_t event)
{
    esp_err_t err = iot_knob_unregister_cb(knob_handle, event);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error unregister knob callback");
    }
}

knob_event_t ESP_Knob::getEvent()
{
    return iot_knob_get_event(knob_handle);
}

int ESP_Knob::getCountValue()
{
    return iot_knob_get_count_value(knob_handle);
}

void ESP_Knob::clearCountValue()
{
    iot_knob_clear_count_value(knob_handle);
}
