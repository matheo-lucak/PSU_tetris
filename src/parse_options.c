/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** parse_options
*/

#include <unistd.h>
#include <getopt.h>
#include "my.h"
#include "tetris.h"

"LlrtdqpswD"
bolean_t set_control_key(option_t *options, char option, char *arg)
{
    if (!options || !arg)
        return (NULL);
    if (option == 'l') {
        options->control_keys[0] = arg[0];
        return (TRUE);
    }
    if (option == 'r') {
        options->control_keys[1] = arg[0];
        return (TRUE);
    }
    if (option == 't') {
        options->control_keys[2] = arg[0];
        return (TRUE);
    }
    if (option == 'd') {
        options->control_keys[4] = arg[0];
        return (TRUE);
    }
    return (FALSE);
}

bolean_t set_control_key(option_t *options, char option, char *arg)
{
    if (!options || !arg)
        return (NULL);
    if (option == 'l') {
        options->control_keys[0] = arg[0];
        return (TRUE);
    }
    if (option == 'r') {
        options->control_keys[1] = arg[0];
        return (TRUE);
    }
    if (option == 't') {
        options->control_keys[2] = arg[0];
        return (TRUE);
    }
    if (option == 'd') {
        options->control_keys[4] = arg[0];
        return (TRUE);
    }
    return (FALSE);
}

bolean_t parse_option(const int ac, char * const av[], option_t *options)
{
    struct option option_template[10] = {
        {.name = "level=", .has_arg = 1, NULL, 'L'},
        {.name = "key-left=", .has_arg = 1, NULL, 'l'},
        {.name = "key-right=", .has_arg = 1, NULL, 'r'},
        {.name = "key-turn=", .has_arg = 1, NULL, 't'},
        {.name = "key-drop=", .has_arg = 1, NULL, 'd'},
        {.name = "key-quit=", .has_arg = 1, NULL, 'q'},
        {.name = "key-pause=", .has_arg = 1, NULL, 'p'},
        {.name = "map-size=", .has_arg = 1, NULL, 's'},
        {.name = "without-next", .has_arg = 0, NULL, 'w'},
        {.name = "debug", .has_arg = 0, NULL, 'D'},
        {.name = NULL, .has_arg = 0, NULL, 0}};
    int check = 0;
    int option_index = 0;

    if (!av)
        return (84);
    do {
        check = getopt_long(ac, av, "LlrtdqpswD", option_template, &option_index);
        printf("Opt arg : %s\n", optarg);
    } while (check != -1);
}