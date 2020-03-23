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
    register size_t index = 0;
    dimensions_t win_dim = {getmaxx(stdscr), getmaxy(stdscr)};

    while (index < options.map_size.height) {
        mvprintw(LINES / 2 - options.map_size.height / 2 + index, COLS / 2 - options.map_size.height / 2, game_data->board[index]);
        index += 1;
    }
    refresh();
    index = 0;
    return (true);
}

int game(option_t options, tetrimino_t **tetrimino_list)
{
    game_data_t game_data;

    if (!init_game_data(&game_data, options))
        return (84);
    initscr();
    while (run_game(&game_data, options, tetrimino_list));
    endwin();
    should_save_score(game_data);
    return (0);
}