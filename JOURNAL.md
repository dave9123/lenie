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
![ESP32 with ILI9341 Schematics I made](https://dave9123.me/assets/kicad_Y0P2RdrOQQ.png)

Time spent: 4 hours

## May 26th, 2025

I decided to add LED matrix as the TFT display emits blue light which isn't necessarily great for eyes as it could disrupt sleep-wake cycle. Also, red light before bed can improve the ability to fall asleep and wake up refreshed based on a study.

|                           Schematics                           | PCB                                                     | 3D View #1                                                     | 3D View #2                                                     |
| :------------------------------------------------------------: | :-----------------------------------------------------: | :------------------------------------------------------------: | :------------------------------------------------------------: |
| ![Schematics](https://dave9123.me/assets/kicad_IpeoWiujsL.jpg) | ![PCB](https://dave9123.me/assets/kicad_ov2GFOG3tD.jpg) | ![3D View #1](https://dave9123.me/assets/kicad_K7pklo50ou.jpg) | ![3D View #2](https://dave9123.me/assets/kicad_1gZMiEnWAk.jpg) |

![Current Bill of Material](https://dave9123.me/assets/firefox_xtIIQq1NK6.jpg)
I currently have the incomplete Bill of Material, haven't thought of integrating the 5 tactile switches as of now yet.

Useful resources:
- https://www.theguardian.com/lifeandstyle/2023/oct/01/should-i-worry-about-blue-light
- https://www.reddit.com/r/NoStupidQuestions/comments/1h9wh2m/is_it_bad_to_sleep_with_red_leds/

Time spent: 3 hours
## Reference
![ESP32 DOIT DEVKIT V1 Board Pinout](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/08/ESP32-DOIT-DEVKIT-V1-Board-Pinout-36-GPIOs-updated.jpg?resize=750%2C538&quality=100&strip=all&ssl=1)