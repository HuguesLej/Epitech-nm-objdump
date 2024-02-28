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

bool open_file(const char *str);
