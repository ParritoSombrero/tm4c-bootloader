#include "bootloader.h"
#include "uart.h"
#include "gpio.h"
#include "commands.h"
#define APPLICATION_START 0x00008000
#define VTOR (*(volatile uint32_t *)0xE000ED08)

int index = 0;

void enterFlasherMode() {
    uart_init();
    redLEDtoggle();
    uart_out("\x1B[2J\x1B[H");
    uart_out("FLASH MODE\r\n");
    while(1) {
        char c = uart_getc();
        uart_putc(c);

        if (c == 127) {
            if (index > 0) {
                index--;
            }
        } else if (c == '\r') {
            uart_out("\r\n");
            buffer[index] = '\0';
            handle_command(buffer);
            index = 0;
        } else {
            if (index < sizeof(buffer) - 1) {
                buffer[index++] = c;
            }
        }
    }
}

static inline void setMSP(uint32_t value) {
    __asm("    cpsid i");
    __asm(" MSR MSP, R0");
}

void jumpToApplication(void) {
    uint32_t appStack = *(uint32_t *)APPLICATION_START;
    uint32_t appReset = *(uint32_t *)(APPLICATION_START + 4);

    setMSP(appStack);

    void (*appEntry)(void) = (void (*)(void))appReset;

    VTOR = APPLICATION_START;

    appEntry();
}
