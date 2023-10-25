#include <Arduino.h>
#include <ESP_Knob.h>

#define GPIO_KNOB_A 1
#define GPIO_KNOB_B 2

ESP_Knob knob = new ESP_Knob(GPIO_KNOB_A, GPIO_KNOB_B);

static void knob_left_cb(void *arg, void *data)
{
    Serial.println("KNOB_LEFT Count is %d usr_data: %s", knob.get_count_value(), (char *)data);
}

static void knob_right_cb(void *arg, void *data)
{
    Serial.println("KNOB_RIGHT Count is %d usr_data: %s", knob.get_count_value(), (char *)data);
}

static void knob_h_lim_cb(void *arg, void *data)
{
    Serial.println("KNOB_H_LIM usr_data: %s", (char *)data);
}

static void knob_l_lim_cb(void *arg, void *data)
{
    Serial.println("KNOB_L_LIM usr_data: %s", (char *)data);
}

static void knob_zero_cb(void *arg, void *data)
{
    Serial.println("KNOB_ZERO usr_data: %s", (char *)data);
}

void setup() {
    Serial.begin(115200);
    Serial.println("ESP_Knob example");

    knob.begin();
    knob.register_cb(KNOB_LEFT, knob_left_cb, "KNOB_LEFT");
    knob.register_cb(KNOB_RIGHT, knob_right_cb, "KNOB_RIGHT");
    knob.register_cb(KNOB_H_LIM, knob_h_lim_cb, "KNOB_H_LIM");
    knob.register_cb(KNOB_L_LIM, knob_l_lim_cb, "KNOB_L_LIM");
    knob.register_cb(KNOB_ZERO, knob_zero_cb, "KNOB_ZERO");
}

void loop() {
    Serial.println(knob.read());
    delay(100);
}
