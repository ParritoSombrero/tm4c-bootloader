#include "gpio.h"

void gpio_init(void) {
    SYSCTL_RCGCGPIO_R |= (1 << 5) | (1 << 0);

    volatile int delay;
    for (delay = 0; delay < 1000; delay++) {}

    // port A
    GPIO_DEN |= (1 << 0) | (1 << 1);
    GPIO_AFSEL |= (1 << 0) | (1 << 1);
    GPIO_PCTL &= ~((0xF << 0) | (0xF << 4));
    GPIO_PCTL |= (0x1 << 0) | (0x1 << 4);

    // port F
    GPIOF_DEN |= (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);
    GPIOF_DIR |= (1 << 1) | (1 << 2) | (1 << 3);
    GPIOF_DIR &= ~(1 << 4);
    GPIOF_PUR |= (1 << 4);
}

// red LED

void redLEDtoggle(void) {
    GPIOF_DATA ^= (1 << 1);
}

void redLEDon(void) {
    GPIOF_DATA |= (1 << 1);
}

void redLEDoff(void) {
    GPIOF_DATA &= ~(1 << 1);
}


//  blue LED

void blueLEDtoggle(void) {
    GPIOF_DATA ^= (1 << 2);
}

void blueLEDon(void) {
    GPIOF_DATA |= (1 << 2);
}

void blueLEDoff(void) {
    GPIOF_DATA &= ~(1 << 2);
}


//  green LED

void greenLEDtoggle(void) {
    GPIOF_DATA ^= (1 << 3);
}

void greenLEDon(void) {
    GPIOF_DATA |= (1 << 3);
}

void greenLEDoff(void) {
    GPIOF_DATA &= ~(1 << 3);
}

// button

bool buttonCheck(void) {
    if ((GPIOF_DATA & (1 << 4)) == 0) {
        return true;
    } else {
        return false;
    }
}
