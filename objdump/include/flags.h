/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** flags
*/

#pragma once

/* No flags. */
#define BFD_NO_FLAGS    0x00
/* BFD contains relocation entries. */
#define HAS_RELOC       0x01
/* BFD is directly executable. */
#define EXEC_P          0x02
/* BFD has line number information (basically used for F_LNNO in a
   COFF header). */
#define HAS_LINENO      0x04
/* BFD has debugging information. */
#define HAS_DEBUG       0x08
/* BFD has symbols. */
#define HAS_SYMS        0x10
/* BFD has local symbols (basically used for F_LSYMS in a COFF
   header). */
#define HAS_LOCALS      0x20
/* BFD is a dynamic object. */
#define DYNAMIC         0x40
/* Text section is write protected (if D_PAGED is not set, this is
   like an a.out NMAGIC file) (the linker sets this by default, but
   clears it for -r or -N). */
#define WP_TEXT         0x80
/* BFD is dynamically paged (this is like an a.out ZMAGIC file) (the
   linker sets this by default, but clears it for -r or -n or -N). */
#define D_PAGED         0x100


typedef struct flags_s {
    unsigned int flag;
    char *name;
} flags_t;


const flags_t BFD_FLAGS[] = {
    {BFD_NO_FLAGS, "BFD_NO_FLAGS"},
    {HAS_RELOC, "HAS_RELOC"},
    {EXEC_P, "EXEC_P"},
    {HAS_LINENO, "HAS_LINENO"},
    {HAS_DEBUG, "HAS_DEBUG"},
    {HAS_SYMS, "HAS_SYMS"},
    {HAS_LOCALS, "HAS_LOCALS"},
    {DYNAMIC, "DYNAMIC"},
    {WP_TEXT, "WP_TEXT"},
    {D_PAGED, "D_PAGED"}
};
