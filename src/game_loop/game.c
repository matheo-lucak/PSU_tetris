/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "tetris.h"
#include "tetris_board.h"

char **create_board(void)
{
    char **board = NULL;
    register size_t index = 0;

    board = malloc(sizeof(char *) * (my_arrlen((char **)tetris_board_template)));
    if (!board)
        return (NULL);
    while (tetris_board_template[index]) {
        board[index] = my_strdup(tetris_board_template[index]);
        if (!(board[index]))
            return (NULL);
        index += 1;
    }
    board[index] = NULL;
    return (board);
}

int game(option_t options, tetrimino_t **tetrimino_list)
{
    char **board = create_board();
    register size_t index = 0;

    if (!board)
        return (84);
    initscr();
    while (1) {
        while (board[index]) {
            printw(board[index]);
            index += 1;
        }
        refresh();
        index = 0;
    }
    endwin();
}