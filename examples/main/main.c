/**
 * @file main.c
 * @author Kasper Nyhus
 * @brief
 * @version 0.1
 * @date 2023-06-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>
#include <string.h>

#include "esp_err.h"
#include "esp_log.h"
#include "esp_neopixel.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


static const char* TAG = "EXAMPLE-NEOPIXEL";


void app_main(void)
{
    ESP_LOGI(TAG, "----------------------");

    esp_neopixel_config_t cfg = {
        .rmt_channel = 0,
        .gpio = 15
    };
    esp_neopixel_init(&cfg);

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
