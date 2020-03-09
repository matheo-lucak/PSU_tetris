/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <stddef.h>

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
    unsigned int options : 2;
    vector2i_t map_size;
    char control_keys[3];
    char option_keys[3];
} option_t;


#endif /* !TETRIS_H_ */