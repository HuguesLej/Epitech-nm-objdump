/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** open_file
*/

#include "nm.h"

char choose_char(unsigned char type, unsigned char bind)
{
    unsigned char c;

    (void) type;
    (void) bind;

    switch (type) {
        case STT_NOTYPE:
            c = '?';
            break;
        default:
            c = ' ';
    }

    if (bind == STB_WEAK && c == '?')
        c = 'w';

    return c;
}

bool open_file(const char *str)
{
    int fd;
    void *buf;
    struct stat s;
    Elf64_Ehdr *ehdr;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return false;
    fstat(fd, &s);
    buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
        perror("mmap");
        return false;
    }
    ehdr = (Elf64_Ehdr *) buf;
    if (ehdr->e_type != ET_REL && ehdr->e_type != ET_EXEC && ehdr->e_type != ET_DYN)
        return false;


    Elf64_Shdr *shdr = (Elf64_Shdr *) (buf + ehdr->e_shoff);

    for (unsigned short i = 0; i < ehdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB) {
            Elf64_Sym *sym = (Elf64_Sym *) (buf + shdr[i].sh_offset);
            char *tab = (char *) (buf + shdr[shdr[i].sh_link].sh_offset);

            for (unsigned long j = 0; j < (shdr[i].sh_size / sizeof(Elf64_Sym)); j++) {
                if (sym[j].st_info != STT_FILE) {
                    printf("%016lx %c %u %s\n",
                    sym[j].st_value,
                    choose_char(ELF64_ST_TYPE(sym[j].st_info), ELF64_ST_BIND(sym[j].st_info)),
                    ELF64_ST_BIND(sym[j].st_info),
                    tab + sym[j].st_name);
                }
            }
        }
    }


    close(fd);

    return true;
}
