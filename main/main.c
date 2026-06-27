#include "freertos/idf_additions.h"
#include "portmacro.h"
#include "stdio.h"

#include "wifi.h"
#include "sensor.h"
#include "mqtt.h"
#include "OLED.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "nvs_flash.h"
#include "esp_err.h"
#include <stdio.h>

QueueHandle_t temp_queue;

void sensor_task(void *arg)
{
	while(1)
	{
		float temp;


		temp = sensor_get_temp();
		
		
		xQueueSend(temp_queue, &temp, portMAX_DELAY);
		
		vTaskDelay(pdMS_TO_TICKS(2000));

	}
}

void oled_task(void *arg)
{
	float temp;
	
	while(1)
	{
		if(xQueueReceive(temp_queue, &temp, portMAX_DELAY))
		{
			oled_display_temp(temp);
		}
		vTaskDelay(pdMS_TO_TICKS(3000));
	}
}

void mqtt_task(void *arg)
{
	float temp;
	
	while(1)
	{
		
		if(xQueueReceive(temp_queue, &temp, portMAX_DELAY))
		{
			printf("Temperature = %.2f C\n",temp);
			mqtt_publish_temp(temp);
		}
			
	}
}

void app_main(void)
{
	esp_err_t ret = nvs_flash_init();

	    if(ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
	    {
	        nvs_flash_erase();
	        nvs_flash_init();
	    }

    wifi_init();
	
	vTaskDelay(pdMS_TO_TICKS(5000));

    sensor_init();

    oled_init();

	mqtt_start();

	temp_queue = xQueueCreate(5, sizeof(float));
	
	xTaskCreatePinnedToCore(
			sensor_task,
			"sensor",
			2048, 
			NULL, 
			5, 
			NULL, 
			0);
			
	xTaskCreatePinnedToCore(
			oled_task,
			"OLED",
			2048, 
			NULL, 
			4, 
			NULL, 
			1);
			
	xTaskCreatePinnedToCore(
			mqtt_task,
			"MQTT",
			4096, 
			NULL, 
			3, 
			NULL, 
			1);
}
