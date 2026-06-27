#include "onewire_bus.h"
#include "ds18b20.h"

#include "sensor.h"


#include "esp_log.h"



#define DS18B20_GPIO 4



static const char *TAG = "DS18B20";


static ds18b20_device_handle_t sensor;



void sensor_init(void)
{

    onewire_bus_handle_t bus;



    onewire_bus_config_t bus_config =
    {
        .bus_gpio_num = DS18B20_GPIO,
    };



    onewire_bus_rmt_config_t rmt_config =
    {
        .max_rx_bytes = 10,
    };



    ESP_ERROR_CHECK(
        onewire_new_bus_rmt(
            &bus_config,
            &rmt_config,
            &bus
        )
    );



    onewire_device_iter_handle_t iter;



    ESP_ERROR_CHECK(
        onewire_new_device_iter(
            bus,
            &iter
        )
    );



    onewire_device_t device;



    if(onewire_device_iter_get_next(
            iter,
            &device) == ESP_OK)
    {

        ds18b20_config_t config =
        {
          
        };


        ESP_ERROR_CHECK(
            ds18b20_new_device_from_enumeration(
                &device,
                &config,
                &sensor
            )
        );


        ESP_LOGI(
            TAG,
            "DS18B20 Found"
        );

    }

    else
    {

        ESP_LOGE(
            TAG,
            "No DS18B20 found"
        );

    }



    ESP_ERROR_CHECK(
        onewire_del_device_iter(iter)
    );


}



float sensor_get_temp(void)
{

    float temperature = 0;



    ESP_ERROR_CHECK(
        ds18b20_trigger_temperature_conversion(sensor)
    );



    ESP_ERROR_CHECK(
        ds18b20_get_temperature(
            sensor,
            &temperature
        )
    );



    return temperature;

}





