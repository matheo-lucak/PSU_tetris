/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** run_game
*/

#include "time.h"
#include "my.h"
#include "tetris.h"

static inline pos_t compute_board_position(option_t options)
{
    pos_t win_dim = {getmaxx(stdscr), getmaxy(stdscr)};

    return ((pos_t){(win_dim.x / 2) - (options.map_size.width / 2),
                        (win_dim.y / 2) - (options.map_size.height / 2)});
}

bool run_game(game_data_t *game_data, option_t options,
                                        tetrimino_t **tetrimino_list)
{
    pos_t board_pos = compute_board_position(options);

    refresh();
    erase();
    display_board(game_data->board, options.map_size, board_pos);
    display_frame(game_data->left_panel, board_pos);
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