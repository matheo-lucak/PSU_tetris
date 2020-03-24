/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_board
*/

#include "my.h"
#include "tetris.h"

static inline dimensions_t compute_board_position(option_t options)
{
    dimensions_t win_dim = {getmaxx(stdscr), getmaxy(stdscr)};

    return ((dimensions_t){(win_dim.width / 2) - (options.map_size.width / 2),
                        (win_dim.height / 2) - (options.map_size.height / 2)});
}

static inline void display_cell(cell_t cell, int x, int y)
{
    init_pair(1, cell.color, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvaddch(y, x, cell.cell);
    attroff(COLOR_PAIR(1));
}

void display_board(game_data_t *game_data, option_t options)
{
    register size_t x = 0;
    register size_t y = 0;
    dimensions_t board_pos = compute_board_position(options);

    for (y = 0; y < options.map_size.height + 2; y += 1) {
        for (x = 0; x < options.map_size.width + 2; x += 1) {
            display_cell(game_data->board[y][x],
                        board_pos.width + x, board_pos.height + y);
        }
    }
}