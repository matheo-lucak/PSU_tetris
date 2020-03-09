/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_option
*/

#ifndef SET_OPTION_H_
#define SET_OPTION_H_

#include "tetris.h"

bolean_t set_control_key(option_t *options, char option, char *arg);
bolean_t set_option_key(option_t *options, char option, char *arg);
bolean_t set_level(option_t *options, char option, char *arg);
bolean_t set_map_size(option_t *options, char option, char *arg);
bolean_t set_game_option(option_t *options, char option, char *arg);

static bolean_t (*set_option_func[])(option_t *, char , char *) = {
    set_level,
    set_control_key,
    set_control_key,
    set_control_key,
    set_control_key,
    set_option_key,
    set_option_key,
    set_map_size,
    set_game_option,
    set_game_option,
    NULL
};

static struct option const option_template[11] = {
    {.name = "level=", .has_arg = 1, NULL, 'L'},
    {.name = "key-left=", .has_arg = 1, NULL, 'l'},
    {.name = "key-right=", .has_arg = 1, NULL, 'r'},
    {.name = "key-turn=", .has_arg = 1, NULL, 't'},
    {.name = "key-drop=", .has_arg = 1, NULL, 'd'},
    {.name = "key-quit=", .has_arg = 1, NULL, 'q'},
    {.name = "key-pause=", .has_arg = 1, NULL, 'p'},
    {.name = "map-size=", .has_arg = 1, NULL, 's'},
    {.name = "without-next", .has_arg = 0, NULL, 'w'},
    {.name = "debug", .has_arg = 0, NULL, 'D'},
    {.name = NULL, .has_arg = 0, NULL, 0}
};

#endif /* !SET_OPTION_H_ */