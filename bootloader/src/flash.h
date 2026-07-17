#ifndef FLASH_H
#define FLASH_H

#include <stdint.h>
#include <stdbool.h>

// To program a 32-bit word
// 1. Write source data to the FMD register.
// 2. Write the target address to the FMA register.
// 3. Write the Flash memory write key and the WRITE bit to the FMC register. Depending on the
// value of the KEY bit in the BOOTCFG register, the value 0xA442 or 0x71D5 must be written
// into the WRKEY field for a Flash memory write to occur.
// 4. Poll the FMC register until the WRITE bit is cleared.


#define FLASH_BASE 0x400FD000
#define FLASH_FMD (*((volatile uint32_t*)(FLASH_BASE + 0x004)))
#define FLASH_FMA (*((volatile uint32_t*)(FLASH_BASE + 0x000)))
#define FLASH_FMC (*((volatile uint32_t*)(FLASH_BASE + 0x008)))

void flashAddress(uint32_t address, uint32_t data);
bool verifyAddress (uint32_t address, uint32_t data);
void eraseAddress(uint32_t address);
void flashBufferAddress(uint32_t address, const uint32_t *buffer, uint32_t data);
bool verifyBufferAddress(uint32_t address, const uint32_t *buffer, uint32_t words);
uint32_t readAddress(uint32_t address);

#endif 
