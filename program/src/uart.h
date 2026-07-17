#ifndef UART_H
#define UART_H

#include <stdint.h>

#define SYSCTL_RCGCUART_R (*((volatile uint32_t*)0x400FE618))

#define UART0_BASE 0x4000C000

#define UART0_DR_R (*((volatile uint32_t*)(UART0_BASE + 0x000)))
#define UART0_FR_R (*((volatile uint32_t*)(UART0_BASE + 0x018)))
#define UART0_IBRD_R (*((volatile uint32_t*)(UART0_BASE + 0x024)))
#define UART0_FBRD_R (*((volatile uint32_t*)(UART0_BASE + 0x028)))
#define UART0_LCRH_R (*((volatile uint32_t*)(UART0_BASE + 0x02C)))
#define UART0_CTL_R (*((volatile uint32_t*)(UART0_BASE + 0x030)))

void uart_init(void);
void uart_out(const char *s);
char uart_getc(void);
void uart_putc(char c);

#endif
