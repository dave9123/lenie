#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <SD.h>
#include <Wire.h>
#include <SPI.h>
#include <RTClib.h>
#include <LEDControl.h>
#include <SPIFFS.h>

#include "config.h"

TFT_eSPI tft = TFT_eSPI();
RTC_DS3231 rtc(DS3231_SDA, DS3231_SCL);

void setup()
{
    Serial.begin(115200);

    analogReadResolution(12);

    SPI.begin(SD_SCK, SD_MISO, SD_MOSI, -1);

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
    configTime(0, 0, "pool.ntp.org", "time.nist.gov");
}

long lastLoggingTime = 0;
long lastTimeUpdate = 0;
bool hasWifiBeenConnect = false;

void loop()
{
    lv_timer_handler();
    delay(5);
    
    if (hasWifiBeenConnect == false && WiFi.status() == WL_CONNECTED)
    {
        hasWifiBeenConnect = true;
    }

    if (millis() - lastLoggingTime > 10000 || millis() < lastLoggingTime || lastLoggingTime == 0)
    {
        checkBatteryLevel();
        checkSDCard();
    }

    if (WiFi.status() == WL_CONNECTED && (millis() - lastTimeUpdate > 1 * 60 * 1000 || millis() < lastTimeUpdate || lastTimeUpdate == 0))
    {
        timeClient.update();
        Serial.printf("Current Time: %s\n", timeClient.getFormattedTime().c_str());
        lastTimeUpdate = millis();
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