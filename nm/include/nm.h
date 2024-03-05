/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** nm
*/

#pragma once

#include <elf.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

#define NO_FILE 0
#define IS_DIR 1
#define WG_FILE 2

typedef struct file_s {
    int fd;
    long size;
    void *buf;
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
} file_t;

typedef struct symbols_s {
    unsigned long addr;
    char type;
    char *name;
    struct symbols_s *next;
} symbols_t;

bool process_file(file_t *file, const char *path, bool are_mult_files);
bool open_file(file_t *file, const char *path);
bool close_file(int fd);
void print_error(unsigned flag, const char *str);
bool get_file_content(file_t *file, const char *path);
symbols_t *add_element(symbols_t **symbols);
void free_list(symbols_t **symbols);
void sort_list(symbols_t **symbols);
void get_symbols(file_t *file, symbols_t **symbols);
char get_type(Elf64_Sym *sym, unsigned sh_type, unsigned long sh_flags);
bool is_char_uppercase(char c);
char char_to_uppercase(char c);
void print_symbols(symbols_t **symbols, const char *path, bool are_mult_files);
