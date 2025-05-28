---
title: Lenie
author: dave9123
description: A smart alarm clock that helps you reduce distractions.
created_at: 2025-05-24
---
Problems I encounter:
- I tend to use my phone directly after I got out of bed as I use it as an alarm to wake me up.
	- Looking at your phone first thing in the morning can have several potential negative effects on your eyes and overall well-being according to https://www.healthshots.com/mind/mental-health/side-effects-of-using-phone-in-the-morning/.
	- The distractions such as notifications causes me to look at it first instead of preparing for the day.

## May 24th, 2025

Made some base design for the display and the wiring.

![Clock display design](https://dave9123.me/assets/Figma_Ew2eRsVyQt.jpg)
![ESP32 with ILI9341 Schematic I made](https://dave9123.me/assets/kicad_Y0P2RdrOQQ.png)

Time spent: 4 hours

## May 26th, 2025

I decided to add LED matrix as the TFT display emits blue light which isn't necessarily great for eyes as it could disrupt sleep-wake cycle. Also, red light before bed can improve the ability to fall asleep and wake up refreshed based on a study.

|                           Schematic                           | PCB                                                     | 3D View #1                                                     | 3D View #2                                                     |
| :-----------------------------------------------------------: | :-----------------------------------------------------: | :------------------------------------------------------------: | :------------------------------------------------------------: |
| ![Schematic](https://dave9123.me/assets/kicad_IpeoWiujsL.jpg) | ![PCB](https://dave9123.me/assets/kicad_ov2GFOG3tD.jpg) | ![3D View #1](https://dave9123.me/assets/kicad_K7pklo50ou.jpg) | ![3D View #2](https://dave9123.me/assets/kicad_1gZMiEnWAk.jpg) |

![Current Bill of Material](https://dave9123.me/assets/firefox_xtIIQq1NK6.jpg)
I currently have the incomplete Bill of Material, haven't added the 5 tactile buttons yet.

Useful resources:
- https://www.theguardian.com/lifeandstyle/2023/oct/01/should-i-worry-about-blue-light
- https://www.reddit.com/r/NoStupidQuestions/comments/1h9wh2m/is_it_bad_to_sleep_with_red_leds/

Edit: Added to the schematics!

Time spent: 3 hours

## May 27, 2025

I plan to use the tactile buttons to configure
- OK/Snooze (hold)
- Left/Back (hold)
- Right/Show Calendar (hold)
- Up/Show To Do (hold)
- Down/Show Alarm (hold)

Now, for the button. I am being indecisive on either a short or long 12 mm push button as the short one is more expensive than the long one but it's still similar.

| Short | Long |
| :-: | :-: |
| ![short 12 mm push button - Shopee](https://dave9123.me/assets/firefox_9sAsX9aZbQ.jpg) | ![long 12 mm push button - Shopee](https://dave9123.me/assets/firefox_cpeNnMvyod.jpg) |

Now that I remember that the smart clock will be big due to the LED matrix being 32x8 and ILI9341 being 3.2", the long one might do while saving up on costs and reducing wire usage. However, I'll get back into this problem after I started making the CAD design.

Time spent: 3 hours

## May 28, 2025

So I'm deciding on adding even more buttons for controlling and functionalities.
- OK / Snooze (hold) / Dismiss (double click)
- Left / Back (hold)
- Right / Show Calendar (hold)
- Up / Show To Do (hold) / Timer (double click)
- Down / Show Alarm (hold) / Stopwatch (double click)
- Volume Up
- Volume Down

Tbh, I would really prefer having both snooze and dismiss alarm bigger and on a separate location. Also, the volume controls can be like from double clicking another button then using the current up down buttons to control the volume followed by OK to save.

While I'm planning to use a 3.7V 2000 mAh LiPo, I'm incredible scared if it's not going to have enough power because I'm going to be powering 2 incredibly power hungry speakers, 3W, which is quite big knowing regular most USB is feeding 5V 2A—I'm hoping for the best at this point lol.

|                            Bill of Material                            |                           Schematic                           |
| :--------------------------------------------------------------------: | :-----------------------------------------------------------: |
| ![Bill of Material](https://dave9123.me/assets/firefox_oofeG6Y7yf.jpg) | ![Schematic](https://dave9123.me/assets/kicad_No386VCskA.jpg) |
Some Bill of Material and schematic updates—added a TP4056 as charge and battery protection, an MT3608 as step up boost converter, two speaker for alarm tone music playback, a LiPo battery as a backup power, a capacitor to smooth current spikes and prevent reset on ESP32, a PAM8403 to amplify speaker sound.

Notes:
- Don’t forget **pull-down resistor** on the voltage divider to avoid floating input.
- **Do NOT charge batteries without a protection/charging circuit** (like TP4056).
- Optionally, add a **battery status indicator LED** for low battery warning.
- **Do not connect speaker negatives to GND.** PAM8403 is a **differential output amplifier** — both `+` and `−` of each speaker must go to the respective pins.

Time spent: 4 hours

## Reference
![ESP32 DOIT DEVKIT V1 30 GPIOs Board Pinout](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/08/ESP32-DOIT-DEVKIT-V1-Board-Pinout-30-GPIOs-Copy.png?quality=100&strip=all&ssl=1)