# AuroraDrop v0.0.14

RGB Matrix Audio Visualiser for ESP32

Based on the FastLED Auroa Demo by Jason Coon, and using the ESP32-HUB75-MatrixPanel-I2S-DMA library by mrfaptastic.

Welcome. Work is in progress, updates may appear now and then.

## Introduction

AuroraDrop creates and runs multiple random patterns based on audio input from your PC, and renders them in a sequenced, multi-parallelized, unpredictable flow. Thrown in are a few random effects, some image manipulations and complimentary fixed and re-active animations, also borrowed from the Jason's Auroa demo.

AuroraDrop currently works with HUB75 matrix panels, and now, at an experimental level, on standard LED strip based panels (though not quite as fast) and the TTGO TFT Dev Board and T-Watch.

Details for wiring your ESP32 to a HUB75 panel can be found on mrfaptastic's ESP32-HUB75-MatrixPanel-I2S-DMA project page.
https://github.com/mrfaptastic/ESP32-HUB75-MatrixPanel-I2S-DMA#2-wiring-esp32-with-the-led-matrix-panel

## Some Pics and Videos

![example_matrix_animation1](https://user-images.githubusercontent.com/4552572/134411163-7eed342a-f806-48df-8284-c8c2a170b4af.gif)
![example_matrix_diagnostics1](https://user-images.githubusercontent.com/4552572/134822397-68405460-cfea-4bf5-96b5-e20ee566a729.png)
![example_matrix_ttgo](https://user-images.githubusercontent.com/4552572/138756428-43d786c5-0d22-42ad-aecd-2dd7b31ed488.png)

[![AuroraDrop](http://img.youtube.com/vi/6lSb6BLZaRQ/0.jpg)](http://www.youtube.com/watch?v=6lSb6BLZaRQ "AuroraDrop 0.0.3")

https://youtu.be/6lSb6BLZaRQ


[![AuroraDrop](http://img.youtube.com/vi/wxiZug6A2b8/0.jpg)](http://www.youtube.com/watch?v=wxiZug6A2b8 "AuroraDrop 0.0.12")

https://youtu.be/wxiZug6A2b8


## Example Visualisations

![bitmap1](https://user-images.githubusercontent.com/4552572/137008263-2cd191cb-fc51-445f-8496-6b9dbc1141d4.png) ![bitmap2](https://user-images.githubusercontent.com/4552572/137008280-2f5a7f18-abf7-4f87-937f-abaded38be8e.png) ![bitmap3](https://user-images.githubusercontent.com/4552572/137008303-60a0098d-e878-4fbd-9695-de55e5871269.png) ![bitmap4b](https://user-images.githubusercontent.com/4552572/137008672-e3eb3f7c-4648-4aa2-9c18-655a2434ecf0.png) ![bitmap5](https://user-images.githubusercontent.com/4552572/137008329-1d3b0771-f201-4ce3-95eb-2ec01f6bdd49.png) ![bitmap6](https://user-images.githubusercontent.com/4552572/137008351-81d03100-3593-4c5c-9b21-47538324329a.png) ![bitmap7](https://user-images.githubusercontent.com/4552572/137008366-5f6928c5-a48a-4004-a101-cd3d620e5407.png) ![bitmap8](https://user-images.githubusercontent.com/4552572/137008378-f9b676e0-64e0-4fb9-9871-30986dce088b.png) ![bitmap9](https://user-images.githubusercontent.com/4552572/137008395-985d0761-5988-4116-b357-d0211af1e97c.png) ![bitmap10](https://user-images.githubusercontent.com/4552572/137008412-79c7ce00-66a7-4961-95a7-424caecddbec.png) ![bitmap11](https://user-images.githubusercontent.com/4552572/137008425-967617eb-f75f-4568-bb84-c1349df86457.png)
![bitmap12](https://user-images.githubusercontent.com/4552572/137008461-89f3ff07-3f4a-471f-a605-05168c0964dd.png) 


## Web Interface

![web_bitmap1](https://user-images.githubusercontent.com/4552572/137007058-e84c9805-5442-4d5b-83c0-64f012611f9f.png)

![web_bitmap3](https://user-images.githubusercontent.com/4552572/137807502-aee10806-0850-44fd-ae82-9f524399069c.png)



## Latest Updates

0.0.14
* Added support for 320x240 eSPI TFT displays
* Tisy up.
* Fixed some bugs.

0.0.13
* Added support for TTGO-WATCH (You'll need to uncomment pertinent line in code for your hardware and use WiFi TCP comms)
* Revised serial interface comms. Requires update of the companion application.
* Removed UDP support.
* Added TCP support. Requires update of the companion application. (You'll need to uncomment pertinent line in code)
* Added some plasma style effects and others.
* Added Lian-Li SL120 effect option.
* Added some bugs and left a lot of mess about.

0.0.12
* Added support for TTGO-TFT Dev boards. (You'll need to uncomment pertinent line in code for your hardware)
* Some speed improvements.
* Fixed some bugs.

0.0.11
* Added web server option to select the number of concurrent patterns running.
* Option to check for new git updates.
* Fixed some bugs.
* Added some new bugs and patterns.

0.0.10
* Added some more patterns from the AuroraDemo.
* Fixed some bugs.

0.0.9
* Experimental support for LED strip matrix (tested with 16x16).
* Enable and disable individual effects from web interface.
* Option to use rendered output as web server favicon.
* Tweaks to test patterns.
* General tidy.

0.0.8
* View/download visualisation renders from web interface.
* FFT datagram now 128 bytes long. (update your companion applicaction)

0.0.7
* Tweaks to test patterns.
* General tidy.

0.0.6
* Fixed bug with delay in serial comms.

0.0.5
* Experimental network streaming support (slow).
* Additional kalideoscope and effects patterns.
* New and tweaks to test patterns.

0.0.4
* Fixes
* Additions to testing web interface.
* Tweaks to test patterns.

0.0.3
* Added diagnostics.
* Added basic web server. (uncomment #define USE_WIFI in source code)
* Implemented fps capping.
* Tweaks to test patterns.


## Notes

AuroraDrop's audio visualisations currently only works when your ESP32 is connected to your PC via the USB connection, and you are running the companion windows application 'AuroraDrop Companion' (there is an WIP experimental network streaming mode). This application captures and processes the current audio playing on
your PC and passes this to the ESP32 via serial communications, which then renders the visualisations.

https://github.com/uklooney/AuroraDropCompanion

Tested on 64x64 1/32 scan LED Matrix


### Suggested Simple Hardware Solution
   
 * ESP32 I2S Matrix Shield (tested with v2.0.6)
 * https://github.com/witnessmenow/ESP32-i2s-Matrix-Shield
 * https://www.youtube.com/watch?v=ZiR93TmSyE0

Libraries needed:-

 * FastLED (tested with v3.4)
 * https://github.com/FastLED/FastLED

 * ESP32 HUB75 LED MATRIX PANEL DMA Display (tested with v2.0.5)
 * https://github.com/mrfaptastic/ESP32-HUB75-MatrixPanel-I2S-DMA

 * Adafruit GFX Library (tested with 1.10.12)
 * https://github.com/adafruit/Adafruit-GFX-Library

Optional WiFi libraries needed:-

*   https://github.com/me-no-dev/ESPAsyncWebServer/archive/master.zip
*   https://github.com/me-no-dev/AsyncTCP/archive/master.zip

*   These will need to be manually installed in your arduino libraries folder as they are not available via the arduino library manager.

Optional FFT libraries needed (experimental):-

*   ArduinoFFT  (tested with v1.5.6)
*   https://github.com/kosme/arduinoFFT

Optional TFT libraries for TTGO-T-Display

*  https://github.com/Xinyuan-LilyGO/TTGO-T-Display

### Library Dependancies

  *  ESP32-HUB75-LED-MatrixPanel-I2S-DMA by mrfaptastic- the library this project is designed to be used with. This is what interacts with the matrix panel. You can install this from the Arduino Library manager by searching for "ESP32 HUB75 LED MATRIX PANEL DMA Display"
  *  Adafruit GFX - is a dependacy of the matrix library. This can also be installed from the library manager by searching for "Adafruit GFX"
  *  FastLED by Damiel Garcia- Again you can use the library manager and search for "FastLED"
  *  Arduino FFT by Enrique Condes- This can also be installed from the library manager by searching for "arduinoFFT"
  *  TFT_eSPI by


### Based on

 Lots, including...

 * Aurora: https://github.com/pixelmatix/aurora
   * Copyright (c) 2014 Jason Coon

 * ESP32-HUB75-MatrixPanel-I2S-DMA and Examples: https://github.com/mrfaptastic/ESP32-HUB75-MatrixPanel-I2S-DMA
   * Copyright (c) 2021 mrfaptastic
 
 * Portions of this code are adapted from "Flocking" in "The Nature of Code" by Daniel Shiffman: http://natureofcode.com/
   * Copyright (c) 2014 Daniel Shiffman
   * http://www.shiffman.net

 * Portions of this code are adapted from "Funky Clouds" by Stefan Petrick: https://gist.github.com/anonymous/876f908333cd95315c35
 * Portions of this code are adapted from "NoiseSmearing" by Stefan Petrick: https://gist.github.com/StefanPetrick/9ee2f677dbff64e3ba7a
   * Copyright (c) 2014 Stefan Petrick
   * http://www.stefan-petrick.de/wordpress_beta

 * Portions of this code are adapted from Noel Bundy's work: https://github.com/TwystNeko/Object3d
   * Copyright (c) 2014 Noel Bundy
 
 * Portions of this code are adapted from the Petty library: https://code.google.com/p/peggy/
   * Copyright (c) 2008 Windell H Oskay.  All right reserved.

 * Portions of this code are adapted from SmartMatrixSwirl by Mark Kriegsman: https://gist.github.com/kriegsman/5adca44e14ad025e6d3b
   * https://www.youtube.com/watch?v=bsGBT-50cts
   * Copyright (c) 2014 Mark Kriegsman

 * Portions of this code are adapted from LedEffects Plasma by Robert Atkins:
   * https://bitbucket.org/ratkins/ledeffects/src/26ed3c51912af6fac5f1304629c7b4ab7ac8ca4b/Plasma.cpp?at=default
   * Copyright (c) 2013 Robert Atkins

 * Portions of this code are adapted from Random Nerd Tutorials:
   * https://randomnerdtutorials.com/esp32-async-web-server-espasyncwebserver-library/
