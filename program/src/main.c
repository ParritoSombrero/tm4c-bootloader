#include "gpio.h"
#include <stdint.h>
#include "uart.h"
#include "commands.h"

#define APPLICATION_START 0x00008000

char buffer[10];

int main(void) {
    gpio_init();
    blueLEDon();
}
