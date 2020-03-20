/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_options
*/

#include "my.h"
#include "tetris.h"

bool set_control_key(option_t *options, char option, char *arg)
{
    int index = 0;

    if (!options || !arg)
        return (false);
    index = find_char("lrtd", option);
    if (index == -1)
        return (false);
    options->control_keys[index] = arg[0];
    my_printf("Option %c set key %c\n", option, arg[0]);
    return (true);
}

bool set_option_key(option_t *options, char option, char *arg)
{
    int index = 0;

    if (!options || !arg)
        return (false);
    index = find_char("qp", option);
    if (index == -1)
        return (false);
    options->control_keys[index] = arg[0];
    my_printf("Option %c set key %c\n", option, arg[0]);
    return (true);
}

bool set_level(option_t *options, char option, char *arg)
{
    if (!options || !arg)
        return (false);
    if (!my_str_is_num(arg))
        return (false);
    options->level = my_getnbr(arg);
    if (options->level <= 0)
        return (false);
    my_printf("Option %c set level %d\n", option, options->level);
    return (true);
}

bool set_map_size(option_t *options, char option, char *arg)
{
    char **parsed_input = my_str_to_word_array(arg, ", ", 0);
    int tmp_width = 0;
    int tmp_height = 0;

    if (!options || !arg || !parsed_input)
        return (false);
    if (my_arrlen(parsed_input) != 2) {
        my_free_arr((void **)parsed_input);
        return (false);
    }
    tmp_width = my_absolute_getnbr(parsed_input[0]);
    tmp_height = my_absolute_getnbr(parsed_input[1]);
    if (tmp_width <= 0 || tmp_height <= 0) {
        my_free_arr((void **)parsed_input);
        return (false);
    }
    options->map_size.width = (size_t)tmp_width;
    options->map_size.height = (size_t)tmp_height;
    my_printf("Option %c set size to %d, %d\n", option, options->map_size.width, options->map_size.height);
    return (true);
}

bool set_game_option(option_t *options, char option,
                        __attribute__((unused))char *arg)
{
    int index = 0;

    if (!option)
        return (false);
    index = find_char("Dw", option);
    if (index == -1)
        return (false);
    options->game_option |= my_pow(2, index);
    my_printf("Option %c set bit %d\n", option, my_pow(2, index));
    return (true);
}