/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** nm
*/

#pragma once

#include "commons.h"


/* Structure containing symbols data from a file. */
typedef struct symbols_s {
    unsigned long addr;
    char type;
    char *name;
    struct symbols_s *next;
} symbols_t;


/**
 * @brief Process a file to get its symbols and print them.
 *
 * @param file Structure containing data about the processed file.
 * @param bin Name of the current program binary.
 * @param path Path of the processed file.
 * @param are_mult_files Boolean specifying if multiple files are
 * processed. `true` if there are multiple files and `false` otherwise.
 * @return `true` if the function has been executed without error.
 * @return `false` if an error occurred.
 */
bool process_file(file_t *file, const char *bin, const char *path,
    bool are_mult_files);

/**
 * @brief Print all the non empty symbols in a
 * `symbols_t` linked list with their address and type.
 *
 * @param symbols Structure containing all symbols of a file.
 * @param bin Name of the current program binary.
 * @param path Path of the processed file.
 * @param are_mult_files Boolean specifying if multiple files are
 * processed. `true` if there are multiple files and `false` otherwise.
 */
void print_symbols(symbols_t **symbols, const char *bin, const char *path,
    bool are_mult_files);


/**
 * @brief Get all symbols in a file.
 *
 * @param file Structure containing data from a file.
 * @param symbols Pointer on the first element of a linked list of `symbols_t`.
 */
void get_symbols(file_t *file, symbols_t **symbols);

/**
 * @brief Get the type of symbol.
 *
 * @param sym Structure containing data from a symbol.
 * @param sh_type Type of the section containing the symbol.
 * @param sh_flags Flags of the section containing the symbol.
 * @return Character representing the type of the symbol.
 */
char get_type(Elf64_Sym *sym, unsigned sh_type, unsigned long sh_flags);


/**
 * @brief Add an element at the end of a linked list of `symbols_t`.
 *
 * @param symbols Pointer on the first element of a
 * linked list or pointer on `NULL` if the list is empty.
 * @return Pointer on the added element.
 */
symbols_t *add_element(symbols_t **symbols);

/**
 * @brief Free a linked list of `symbols_t`.
 *
 * @param symbols Pointer on the first element of a linked list.
 */
void free_list(symbols_t **symbols);

/**
 * @brief Sort a linked list of `symbols_t` by name in ASCII order.
 *
 * @param symbols Pointer on the first element of a linked list.
 */
void sort_list(symbols_t **symbols);
