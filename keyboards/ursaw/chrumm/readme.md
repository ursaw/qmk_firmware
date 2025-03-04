# Chrumm

![Chrumm](https://i.imgur.com/n57bTEEh.jpg)

An open-hardware ergonomic monoblock. Made of a 3D-printed body and Raspberry Pi Pico powered PCB, with 64 soldered MX switches and a central rotary encoder.

* Keyboard Maintainer: [Severin Meyer](https://github.com/sevmeyer)
* Hardware Supported: Chrumm PCB, Raspberry Pi Pico
* Hardware Availability: [GitHub](https://github.com/sevmeyer/chrumm-keyboard)

Make example for this keyboard (after setting up your build environment):

    make chrumm:default

Flashing example for this keyboard:

    make chrumm:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Physical reset button**: Hold down the `BOOTSEL` button on the Raspberry Pi Pico and plug in the keyboard
* **Bootmagic reset**: Hold down the top left key (usually Escape) and plug in the keyboard
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
