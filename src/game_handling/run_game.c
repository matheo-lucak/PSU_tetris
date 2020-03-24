/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** run_game
*/

#include "my.h"
#include "tetris.h"

static inline dimensions_t compute_board_position(option_t options)
{
    dimensions_t win_dim = {getmaxx(stdscr), getmaxy(stdscr)};

    return ((dimensions_t){(win_dim.width / 2) - (options.map_size.width / 2),
                        (win_dim.height / 2) - (options.map_size.height / 2)});
}

bool run_game(game_data_t *game_data, option_t options,
                                        tetrimino_t **tetrimino_list)
{
    register size_t x = 0;
    register size_t y = 0;
    dimensions_t board_pos = compute_board_position(options);

    start_color();
    refresh();
    for (y = 0; y < options.map_size.height + 2; y += 1) {
        for (x = 0; x < options.map_size.width + 2; x += 1) {
            mvaddch(board_pos.height + y, board_pos.width + x, game_data->board[y][x].cell);
        }
    }
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