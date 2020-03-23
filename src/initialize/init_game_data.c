/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_game_data
*/

#include "my.h"
#include "tetris.h"

static bool init_high_score_frame(game_data_t *game_data)
{
    game_data->high_score.data = get_score();
    game_data->high_score.str = my_int_to_str(game_data->high_score.data);
    return (true);
}

bool init_game_data(game_data_t *game_data, option_t options)
{
    if (!game_data)
        return (false);
    my_memset((char *)game_data, '\0', sizeof(game_data_t));
    game_data->board = create_board(options);
    if (!(game_data->board))
        return (false);
    if (!init_high_score_frame(game_data))
        return (false);
    return (true);
}