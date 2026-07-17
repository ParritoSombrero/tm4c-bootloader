#include <stdint.h>
#include <string.h>
#include "gpio.h"
#include "flash.h"
#include "uart.h"
#include "bootloader.h"

#define DEBUG 1

int main(void) {
    gpio_init();

    #if DEBUG
        uart_init();
        uart_out("\x1B[2J\x1B[H");
        uart_out("TM4C123GXL BOOTLOADER\r\n");
        uart_out("BETA VERSION\r\n");
        uart_out("DEBUG BUILD\r\n");
    #endif

    if (buttonCheck()) {
        enterFlasherMode();
    } else {
        greenLEDon();
        jumpToApplication();
    }
}
