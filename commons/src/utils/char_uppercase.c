/*
** EPITECH PROJECT, 2024
** B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune [WSL: Ubuntu]
** File description:
** char_uppercase
*/

#include "commons.h"

bool is_char_uppercase(char c)
{
    if (c < 'A' || c > 'Z')
        return false;
    return true;
}

char char_to_uppercase(char c)
{
    char upper_c = c - 32;

    return upper_c;
}
