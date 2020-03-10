/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_options
*/

#include "my.h"
#include "tetris.h"

bolean_t set_control_key(option_t *options, char option, char *arg)
{
    int index = 0;

    if (!options || !arg)
        return (FALSE);
    index = find_char("lrtd", option);
    if (index == -1)
        return (FALSE);
    options->control_keys[index] = arg[0];
    my_printf("Option %c set key %c\n", option, arg[0]);
    return (TRUE);
}

bolean_t set_option_key(option_t *options, char option, char *arg)
{
    int index = 0;

    if (!options || !arg)
        return (FALSE);
    index = find_char("qp", option);
    if (index == -1)
        return (FALSE);
    options->control_keys[index] = arg[0];
    my_printf("Option %c set key %c\n", option, arg[0]);
    return (TRUE);
}

bolean_t set_level(option_t *options, char option, char *arg)
{
    if (!options || !arg)
        return (FALSE);
    if (!my_str_is_num(arg))
        return (FALSE);
    options->level = my_getnbr(arg);
    if (options->level <= 0)
        return (FALSE);
    my_printf("Option %c set level %d\n", option, options->level);
    return (TRUE);
}

bolean_t set_map_size(option_t *options, char option, char *arg)
{
    char **parsed_input = my_str_to_word_array(arg, " ,", 0);

    if (!options || !arg || !parsed_input)
        return (FALSE);
    if (my_arrlen(parsed_input) != 2) {
        my_free_arr((void **)parsed_input);
        return (FALSE);
    }
    options->map_size.x = my_getnbr(parsed_input[0]);
    options->map_size.y = my_getnbr(parsed_input[1]);
    if (options->map_size.x <= 0 || options->map_size.y <= 0 ||
        !my_str_is_num(parsed_input[0]) || !my_str_is_num(parsed_input[0])) {
        my_free_arr((void **)parsed_input);
        return (FALSE);
    }
    my_printf("Option %c set size to %d, %d\n", option,
                            options->map_size.x, options->map_size.y);
    return (TRUE);
}

bolean_t set_game_option(option_t *options, char option,
                                    __attribute__((unused))char *arg)
{
    int index = 0;

    if (!option)
        return (FALSE);
    index = find_char("Dw", option);
    if (index == -1)
        return (FALSE);
    options->game_option |= my_pow(2, index);
    my_printf("Option %c set bit %d\n", option, my_pow(2, index));
    return (TRUE);
}