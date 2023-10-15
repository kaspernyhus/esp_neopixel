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
#include "hal/gpio_types.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


static const char* TAG = "EXAMPLE-NEOPIXEL";


void app_main(void)
{
    ESP_LOGI(TAG, "----------------------");

    esp_neopixel_config_t cfg = {
        .rmt_channel = 0,
        .gpio = GPIO_NUM_15
    };
    esp_neopixel_init(&cfg);

    while (1) {
        ESP_LOGI(TAG, "Set pixel");
        esp_neopixel_set_pixel(13, 30, 1);
        esp_neopixel_on();
        vTaskDelay(pdMS_TO_TICKS(1000));

        ESP_LOGI(TAG, "OFF");
        esp_neopixel_off();
        vTaskDelay(pdMS_TO_TICKS(1000));

        ESP_LOGI(TAG, "Set color");
        esp_neopixel_set_color(NEOPIXEL_ORANGE);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
