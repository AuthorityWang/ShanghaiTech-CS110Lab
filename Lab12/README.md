## Burn the borad
In the terminal:

Boot0 - reset - reset - Boot0

make

sudo ./dfu-util -l | grep 28e9:0189

sudo ./dfu-util -a 0 --dfuse-address 0x08000000:leave -D .pio/build/sipeed-longan-nano/firmware.bin