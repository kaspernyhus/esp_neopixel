idf_component_register(SRCS
        "esp_neopixel.c"
        "led_strip_rmt.c"
    INCLUDE_DIRS "include"
    PRIV_REQUIRES "driver"
)
