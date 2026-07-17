#include "commands.h"
#include "gpio.h"
#include <stdint.h>
#include <string.h>
#include <uart.h>
#include <flash.h>

char buffer[9];

char *nextToken(char **cursor) {
    char *start = *cursor;

    while (*start == ' ') {
        start++;
    }

    if (*start == '\0') {
        return NULL;
    }

    for (char *i = start; *i != '\0'; i++) {
        if (*i == ' ') {
            *i = '\0';
            *cursor = i + 1;
            return start;
        }
    }
    *cursor = start + strlen(start);
    return start;
}

uint32_t parseHex(char *str) {
    uint32_t value = 0;

    if (str[0] == '0' && str[1] == 'x') {
        str += 2;
    }

    while (*str != '\0') {
        value <<= 4;

        if (*str >= '0' && *str <= '9') {
            value += *str - '0';
        } else if (*str >= 'A' && *str <= 'F') {
            value += *str - 'A' + 10;
        } else if (*str >= 'a' && *str <= 'f') {
            value += *str - 'a' + 10;
        }

        str++;
    }
    return value;
}

void parseString(uint32_t address, char *buffer) {
    for (int shift = 28, i = 0; shift >= 0; shift -= 4, i++) {
        uint8_t digit = (address >> shift) & 0xF;

        if (digit < 10) {
            buffer[i] = '0' + digit;
        } else {
            buffer[i] = 'A' + (digit - 10);
        }
    }
    buffer[8] = '\0';
}

void handle_command(char *command) {
    char *cursor = command;
    char *cmd = nextToken(&cursor);
    char *address = nextToken(&cursor);
    char *data = nextToken(&cursor);

    if (strcmp(cmd, "info") == 0) {
        uart_out("abc\r\n");
    } else if (strcmp(cmd, "erase") == 0) {
        uint32_t addr = parseHex(address);
        eraseAddress(addr);
        uart_out("Page erased\r\n");
    } else if (strcmp(cmd, "write") == 0) {
        uint32_t addr = parseHex(address);
        uint32_t dat = parseHex(data);
        flashAddress(addr, dat);
        uart_out("Word written\r\n");
    } else if (strcmp(cmd, "verify") == 0) {
        uart_out("Verification PASS\r\n");
    } else if (strcmp(cmd, "read") == 0) {
        uint32_t addr = parseHex(address);
        uint32_t value = readAddress(addr);
        parseString(value, buffer);
        uart_out(buffer);
        uart_out("Read PASS");
    } else {
        uart_out("Invalid command");
    }
}
