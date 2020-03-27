/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_interact
*/

#include "tetris.h"

static bool tetrimino_collide_cell(game_data_t *game_data, char **shape,
                                                pos_t pos, pos_t offset)
{
    if (game_data->board[pos.y + offset.y][pos.x + offset.x].cell == '*' &&
        shape[offset.y][offset.x] == '*')
        return (true);
    return (false);
}

bool tetrimino_collide(game_data_t *game_data, char **shape, pos_t pos)
{
    register size_t x = 0;
    register size_t y = 0;
    bool collide = false;

    for (y = 0; y != '\0' && !collide; y += 1) {
        for (x = 0; x != '\0' && !collide; x += 1) {
            collide = tetrimino_collide_cell(game_data, shape,
                                                pos, (pos_t){x, y});
        }
    }
    return (false);
}

void rotate_tetrimino(game_data_t *game_data, tetrimino_t *tetrimino)
{
    pos_t pos = game_data->cursor;

    if (!tetrimino_collide(game_data,
                            tetrimino->shapes[tetrimino->rotation + 1],
                                                                    pos))
        tetrimino->rotation += 1;
}

void move_tetrimino(game_data_t *game_data, tetrimino_t *tetrimino,
                                                        int key_code)
{
    pos_t pos = game_data->cursor;

    if (key_code == KEY_CODE_LEFT &&
        !tetrimino_collide(game_data, tetrimino->shapes[tetrimino->rotation],
                                                    (pos_t){pos.x - 1, pos.y}))
        game_data->cursor.x -= 1;
    if (key_code == KEY_CODE_RIGHT &&
        !tetrimino_collide(game_data, tetrimino->shapes[tetrimino->rotation],
                                                    (pos_t){pos.x + 1, pos.y}))
        game_data->cursor.x += 1;
}