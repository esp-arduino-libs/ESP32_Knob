#include <Arduino.h>
#include <ESP_Knob.h>

#define GPIO_KNOB_A 1
#define GPIO_KNOB_B 2

ESP_Knob *knob = new ESP_Knob(GPIO_KNOB_A, GPIO_KNOB_B);

static void knob_left_cb(void *arg, void *data)
{
    Serial.printf("KNOB_LEFT Count is %d\n", knob->getCountValue());
}

static void knob_right_cb(void *arg, void *data)
{
    Serial.printf("KNOB_RIGHT Count is %d\n", knob->getCountValue());
}

static void knob_h_lim_cb(void *arg, void *data)
{
    Serial.println("KNOB_H_LIM");
}

static void knob_l_lim_cb(void *arg, void *data)
{
    Serial.println("KNOB_L_LIM");
}

static void knob_zero_cb(void *arg, void *data)
{
    Serial.println("KNOB_ZERO");
}

void setup() {
    Serial.begin(115200);
    Serial.println("ESP_Knob example");

    knob->begin();
    knob->registerEvent(KNOB_LEFT, knob_left_cb, NULL);
    knob->registerEvent(KNOB_RIGHT, knob_right_cb,NULL);
    knob->registerEvent(KNOB_H_LIM, knob_h_lim_cb, NULL);
    knob->registerEvent(KNOB_L_LIM, knob_l_lim_cb, NULL);
    knob->registerEvent(KNOB_ZERO, knob_zero_cb, NULL);
}

void loop() {
    delay(1000);
}
