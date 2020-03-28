/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** land_tetrimino
*/

#include "my.h"
#include "tetris.h"

static void write_tetrimino_in_board(game_data_t *game_data, tetrimino_t *queue)
{
    pos_t pos = game_data->cursor;
    register size_t y = 0;
    register size_t x = 0;

    for (y = 0; y < (size_t)queue->alloc_size; y += 1) {
        for (x = 0; x < (size_t)queue->alloc_size; x += 1) {
            if (queue->shapes[queue->rotation][y][x] == '*') {
                game_data->board[pos.y + y][pos.x + x].cell = '*';
                game_data->board[pos.y + y][pos.x + x].color = queue->color;
            }
        }
    }
}

bool land_tetrimino(game_data_t *game_data, tetrimino_t **queue,
                                                option_t options)
{
    pos_t pos = game_data->cursor;

    if (tetrimino_collide(game_data, options,
                            (*queue)->shapes[(*queue)->rotation],
                            (pos_t){pos.x, pos.y + 1})) {
        write_tetrimino_in_board(game_data, *queue);
        dequeue_tetrimino(queue);
        game_data->cursor.y = 0;
        return (false);
    }
    game_data->cursor.y += 1;
    return (true);
}