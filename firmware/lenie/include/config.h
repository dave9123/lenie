#ifndef LENIE_CONFIG_H
#define LENIE_CONFIG_H

#define WIFI_SETUP_SSID "Lenie" // Runs as AP for onboarding, 32 characters max
// #define WIFI_PASSWORD_OVERRIDE "" // Uncomment this to override automatic password generation
#define WIFI_HOSTNAME "lenie" // 253 ASCII characters max, may contain only the ASCII letters a-z (in a case-insensitive manner), the digits 0-9, and the hyphen-minus character ('-')

#define TIMEZONE_OVERRIDE "Asia/Jakarta"

#define BATTERY_MAX_VOLTAGE 4.2
#define BATTERY_MIN_VOLTAGE 3.0
#define BATTERY_DIVIDER_RATIO (470/1470)

#define BUTTON_1 23
#define BUTTON_2 27
#define BUTTON_3 32
#define BUTTON_4 33
#define BUTTON_5 35

#define TFT_DC 2
#define TFT_CS 15
#define TFT_SCLK 14
#define TFT_MOSI 13
#define TFT_MISO 12
#define TFT_RST 4
#define TFT_BL 18

#define SD_CS 5
#define SD_MOSI 13
#define SD_MISO 12
#define SD_SCK 14
#define SD_DETECT 34

#define LED_DIN 12
#define LED_CS 19
#define LED_SCK 14

#define PAM8403_L 25
#define PAM8403_R 26

#define DS3231_SCL 22
#define DS3231_SDA 21

#define BATTERY_LEVEL 36

#endif