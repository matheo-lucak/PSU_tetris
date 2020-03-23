/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_game_board
*/

#include "stdlib.h"
#include "my.h"
#include "tetris.h"

static void fill_board_line(char **board, size_t index, dimensions_t map_size)
{
    if (!board || !(board[index]))
        return ;
    my_memset(board[index], ' ', map_size.width);
    if (index == 0 || index == map_size.height - 1)
        my_memset(board[index], '*', map_size.width);
    board[index][0] = '*';
    board[index][map_size.width - 1] = '*';
    board[index][map_size.width] = '\0';
}

static void fill_board_edge(char **board, dimensions_t map_size)
{
    board[0][0] = '/';
    board[0][0] = '/';
    board[map_size.height - 1][map_size.width - 1] = '/';
    board[map_size.height - 1][0] = '\\';
    board[0][map_size.width - 1] = '\\';
}

char **create_board(option_t options)
{
    char **board = NULL;
    register size_t index = 0;

    board = malloc(sizeof(char *) * (options.map_size.height + 1));
    if (!board)
        return (NULL);
    while (index < options.map_size.height) {
        board[index] = malloc(sizeof(char) * (options.map_size.width + 1));
        if (!(board[index]))
            return (NULL);
        fill_board_line(board, index, options.map_size);
        index += 1;
    }
    fill_board_edge(board, options.map_size);
    board[options.map_size.height] = NULL;
    return (board);
}