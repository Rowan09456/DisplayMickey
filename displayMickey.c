#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/i2c.h"
#include "ssd1306_i2c.h"

int main()
{
    stdio_init_all();

    printf("Hello, SSD1306! ...\n");
    i2c_init(I2C_PORT, I2C_CLOCK * 1000);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA_PIN);
    gpio_pull_up(I2C_SCL_PIN);
 

    SSD1306_initialise();
      if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    int i = 0;
    

    while (1) {
        printf("Hell0, world [%d]!\n", i++);
        sleep_ms(1000);
         cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,!cyw43_arch_gpio_get(CYW43_WL_GPIO_LED_PIN) );

        ClearDisplay();

        DrawLine(0,0,SSD1306_LCDWIDTH-1, 0, true);
        DrawLine(0,0,0,SSD1306_LCDHEIGHT-1, true);
        DrawLine(SSD1306_LCDWIDTH-1, 0,SSD1306_LCDWIDTH-1, SSD1306_LCDHEIGHT-1, true);
        DrawLine(0,SSD1306_LCDHEIGHT-1,SSD1306_LCDWIDTH-1, SSD1306_LCDHEIGHT-1, true);

        WriteString(13,8,"HELLO SSD1306");

        for (int ch = '9'; ch>='1';ch--)
        {
            WriteBigChar(56, 36, ch);
            UpdateDisplay();
            sleep_ms(500);
        }

        WriteBigString(0,35,"BLASTOFF");
        UpdateDisplay();

        for (int i = 0;i<10;i++)
        {
            InvertDisplay(true);
            sleep_ms(100);
            InvertDisplay(false);
            sleep_ms(100);
        }

        for (int i=0;i<SSD1306_LCDWIDTH;i++) {
            if (i >= SSD1306_LCDWIDTH/2) {
                DrawLine(i,0,i, SSD1306_LCDHEIGHT-1, false);
                DrawLine(SSD1306_LCDWIDTH - i - 1,0,SSD1306_LCDWIDTH - i - 1, SSD1306_LCDHEIGHT-1, false);
            }
            else {
                DrawLine(i,0,i, SSD1306_LCDHEIGHT-1, true);
                DrawLine(SSD1306_LCDWIDTH - i - 1,0,SSD1306_LCDWIDTH - i - 1, SSD1306_LCDHEIGHT-1,  true);
            }
            UpdateDisplay();
        }

    }

    printf("Done\n");

    return 0;
}
