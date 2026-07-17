#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

#define SYSCTL_RCGCGPIO_R (*((volatile uint32_t*)0x400FE608))
#define GPIO_PORTA_BASE 0x40004000
#define GPIO_PORTF_BASE 0x40025000

#define GPIO_DEN (*((volatile uint32_t*)(GPIO_PORTA_BASE + 0x51C)))
#define GPIO_AFSEL (*((volatile uint32_t*)(GPIO_PORTA_BASE + 0x420)))
#define GPIO_PCTL (*((volatile uint32_t*)(GPIO_PORTA_BASE + 0x52C)))
#define GPIOF_DEN (*((volatile uint32_t*)(GPIO_PORTF_BASE + 0x51C)))
#define GPIOF_DIR (*((volatile uint32_t*)(GPIO_PORTF_BASE + 0x400)))
#define GPIOF_DATA (*((volatile uint32_t*)(GPIO_PORTF_BASE + 0x3FC)))
#define GPIOF_PUR (*((volatile uint32_t*)(GPIO_PORTF_BASE + 0x510)))

void gpio_init(void);
void redLEDtoggle(void);
void redLEDon(void);
void redLEDoff(void);
void greenLEDtoggle(void);
void greenLEDon(void);
void greenLEDoff(void);
void blueLEDtoggle(void);
void blueLEDon(void);
void blueLEDoff(void);
bool buttonCheck(void);

#endif
