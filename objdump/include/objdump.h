/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** objdump
*/

#pragma once

#include "commons.h"


/* File format for 32 bits architecture. */
#define FORMAT_32 "elf32-i386"
/* File format for 64 bits architecture. */
#define FORMAT_64 "elf64-x86-64"

/* 32 bits architecture name. */
#define ARCHI_32 "i386"
/* 64 bits architecture name. */
#define ARCHI_64 "i386:x86-64"

/* The lowest printable character. */
#define LOW_PRINT_CHAR ' '
/* The highest printable character. */
#define HIGH_PRINT_CHAR '~'

/* Placeholder used when printing non printable character. */
#define NO_PRINT_PLACEHOLDER '.'


/**
 * @brief Process a file to get its content.
 *
 * @param bin Name of the current program binary.
 * @param path Path of the processed file.
 * @return `true` if the function has been executed without error.
 * @return `false` if an error occurred.
 */
bool process_file(const char *bin, const char *path);


/**
 * @brief Print the objdump header.
 *
 * @param file Structure containing data from the processed file.
 * @param path Path of the processed file.
 */
void print_header(file_t *file, const char *path);

/**
 * @brief Print informations from file sections.
 *
 * @param file Structure containing data from the processed file.
 */
void print_sections(file_t *file);
