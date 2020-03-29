/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** land_tetrimino
*/

#include "my.h"
#include "tetris.h"

static void write_tetrimino_cell_in_board(game_data_t *game_data,
                                            tetrimino_t *queue,
                                            pos_t pos,
                                            pos_t offset)
{
    if (pos.y + offset.y < 1) {
        game_data->quit = true;
        return ;
    }
    if (queue->shapes[queue->rotation][offset.y][offset.x] == '*') {
        game_data->board[pos.y + offset.y][pos.x + offset.x].cell = '*';
        game_data->board[pos.y + offset.y][pos.x + offset.x].color =
                                                        queue->color;
    }
}

static void write_tetrimino_in_board(game_data_t *game_data, tetrimino_t *queue)
{
    pos_t pos = game_data->cursor;
    register size_t y = 0;
    register size_t x = 0;

    for (y = 0; y < (size_t)queue->alloc_size; y += 1) {
        for (x = 0; x < (size_t)queue->alloc_size; x += 1) {
            write_tetrimino_cell_in_board(game_data, queue, pos,
                                                    (pos_t){x, y});
        }
    }
}

static void update_new_cursor(game_data_t *game_data, option_t options,
                                                        tetrimino_t *queue)
{
    if (!queue) {
        game_data->cursor.y = 0;
        return ;
    }
    game_data->cursor.y = (queue->alloc_size * -1) + 1;
    if (game_data->cursor.x + queue->alloc_size - 1 > options.map_size.width) {
        game_data->cursor.x -= queue->alloc_size;
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
        update_new_cursor(game_data, options, *queue);
        return (false);
    }
    game_data->cursor.y += 1;
    return (true);
}