/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetris_special_keys.h
*/

#ifndef TETRIS_SPECIAL_KEYS_H_

#define TETRIS_SPECIAL_KEYS_H_

#include <stddef.h>
#include <ncurses.h>

struct special_key {
    size_t itteration;
    int character;
    char *to_print;
};

static struct special_key const special_keys[6] = {
    {.itteration = 0, .character = ' ', .to_print = "(space)\n"},
    {.itteration = 1, .character = KEY_LEFT, .to_print = "^EOD\n"},
    {.itteration = 2, .character = KEY_RIGHT, .to_print = "^EOC\n"},
    {.itteration = 3, .character = KEY_UP, .to_print = "^EOA\n"},
    {.itteration = 4, .character = KEY_DOWN, .to_print = "^EOB\n"},
    {.itteration = 5, .character = -1, .to_print = NULL},
};

#endif /* TETRIS_SPECIAL_KEYS_H_ */