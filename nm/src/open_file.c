/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
** File description:
** open_file
*/

#include "nm.h"

bool open_file(const char *str)
{
    int fd;
    void *buf;
    struct stat s;
    Elf64_Ehdr *elf;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return false;
    fstat(fd, &s);
    buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
        perror("mmap");
        return false;
    }
    elf = (Elf64_Ehdr *) buf;
    if (elf->e_type != ET_REL && elf->e_type != ET_EXEC && elf->e_type != ET_DYN)
        return false;
    

    Elf64_Shdr *shdr = (Elf64_Shdr *) (buf + elf->e_shoff);
    (void) shdr;

    printf("%u\n", elf->e_shnum);
    printf("%u\n", elf->e_shentsize);


    close(fd);

    return true;
}
