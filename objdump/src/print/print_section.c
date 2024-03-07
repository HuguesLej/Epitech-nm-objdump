/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** print_section
*/

#include "objdump.h"

static bool is_section_printable(const char *section_name, Elf64_Shdr *shdr)
{
    int cmp;

    cmp = strcmp(section_name, "");
    if (cmp == 0)
        return false;
    if (shdr->sh_type == SHT_SYMTAB)
            return false;
    if (shdr->sh_type == SHT_STRTAB && shdr->sh_flags != SHF_ALLOC)
            return false;
    if (shdr->sh_type == SHT_NOBITS)
            return false;
    return true;
}

static void print_chars_address(unsigned long remain_size)
{
    for (unsigned long i = 0; i < 16; i++) {
        if (i % 4 == 0)
            printf("%1s", "");
        if (i >= remain_size) {
            printf("%2s", "");
            continue;
        }
        printf("%02x", 0);
    }
}

static void print_chars(unsigned long remain_size)
{
    for (unsigned long j = 0; j < 16; j++) {
        if (j >= remain_size) {
            printf("%1s", "");
            continue;
        }
        printf("%c", '.');
    }
}

static void print_section_content(void *buf, Elf64_Shdr *shdr)
{
    unsigned long remain_size;

    (void) buf;
    for (unsigned long i = 0; i < shdr->sh_size; i += 16) {
        remain_size = shdr->sh_size - i;
        printf(" %04lx", (shdr->sh_addr + i));
        print_chars_address(remain_size);
        printf("%2s", "");
        print_chars(remain_size);
        printf("\n");
    }
}

void print_section(file_t *file)
{
    unsigned short shstrndx = file->ehdr->e_shstrndx;
    unsigned long shstr_offset = file->shdr[shstrndx].sh_offset;
    unsigned sh_name_idx;
    char *name;
    bool is_printable;

    for (unsigned short i = 0; i < file->ehdr->e_shnum; i++) {
        sh_name_idx = file->shdr[i].sh_name;
        name = &((char *)file->buf + shstr_offset)[sh_name_idx];
        is_printable = is_section_printable(name, &file->shdr[i]);
        if (!is_printable)
            continue;
        printf("Contents of section %s:\n", name);
        print_section_content(file->buf, &file->shdr[i]);
    }
}
