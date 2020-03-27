/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** parse_input
*/

#include "tetris.h"

static void control_tetrimino(game_data_t *game_data, tetrimino_t *tetrimino,
                        option_t options, int key_code)
{
    if (key_code == KEY_CODE_LEFT || KEY_CODE_RIGHT)
        move_tetrimino(game_data, tetrimino, key_code);
    if (key_code == KEY_CODE_TURN)
        rotate_tetrimino(game_data, tetrimino);
}

static void control_game_event(game_data_t *game_data, option_t options,
                                                            int key_code)
{
    if (key_code == KEY_CODE_QUIT)
        game_data->quit = true;
    if (key_code == KEY_CODE_PAUSE) {
        while (getch() != options.option_keys[KEY_CODE_PAUSE]);
    }
}

void parse_input(game_data_t *game_data, tetrimino_t *tetrimino,
                                                option_t options)
{
    register size_t index = 0;
    int input = getch();


    for (index = 0; index < 4; index += 1) {
        if (input == options.control_keys[index])
            control_tetrimino(game_data, tetrimino, options, index);
    }
    for (index = 0; index < 2; index += 1) {
        if (input == options.control_keys[index])
            control_game_event(game_data, options, index);
    }
}