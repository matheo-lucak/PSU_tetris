/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_game_data
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

bool init_game_data(game_data_t *game_data, option_t options)
{
    if (!game_data)
        return (false);
    my_memset((char *)game_data, '\0', sizeof(game_data_t));
    game_data->board = create_board(options.map_size, 0);
    if (!(game_data->board))
        return (false);
    if (!init_left_pannel(&(game_data->left_panel), options))
        return (false);
    return (true);
}