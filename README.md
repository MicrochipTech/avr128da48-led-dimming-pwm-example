# AVR128DA48 LED Dimming with PWM Example

This repository provides an Atmel Studio solution with a bare metal code example for an LED dimming implemented using a PWM signal. 

The example demonstrates the basic functionality of the PWM peripheral. The output waveform is connected to the on-board LED. The PWM duty cycle value is incremented continuously until it reaches the maximum value and then is reloaded to 0. This produces the dimming effect of the LED.

## Configurations

* PC6 - configured as digital output (the on-board user LED)
* TCA1:
  * Single-slope PWM Mode
  * Compare channel 2 enabled
  * Input clock 4Mhz


## Required Tools 

Software: ATMEL Studio and AVR-DA Device Packs

Hardware: AVR128DA48 Curiosity Nano


## Compatibility
The source code is compatible with the following devices: AVR128DA28, AVR128DA32, AVR128DA48, AVR128DA64, ATmega4808, ATmega3208, ATmega1608, ATmega808, ATmega4809, ATmega3209, ATmega1609, ATmega809.
