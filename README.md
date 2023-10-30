[![Arduino Lint](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/arduino_lint.yml/badge.svg)](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/arduino_lint.yml) [![pre-commit](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/pre-commit.yml/badge.svg)](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/pre-commit.yml) [![Build Test Apps](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/build_test.yml/badge.svg)](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/build_test.yml)


## Component Knob

`Knob` is the component that provides the software PCNT, it can be used on chips(esp32c2, esp32c3) that do not have PCNT hardware capabilities. By using this component, you can quickly use a physical encoder, such as the EC11 encoder.

Features:

1. Support multiple knobs
2. Support each event can register its own callback
3. Support setting the upper and lower count limits

List of supported events:

 * Knob left
 * Knob right
 * Knob high limit
 * Knob low limit
 * Knob back to zero

## Supported Drivers

|                             **Driver**                             | **Version** |
| ------------------------------------------------------------------ | ----------- |
| [knob](https://components.espressif.com/components/espressif/knob) | 0.1.3       |

## Dependencies Version

|                          **Name**                           | **Version** |
| ----------------------------------------------------------- | ----------- |
| ESP32_Knob                                                  | v0.x.x      |
| [arduino-esp32](https://github.com/espressif/arduino-esp32) | >= v2.0.4   |

## How to Use

For information on how to use the library in the Arduino IDE, please refer to the documentation for [Arduino IDE v1.x.x](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries) or [Arduino IDE v2.x.x](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-installing-a-library).

### Examples

* [Test Functions](examples/TestFunctions): Demonstrates how to use ESP32-Knob and test all functions.

### Detailed Usage

```cpp
#include <ESP_Knob.h>

#define GPIO_KNOB_A 1
#define GPIO_KNOB_B 2

ESP_Knob *knob = new ESP_Knob(GPIO_KNOB_A, GPIO_KNOB_B);

static void knob_left_cb(void *arg, void *data)
{
    Serial.printf("KNOB_LEFT Count is %d\n", knob->getCountValue());
}

knob->begin();
knob->registerEvent(KNOB_LEFT, knob_left_cb, NULL);

// Release the ESP_IOExpander object
delete knob;
```

`Note`: This component is only suitable for decoding low-speed rotary encoders such as EC11, and does not guarantee the complete correctness of the pulse count. For high-speed and accurate calculations, please use hardware [PCNT](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/peripherals/pcnt.html?highlight=pcnt)

* | Hardware PCNT Supported Targets | ESP32 | ESP32-C6 | ESP32-H2 | ESP32-S2 | ESP32-S3 |
  | ------------------------------- | ----- | -------- | -------- | -------- | -------- |