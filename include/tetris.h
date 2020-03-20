/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <stdbool.h>
#include <unistd.h>
#include <ncurses.h>

//Defines the boundaries of a component.
typedef struct dimensions_s {
    size_t width;
    size_t height;
} dimensions_t;

typedef enum shape_valid_e {
    VOID,
    CORRECT,
    INCORRECT
} shape_valid_t;

//A tetrimino characteristics.
typedef struct __attribute__((packed))tetrimino_s {
    char **shape;
    char *name;
    dimensions_t dims;
    ssize_t alloc_side;
    size_t color;
    bool error;
    struct tetrimino_s *next;
    struct tetrimino_s *prev;
} tetrimino_t;

//Enum for the chosen gamemode.
typedef enum option_flag_e {
    DEBUG = 1,
    NEXT = 2
} option_flag_t;

typedef struct __attribute__((packed))option_s {
    unsigned int level;
    unsigned int game_option : 2;
    dimensions_t map_size;
    int control_keys[4];
    int option_keys[2];
} option_t;


bool parse_option(const int ac, char * const av[], option_t *options);

/*
** ***********************
** | Tetriminos Handling |
** ***********************
*/

//Reads the "./tetriminos/" directory and checks all of the
//tetriminos properties.
//
//Fills the tetrimino_t simple linked list.
//
//Returns 1 if there's no issue.
//Returns 0 otherwise.
bool read_tetriminos_dir(tetrimino_t **head);

//Checks a tetrimino properties.
//
//Fills the tetrimino_t node.
//
//Returns 1 if there's no issue.
//Returns 0 otherwise.
void get_tetrimino(tetrimino_t *node, const char file_name[]);

//Free's allocated memory of a tetrimino list with memory checkers before
//freeing.
void free_tetriminos_list(tetrimino_t *head);

//Checks if a file_name as a certain given extension.
//
//Returns 1 if it has.
//Returns 0 otherwise.
bool file_extension_determ(const char file_name[], const char extension[]);

/*
** **************
** | Debug mode |
** **************
*/

size_t get_tetriminos_nb(tetrimino_t **head);

void print_prog_stats(tetrimino_t **tetrimino_list, const option_t options);


/*
** ******************
** | Main game Loop |
** ******************
*/

//Where the game starts looping.
//
//Returns 84 if an error occurs.
//Returns 0 otherwise.
int tetris(const int ac, char * const av[]);


#endif /* !TETRIS_H_ */