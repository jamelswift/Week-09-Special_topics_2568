#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_PIN GPIO_NUM_2
static const char *TAG = "LED_APP";

void app_main(void)
{
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(LED_PIN, 1);   // เปิดไฟ
        ESP_LOGI(TAG, "LED ON");
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        gpio_set_level(LED_PIN, 0);   // ปิดไฟ
        ESP_LOGI(TAG, "LED OFF");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
