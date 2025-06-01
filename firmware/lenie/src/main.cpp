#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <SD.h>
#include <Wire.h>
#include <SPI.h>
#include <RTClib.h>
#include <LEDControl.h>

#include "config.h"

TFT_eSPI tft = TFT_eSPI();
RTC_DS3231 rtc;

void setup()
{
    Serial.begin(115200);

    analogReadResolution(12);

    SPI.begin(SD_SCK, SD_MISO, SD_MOSI, -1);

    Wire.begin(DS3231_SDA, DS3231_SCL);

    if (!rtc.begin())
    {
        Serial.println("Couldn't find RTC!");
    }

    dacWrite(PAM8403_L, 0);
    dacWrite(PAM8403_R, 0);

    pinMode(BUTTON_1, INPUT_PULLUP);
    pinMode(BUTTON_2, INPUT_PULLUP);
    pinMode(BUTTON_3, INPUT_PULLUP);
    pinMode(BUTTON_4, INPUT_PULLUP);
    pinMode(BUTTON_5, INPUT_PULLUP);

    pinMode(SD_DETECT, INPUT_PULLUP);

    if (!SD.begin(SD_CS))
    {
        Serial.println("Failed to mount SD Card");
    }
    else
    {
        Serial.println("Mounted SD Card successfully");
    }

    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);

    lv_init();
}

unsigned long lastLoggingTime = 0;

void loop()
{
    lv_timer_handler();
    delay(5);

    if (millis() - lastLoggingTime > 2000 || millis() < lastLoggingTime)
    {
        checkBatteryLevel();
        checkSDCard();
    }

    lastLoggingTime = millis();
}

void checkSDCard()
{
    if (digitalRead(SD_DETECT) == LOW)
    {
        Serial.println("SD Card is inserted");
    }
    else
    {
        Serial.println("SD Card is not inserted");
    }
}

void checkBatteryLevel()
{
    int rawBatteryVoltage = analogRead(BATTERY_LEVEL);
    float batteryVoltage = (rawBatteryVoltage * 3.3 / 4095) / BATTERY_DIVIDER_RATIO;
    int batteryPercentage = round((batteryVoltage - BATTERY_MIN_VOLTAGE) / (BATTERY_MAX_VOLTAGE - BATTERY_MIN_VOLTAGE) * 100);

    Serial.printf("Battery Percentage: %d | Adjusted Voltage: %.2fV\n", batteryPercentage, batteryVoltage);

    if (batteryVoltage < BATTERY_MIN_VOLTAGE)
    {
        Serial.println("Battery voltage too low!");
    }
    else if (batteryVoltage > BATTERY_MAX_VOLTAGE)
    {
        Serial.println("Battery voltage too high!");
    }
}