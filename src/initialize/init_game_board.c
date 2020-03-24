/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_game_board
*/

#include "stdlib.h"
#include "my.h"
#include "tetris.h"
#include "tetris_cell_template.h"

static void fill_board_line(cell_t **board, size_t index, dimensions_t map_size)
{
    register unsigned int tmp_index = 0;

    if (!board || !(board[index]))
        return ;
    for (tmp_index = 0; tmp_index < map_size.width + 1; tmp_index += 1)
        my_memcpy(board[index] + tmp_index, &empty_cell, sizeof(cell_t));
    if (index == 0 || index == map_size.height + 1) {
        for (tmp_index = 0; tmp_index < map_size.width + 1; tmp_index += 1)
            my_memcpy(board[index] + tmp_index, &topbot_cell, sizeof(cell_t));
    }
    my_memcpy(board[index], &side_cell, sizeof(cell_t));
    my_memcpy(board[index] + map_size.width + 1, &side_cell, sizeof(cell_t));
    my_memcpy(board[index] + map_size.width + 2, &null_cell, sizeof(cell_t));
}

static void fill_board_edge(cell_t **board, dimensions_t map_size)
{
    my_memcpy(board[0], &nwse_cell, sizeof(cell_t));
    my_memcpy(board[map_size.height + 1] + map_size.width + 1, &nwse_cell,
                                                            sizeof(cell_t));
    my_memcpy(board[map_size.height + 1], &nesw_cell, sizeof(cell_t));
    my_memcpy(board[0] + map_size.width + 1, &nesw_cell, sizeof(cell_t));
}

cell_t **create_board(option_t options)
{
    cell_t **board = NULL;
    register size_t index = 0;

    board = malloc(sizeof(cell_t *) * (options.map_size.height + 3));
    if (!board)
        return (NULL);
    while (index < options.map_size.height + 2) {
        board[index] = malloc(sizeof(cell_t) * (options.map_size.width + 3));
        if (!(board[index]))
            return (NULL);
        fill_board_line(board, index, options.map_size);
        index += 1;
    }
    fill_board_edge(board, options.map_size);
    board[options.map_size.height + 2] = NULL;
    return (board);
}