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
#include "set_option.h"

static bolean_t (*set_option_func[])(option_t *, char , char *);
static struct option const option_template[11];

bolean_t parse_option(const int ac, char * const av[], option_t *options)
{
    int check = 0;
    int index = 0;

    if (!av)
        return (84);
    do {
        check = getopt_long(ac, av, "LlrtdqpswD", option_template, NULL);
        index = find_char("LlrtdqpswD", check);
        if (index == -1)
            continue;
        if (!set_option_func[index](options, check, optarg)) {
            my_printf("%s is bad argument for option %c\n", optarg, check);
            return (FALSE);
        }
    } while (check != -1);
    return (TRUE);
}