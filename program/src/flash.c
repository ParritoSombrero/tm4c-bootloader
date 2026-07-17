#include "flash.h"

// To program a 32-bit word
// 1. Write source data to the FMD register.
// 2. Write the target address to the FMA register.
// 3. Write the Flash memory write key and the WRITE bit to the FMC register. Depending on the
// value of the KEY bit in the BOOTCFG register, the value 0xA442 or 0x71D5 must be written
// into the WRKEY field for a Flash memory write to occur.
// 4. Poll the FMC register until the WRITE bit is cleared.

// To perform an erase of a 1-KB page
// 1. Write the page address to the FMA register.
// 2. Write the Flash memory write key and the ERASE bit to the FMC register. Depending on the
// value of the KEY bit in the BOOTCFG register, the value 0xA442 or 0x71D5 must be written
// into the WRKEY field for a Flash memory write to occur.
// 3. Poll the FMC register until the ERASE bit is cleared o

void flashAddress(uint32_t address, uint32_t data) {
    FLASH_FMD = data;
    FLASH_FMA = address;
    FLASH_FMC = (0xA442 << 16) | 0x1;

    while (FLASH_FMC & 0x01) {
        
    }
}

void eraseAddress(uint32_t address) {
    FLASH_FMA = address;
    FLASH_FMC = (0xA442 << 16) | 0x2;

    while (FLASH_FMC & 0x02) {
        
    }
}

bool verifyAddress(uint32_t address, uint32_t data) {
    return (*(volatile uint32_t *)address == data);
}


void flashBufferAddress(uint32_t address, const uint32_t *buffer, uint32_t words) {
    for (uint32_t i = 0; i < words; i++) {
        flashAddress(address + i * 4, buffer[i]);
    }
}

bool verifyBufferAddress(uint32_t address, const uint32_t *buffer, uint32_t words) {
    for (uint32_t i = 0; i < words; i++) {
        if (!verifyAddress(address + i * 4, buffer[i])) {
            return false;
        }
    }
    return true;
}

uint32_t readAddress(uint32_t address) {
    return *(volatile uint32_t *)address;
}
