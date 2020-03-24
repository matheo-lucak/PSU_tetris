/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** run_game
*/

#include "my.h"
#include "tetris.h"

bool run_game(game_data_t *game_data, option_t options,
                                        tetrimino_t **tetrimino_list)
{
    refresh();
    erase();
    display_board(game_data, options);
    return (true);
}

int game(option_t options, tetrimino_t **tetrimino_list)
{
    game_data_t game_data;

    if (!init_game_data(&game_data, options))
        return (84);
    initscr();
    start_color();
    while (run_game(&game_data, options, tetrimino_list));
    endwin();
    should_save_score(game_data);
    return (0);
}