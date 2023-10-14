# ESP Neopixel module

### Using old RMT driver

```
esp_neopixel_config_t cfg = {
        .rmt_channel = 0,
        .gpio = 15
    };
    esp_neopixel_init(&cfg);
```

