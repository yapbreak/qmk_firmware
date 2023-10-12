#!/usr/bin/env bash


qmk config user.keyboard=ktec/ergodone
qmk config user.keymap=yapbreak
qmk clean
qmk compile
if [ ! -f ../tkgtoolkit/linux/bin/hid_bootloader_cli ]; then
    git clone https://github.com/kairyu/tkg-toolkit.git ../tkg-toolkit
fi
sudo ../tkg-toolkit/linux/bin/hid_bootloader_cli -W -v -mmcu=atmega32u4 ./ktec_ergodone_yapbreak.hex
