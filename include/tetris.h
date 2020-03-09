/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <stddef.h>

typedef enum bolean_e
{
    FALSE,
    TRUE
} bolean_t;

//Defines the position of a 2d int vector.
typedef struct vector2i_s {
    long int x;
    long int y;
} vector2i_t;

//Defines the boundaries of a component.
typedef struct dimensions_s {
    size_t width;
    size_t height;
} dimensions_t;

//A tetrimino characteristics.
typedef struct tetrimino_s {
    char *name;
    dimensions_t dims;
    size_t color;
    struct tetrimino_s *next;
} tetrimino_t;

//Enum for the chosen gamemode.
typedef enum option_flag_e {
    DEBUG = 1,
    NEXT = 2
} option_flag_t;

typedef struct option_s {
    unsigned int level;
    unsigned int game_option : 2;
    vector2i_t map_size;
    char control_keys[4];
    char option_keys[2];
} option_t;

bolean_t parse_option(const int ac, char * const av[], option_t *options);

#endif /* !TETRIS_H_ */