/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** run_game
*/

#include "my.h"
#include "tetris.h"
#include "tetris_frame_template.h"

static pos_t compute_board_position(option_t options)
{
    pos_t win_dim = {getmaxx(stdscr), getmaxy(stdscr)};

    return ((pos_t){(win_dim.x / 2) - (options.map_size.width / 2),
                    (win_dim.y / 2) - (options.map_size.height / 2)});
}

bool update_game(game_data_t *game_data)
{
    clock_t end = clock();
    int level = game_data->left_panel.components[LEVEL].data;

    if (end - game_data->timer > 1000000 / (level)) {
        game_data->timer = end;
        return (true);
    }
    return (false);
}

bool run_game(game_data_t *game_data, option_t options,
                                        tetrimino_t *tetrimino_list)
{
    pos_t board_pos = compute_board_position(options);
    static tetrimino_t *queue = NULL;

    refresh();
    erase();
    update_queue(&queue, tetrimino_list);
    display_all(game_data, queue, options, board_pos);
    parse_input(game_data, &queue, options);
    if (!update_game(game_data))
        return (true);
    if (land_tetrimino(game_data, &queue, options))
        game_data->cursor.y += 1;
    should_break_line(game_data, options);
    if (game_data->quit) {
        empty_queue(&queue);
        return (false);
    }
    return (true);
}

int game(option_t options, tetrimino_t **tetrimino_list)
{
    game_data_t game_data;

    if (!init_game_data(&game_data, options))
        return (84);
    my_printf("Press any key to start Tetris\n");
    read(0, NULL, 1);
    initscr();
    cbreak();
    keypad(stdscr, true);
    timeout(0);
    start_color();
    while (run_game(&game_data, options, *tetrimino_list));
    endwin();
    should_save_score(game_data);
    free_game_data(game_data);
    return (0);
}