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

typedef struct symbols_s {
    unsigned long addr;
    char type;
    char *name;
    symbols_t *prev;
    symbols_t *next;
} symbols_t;

typedef struct s_bounds_s {
    symbols_t *start;
    symbols_t *end;
} s_bounds_t;

bool open_file(const char *str);
