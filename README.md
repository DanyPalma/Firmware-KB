## Firmware-KB

# Small Compilation of Firmware written for my keyboards
 - uses the QMK framework to operate on ATmega32U4 microcontrollers and more 

# current collection of dany's firmwares
 - sofle

### Requirements
 - [QMK MSYS](https://msys.qmk.fm/)
 - [QMK](https://qmk.fm/)

optional
 - [QMK Toolbox](https://github.com/qmk/qmk_toolbox)
 - [QMK config](config.qmk.fm) 

#### How to Flash
 1) Install both QMK MSYS and QMK
 2) Open QMK MSYS and run `qmk config`
 at this point, follow the ["creating your first firmware"](https://docs.qmk.fm/#/newbs) tutorial
 after writing corresponding firmware
 3) run `qmk compile -kb <keyboard> -km <keymap>` (-km indicates keymap, and -kb indicates keyboard.)

expected output:

```
Linking: .build/planck_rev5_default.elf                                                             [OK]
Creating load file for flashing: .build/planck_rev5_default.hex                                     [OK]
Copying planck_rev5_default.hex to qmk_firmware folder                                              [OK]
Checking file size of planck_rev5_default.hex                                                       [OK]
 * The firmware size is fine - 27312/28672 (95%, 1360 bytes free)
```
 4) Now we are going to flash our keyboard. 

 we need to go into DFU (bootloader) mode
 while it is in this mode you will not be able to type or otherwise use your keyboard. It is very important that you do not unplug the keyboard or otherwise interrupt the      flashing process while the firmware is being written.

 dfferent keyboards have different ways to enter this special mode. If your PCB currently runs QMK, TMK, or PS2AVRGB (Bootmapper Client) and you have not been given specific    instructions, try the following, in order:

Hold down both shift keys and press Pause
Hold down both shift keys and press B
Unplug your keyboard, hold down the Spacebar and B at the same time, plug in your keyboard and wait a second before releasing the keys
Unplug your keyboard, hold down the top or bottom left key (usually Escape or Left Control) and plug in your keyboard
Press the physical RESET button, usually located on the underside of the PCB
Locate header pins on the PCB labeled RESET and GND, and short them together while plugging your PCB in

If you’ve attempted all of the above to no avail, and the main chip on the board says STM32 on it, this may be a bit more complicated. Generally your best bet is to ask on [Discord](https://discord.com/invite/Uq7gcHh) for assistance. It’s likely some photos of the board will be asked for – if you can get them ready beforehand it’ll help move things along!

Otherwise, you should see a message in yellow, similar to this in QMK Toolbox:
```
*** DFU device connected: Atmel Corp. ATmega32U4 (03EB:2FF4:0000)
```
and this bootloader device will also be present in Device Manager, System Information.app, or lsusb.

at this point you can use [QMK Toolbox](https://docs.qmk.fm/#/newbs_flashing?id=load-the-file-into-qmk-toolbox) or [QMK MSYS](https://docs.qmk.fm/#/newbs_flashing?id=flash-your-keyboard-from-the-command-line) 

If using QMK MSYS you have to do the following
 -run `qmk flash` 
 -then run `qmk flash -kb <my_keyboard> -km <my_keymap>`

This will check the keyboard’s configuration, and then attempt to flash it based on the specified bootloader. This means that you don’t need to know which bootloader that your keyboard uses. Just run the command, and let the command do the heavy lifting.

However, this does rely on the bootloader being set by the keyboard. If this information is not configured, or you’re using a board that doesn’t have a supported target to flash it, you will see this error:

`WARNING: This board's bootloader is not specified or is not supported by the ":flash" target at this time.`

In this case, you’ll have to fall back on specifying the bootloader. See the [Flashing Firmware Guide](https://docs.qmk.fm/#/flashing) for more details.

With a little bit of luck everything will work perfectly, but if not there are steps that will help you figure out what’s wrong. Testing your keyboard is usually pretty straightforward. Press every single key and make sure it sends the keys you expect. You can use [QMK Configurator‘s test mode](https://config.qmk.fm/#/test/) to check your keyboard, even if it doesn’t run QMK.

Still not working? Browse the [FAQ topics](https://docs.qmk.fm/#/faq_general) for more information, or chat with us on [Discord.](https://discord.gg/Uq7gcHh)

# More Resources
- [QMK introduction](https://docs.qmk.fm/#/newbs)
- [QMK FAQs](https://docs.qmk.fm/#/faq_general)
- [QMK Configurator Overview](https://docs.qmk.fm/#/newbs_building_firmware_configurator)
- [QMK API Overview](https://docs.qmk.fm/#/api_overview)
- [QMK CLI Overview](https://docs.qmk.fm/#/cli)
- [QMK Use Guides](https://docs.qmk.fm/#/custom_quantum_functions)
- [QMK Development](https://docs.qmk.fm/#/pr_checklist)
