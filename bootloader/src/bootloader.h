#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#include <stdint.h>
#include <stdbool.h>

char buffer[32];

void enterFlasherMode(void);
static inline void setMSP(uint32_t value);
void jumpToApplication(void);

#endif 
