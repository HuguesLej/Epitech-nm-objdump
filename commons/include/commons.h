/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** commons
*/

#pragma once

#include <elf.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>


/* Flag used when provided path does not exist. */
#define NO_FILE 0
/* Flag used when provided path is a directory. */
#define IS_DIR 1
/* Flag used when provided path is a file with the wrong format. */
#define WG_FILE 2
/* Flag used when no symbols are found in a file. */
#define NO_SYM 3


/* Structure containing usefull data from a file. */
typedef struct file_s {
    int fd;
    long size;
    void *buf;
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
} file_t;


/**
 * @brief Open a file and verify its type.
 *
 * @param file Structure to fill with the
 * opened file descriptor and the file size.
 * @param bin Name of the current program binary.
 * @param path Path of a file.
 * @return `true` if the function is executed successfully.
 * @return `false` in case of error.
 */
bool open_file(file_t *file, const char *bin, const char *path);

/**
 * @brief Close an opened file descriptor.
 *
 * @param fd File descriptor to close.
 * @return `true` if the file descriptor is successfully closed.
 * @return `false` in case of error.
 */
bool close_file(int fd);

/**
 * @brief Get data from a file and set a `file_t` structure.
 *
 * @param file Structure to contain data from a file.
 * @param bin Name of the current program binary.
 * @param path Path of a file.
 * @return `true` if the data is successfully got.
 * @return `false` in case of error.
 */
bool get_file_content(file_t *file, const char *bin, const char *path);


/**
 * @brief Print an error depending on the provided flag.
 *
 * @param flag Flag specifying the error.
 * @param bin Name of the current program binary.
 * @param path Path to the file that caused the error. Can not be `NULL`.
 */
void print_error(unsigned flag, const char *bin, const char *path);

/**
 * @brief Verify if a character is an uppercase letter.
 *
 * @param c Character to verify.
 * @return `true` if the character is an uppercase letter.
 * @return `false` if the character is not an uppercase letter.
 */
bool is_char_uppercase(char c);

/**
 * @brief Convert a character to its uppercase version. The function
 * does not verify if the provided character is a letter or not.
 *
 * @param c Character to convert.
 * @return The character converted to uppercase.
 */
char char_to_uppercase(char c);
