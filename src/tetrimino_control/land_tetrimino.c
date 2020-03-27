/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** land_tetrimino
*/

#include "my.h"
#include "tetris.h"

static size_t tetrimino_get_bottom_line(tetrimino_t *queue)
{
    register size_t index = 0;
    size_t bottom_line = 0;

    if (!queue)
        return (bottom_line);
    for (index = 0; index < (size_t)queue->alloc_size; index += 1) {
        if (queue->shapes[queue->rotation][index] &&
            find_char(queue->shapes[queue->rotation][index], '*') == -1)
            bottom_line = index;
    }
    if (!bottom_line && index > 0)
        return (index - 1);
    return (bottom_line);
}

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
    register size_t y = tetrimino_get_bottom_line(*queue);
    register ssize_t x = 0;
    pos_t pos = game_data->cursor;

    for (x = 0; x < (*queue)->alloc_size; x += 1) {
        if ((*queue)->shapes[(*queue)->rotation][y][x] == '*' &&
            (game_data->board[pos.y + y + 1][pos.x + x].cell == '*' ||
            pos.y + y > options.map_size.height - 1)) {
            write_tetrimino_in_board(game_data, *queue);
            dequeue_tetrimino(queue);
            game_data->cursor.y = 0;
            return (false);
            }
    }
    game_data->cursor.y += 1;
    return (true);
}