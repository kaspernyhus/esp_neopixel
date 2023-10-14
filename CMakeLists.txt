idf_component_register(SRCS
        "esp_neopixel.c"
        "led_strip_rmt_ws2812.c"
    INCLUDE_DIRS "include"
    PRIV_REQUIRES "driver"
)
