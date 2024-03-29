
/*
// test_main.c
*/

/*
=================
last modified: 2024/2/25
=================
*/

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_bt.h"
#include "driver/uart.h"
#include "string.h"

#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"

#include "bdi.h"
#include "mockdata_t.h"


void app_main(void)
{
    esp_err_t ret;
    mockdata_t data = {'a','b','c', 127};

    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );

    bdi_port_init_default();
    bdi_begin_advertising();
    for(;;)
    {
        bdi_send_packet(&data);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    return;
}
