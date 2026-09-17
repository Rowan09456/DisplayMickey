/* Example code to talk to a SSD1306 OLED display, 128 x 64 pixels

   NOTE: Ensure the device is capable of being driven at 3.3v NOT 5v. The Pico
   GPIO (and therefor I2C) cannot be used at 5v.

   Connections on Raspberry Pi Pico board, other boards may vary.

   GPIO 6 (pin 9)-> SDA on SSD1306 board
   GPIO 7 (pin 10)-> SCL on SSD1306 board
   3.3v (pin 36) -> VCC on SSD1306 board
   GND (pin 38)  -> GND on SSD1306 board
*/

// By default these devices are on bus address 0x3C or 0x3D. Check your documentation.
static int DEVICE_ADDRESS = 0x3C;

#define I2C_PORT i2c1
#define I2C_SDA_PIN 6
#define I2C_SCL_PIN 7

 // This can be overclocked, 2000 seems to work on the device being tested
 // Spec says 400 is the maximum. Try faster clocks until it stops working!
 // KHz.
#define I2C_CLOCK  1000

#define SSD1306_LCDWIDTH            128
#define SSD1306_LCDHEIGHT           64
#define SSD1306_FRAMEBUFFER_SIZE    (SSD1306_LCDWIDTH * SSD1306_LCDHEIGHT / 8)
 
 void WriteBigString(int x, int y, uint8_t *str);
 void WriteString(int x, int y, uint8_t *str);
 void WriteBigChar(uint x, uint y, uint8_t ch);
 void DrawLine(int x0, int y0, int x1, int y1, bool on);
void ClearDisplay();
void UpdateDisplay();
void SSD1306_initialise();
void InvertDisplay(bool yes);

