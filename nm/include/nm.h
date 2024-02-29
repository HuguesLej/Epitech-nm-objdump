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
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

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
    struct symbols_s *prev;
    struct symbols_s *next;
} symbols_t;

typedef struct s_bounds_s {
    symbols_t *start;
    symbols_t *end;
} s_bounds_t;

bool process_file(file_t *file, const char *path);
bool open_file(file_t *file, const char *path);
bool close_file(int fd);
void print_error(unsigned flag, const char *str);
bool get_file_content(file_t *file, const char *path);
