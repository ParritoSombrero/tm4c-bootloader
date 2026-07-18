# tm4c-bootloader
## overview
bare-metal bootloader that supports UART command parsing, flash operations, and handoff
## setup
this is meant for CCS, and assumes you have the other critical files like startup_ccs.c, you should probably just get a premade project and delete all c files
### bootloader project
1. paste all the files from /bootloader/src/ into the project
2. open hello_ccs.cmd or whatever your linker file is
3. edit APP_BASE to BOOT_BASE, change all references to APP_BASE to BOOT_BASE
4. confirm BOOT_BASE is set to 0x00000000, and it's length is 0x00008000
### application project
1. paste all the files from /program/src/ into the project
2. open hello_ccs.cmd or whatever your linker file is
3. edit APP_BASE to be set to 0x00008000
4. set length to 0x00032000
### UART
baud rate should be set to 115200
## features
-uart command parser
-flash programming
-flash erasing
-flash verification
-flasher mode
-handoff
## commands
to enter the mode that allows these commands, hold SW1 before booting
### info
currently useless, just prints out abc
### erase ADDRESS
erases the page
### write ADDRESS DATA
writes the data argument to the address
### verify
WIP
### read ADDRESS BUFFER
sends the content of address to the buffer, which is then printed through UART
