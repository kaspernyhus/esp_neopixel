/**
 * @file esp_neopixel.h
 * @author Kasper Nyhus
 * @brief
 * @version 0.1
 * @date 2023-10-14
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    NEOPIXEL_WHITE,
    NEOPIXEL_ORANGE,
    NEOPIXEL_RED,
    NEOPIXEL_GREEN,
    NEOPIXEL_BLUE,
    NEOPIXEL_PURPLE,
} esp_neopixel_color_t;

typedef struct {
    uint8_t rmt_channel;
    uint8_t gpio;
    bool invert;
} esp_neopixel_config_t;

/**
 * @brief Configure neopixel RMT Channel & TX GPIO
 *
 * @param cfg
 */
void esp_neopixel_init(esp_neopixel_config_t* cfg);

/**
 * @brief Turn neopixel on
 *
 */
void esp_neopixel_on(void);

/**
 * @brief Turn neopixel off
 *
 */
void esp_neopixel_off(void);

/**
 * @brief Set predefined color
 *
 * @param color
 */
void esp_neopixel_set_color(esp_neopixel_color_t color, uint8_t intensity);

/**
 * @brief Set custom RGB color
 *
 * @param red
 * @param green
 * @param blue
 */
void esp_neopixel_set_pixel(uint32_t red, uint32_t green, uint32_t blue);
