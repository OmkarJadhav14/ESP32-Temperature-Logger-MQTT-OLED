#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/i2c_master.h"

#include "ssd1306.h"


#define I2C_SDA 21
#define I2C_SCL 22

ssd1306_handle_t oled;

void oled_init(void)
{
	// I2C bus configuration

	   i2c_master_bus_config_t bus_config =
	   {
	       .clk_source = I2C_CLK_SRC_DEFAULT,

	       .i2c_port = I2C_NUM_0,

	       .sda_io_num = I2C_SDA,

	       .scl_io_num = I2C_SCL,

	       .flags.enable_internal_pullup = true
	   };


	   i2c_master_bus_handle_t i2c_bus;


	   ESP_ERROR_CHECK(
	       i2c_new_master_bus(
	           &bus_config,
	           &i2c_bus
	       )
	   );


	   // OLED configuration

	   ssd1306_config_t oled_config =
	       I2C_SSD1306_128x64_CONFIG_DEFAULT;


	   //ssd1306_handle_t oled;


	   ESP_ERROR_CHECK(
	       ssd1306_init(
	           i2c_bus,
	           &oled_config,
	           &oled
	       )
	   );


	   // clear display
	   
	   ssd1306_clear_display(
	       oled,
	       false
	   );
}

void oled_display_temp(float temperature)
{

    char temp[20];


    sprintf(
        temp,
        "Temp: %.2f C",
        temperature
    );

	// write text

	ssd1306_display_text(
	    oled,
	    0,
	    "Temp Logger",
	    false
	);

    ssd1306_display_text(
        oled,
        2,
        temp,
        false
    );

}