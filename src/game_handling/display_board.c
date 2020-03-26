/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_board
*/

#include "my.h"
#include "tetris.h"

static inline void display_cell(cell_t cell, int x, int y)
{
    init_pair(cell.color, cell.color, COLOR_BLACK);
    attron(COLOR_PAIR(cell.color));
    mvaddch(y, x, cell.cell);
    attroff(COLOR_PAIR(cell.color));
    free_pair(cell.color);
}

void display_board(cell_t **board, dimensions_t size, pos_t pos)
{
    register size_t x = 0;
    register size_t y = 0;

    if (!board)
        return ;
    for (y = 0; y < size.height + 2; y += 1) {
        for (x = 0; x < size.width + 2; x += 1) {
            display_cell(board[y][x],
                        pos.x + x, pos.y + y);
        }
    }
}