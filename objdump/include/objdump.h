/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** objdump
*/

#pragma once

#include "commons.h"


#define FORMAT_32 "elf32-i386"
#define FORMAT_64 "elf64-x86-64"

#define ARCHI_32 "i386"
#define ARCHI_64 "i386:x86-64"


/**
 * @brief Process a file to get its content.
 *
 * @param bin Name of the current program binary.
 * @param path Path of the processed file.
 * @return `true` if the function has been executed without error.
 * @return `false` if an error occurred.
 */
bool process_file(const char *bin, const char *path);


void print_header(file_t *file, const char *path);

void print_section(file_t *file);
