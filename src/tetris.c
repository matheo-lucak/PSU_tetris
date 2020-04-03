/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Main tetris overview of what's happening.
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static void set_default_options(option_t *options)
{
    *options = (option_t){.level = 1,
                    .game_option = 0,
                    .map_size = (dimensions_t){20, 10},
                    .control_keys = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN},
                    .option_keys = {'q', ' '}};
}

static bool check_for_input(void)
{
    char *input = NULL;

    my_putstr("Press any key to start Tetris\n");
    input = get_next_line(0);
    if (!input)
        return (false);
    free(input);
    return (true);
}

int tetris(const int ac, char * const av[])
{
    tetrimino_t *tetrimino_list = NULL;
    option_t options;
    int game_return_value = 0;

    set_default_options(&options);
    if (!parse_option(ac, av, &options))
        return (84);
    if (!(read_tetriminos_dir(&tetrimino_list)))
        return (84);
    if (options.game_option & DEBUG) {
        print_prog_stats(&tetrimino_list, options);
        if (!check_for_input())
            return (0);
    }
    game_return_value = game(options, &tetrimino_list);
    free_tetriminos_list(tetrimino_list);
    return (game_return_value);
}