/**
 * @file esp_neopixel.c
 * @author Kasper Nyhus
 * @brief
 * @version 0.1
 * @date 2023-10-14
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "esp_neopixel.h"
#include "led_strip.h"

static const uint8_t led_timeout_ms = 5;
static led_strip_t* pStrip_a = NULL;

void esp_neopixel_init(esp_neopixel_config_t* cfg)
{
    /* LED strip initialization with the GPIO and pixels number*/
    pStrip_a = led_strip_init(cfg->rmt_channel, cfg->gpio, 1);
    /* Set all LED off to clear all pixels */
    pStrip_a->clear(pStrip_a, led_timeout_ms);
}

void esp_neopixel_on(void)
{
    if (pStrip_a != NULL) {
        /* Refresh the strip to send data */
        pStrip_a->refresh(pStrip_a, led_timeout_ms);
    }
}

void esp_neopixel_off(void)
{
    if (pStrip_a != NULL) {
        pStrip_a->clear(pStrip_a, led_timeout_ms);
    }
}

void esp_neopixel_set_color(esp_neopixel_color_t color)
{
    if (pStrip_a == NULL) {
        return;
    }
    switch (color) {
    case NEOPIXEL_WHITE:
        pStrip_a->set_pixel(pStrip_a, 0, LED_MAX_INTENSITY, LED_MAX_INTENSITY, LED_MAX_INTENSITY);
        break;
    case NEOPIXEL_ORANGE:
        pStrip_a->set_pixel(pStrip_a, 0, LED_MAX_INTENSITY, (LED_MAX_INTENSITY / 3), 0);
        break;
    case NEOPIXEL_RED:
        pStrip_a->set_pixel(pStrip_a, 0, LED_MAX_INTENSITY, 0, 0);
        break;
    case NEOPIXEL_GREEN:
        pStrip_a->set_pixel(pStrip_a, 0, 0, LED_MAX_INTENSITY, 0);
        break;
    case NEOPIXEL_BLUE:
        pStrip_a->set_pixel(pStrip_a, 0, 0, 0, LED_MAX_INTENSITY);
        break;
    case NEOPIXEL_PURPLE:
        pStrip_a->set_pixel(pStrip_a, 0, LED_MAX_INTENSITY, 0, LED_MAX_INTENSITY);
        break;
    default:
        break;
    }
    pStrip_a->refresh(pStrip_a, 100);
}

void esp_neopixel_set_pixel(uint32_t red, uint32_t green, uint32_t blue)
{
    pStrip_a->set_pixel(pStrip_a, 0, red, green, blue);
}
