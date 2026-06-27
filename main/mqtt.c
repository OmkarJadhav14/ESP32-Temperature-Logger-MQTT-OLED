#include "esp_log.h"
#include "mqtt_client.h"


esp_mqtt_client_handle_t mqtt_client= NULL;

static const char *TAG = "MQTT_Temp";

static void mqtt_event_handler(void *handler_args, esp_event_base_t base,int32_t event_id,void *event_data)
{
    esp_mqtt_event_handle_t event =(esp_mqtt_event_handle_t)event_data;

    switch((esp_mqtt_event_id_t)event_id)
    {
        case MQTT_EVENT_CONNECTED:
            ESP_LOGI(TAG,
                     "MQTT Connected");
            break;

        case MQTT_EVENT_DISCONNECTED:
            ESP_LOGW(TAG,
                     "MQTT Disconnected");
            break;

        case MQTT_EVENT_PUBLISHED:
            ESP_LOGI(TAG,
                     "MQTT Message Published");
            break;

        default:
            break;
    }
}

 void mqtt_start(void)
{
    esp_mqtt_client_config_t mqtt_cfg = 
	{
		.broker.address.uri ="mqtt://broker.emqx.io",
    };

    mqtt_client =esp_mqtt_client_init(&mqtt_cfg);

    esp_mqtt_client_register_event(
        mqtt_client,
        ESP_EVENT_ANY_ID,
        mqtt_event_handler,
        NULL);

    esp_mqtt_client_start(mqtt_client);

    ESP_LOGI(TAG, "MQTT Started");
}

void mqtt_publish_temp(float temperature)
{

    char data[50];

    sprintf(data, "{\"temperature\":%.2f}",temperature);


    esp_mqtt_client_publish(
        mqtt_client,
        "esp32/temp",
        data,
        0,
        1,
        0
    );

}