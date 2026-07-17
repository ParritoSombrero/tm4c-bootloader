#ifndef COMMANDS_H
#define COMMANDS_H
#include <stdio.h>
#include <string.h>
#include <stdint.h>

char *nextToken(char **cursor);
void handle_command(char *cmd);
void parseString(uint32_t address, char *buffer);

#endif
