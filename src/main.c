/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "my.h"
#include "tetris.h"

static void print_usage(char *binary_name)
{
    my_printf("Usage:\t%s [options]\n", binary_name);
    my_putstr("Options:\n");
    my_putstr("\t--help\t\t\t\t\t Display this help\n");
    my_putstr("\t-L --level={num}\t\t\t Start Tetris at level num (def: 1)\n");
    my_putstr("\t-l --key-left={K}\t\t\t Move the tetrimino LEFT "
                                    "using the K key (def: left arrow)\n");
    my_putstr("\t-r --key-right={K}\t\t\t Move the tetrimino RIGHT "
                                    "using the K key (def: right arrow)\n");
    my_putstr("\t-t --key-turn={K}\t\t\t TURN the tetrimino clockwise 90d "
                                    "using the K key (def: top arrow)\n");
    my_putstr("\t-d --key-drop={K}\t\t\t DROP the tetrimino "
                                    "using the K key (def: down arrow)\n");
    my_putstr("\t-q --key-quit={K}\t\t\t QUIT the game "
                                    "using the K key (def: 'q' key)\n");
    my_putstr("\t-p --key-pause={K}\t\t\t PAUSE/RESTART the game "
                                    "using the K key (def: space bar)\n");
    my_putstr("\t--map-size={row,col}\t\t\t Set the numbers of "
                                "rows and columns of the map (def: 20,10)\n");
    my_putstr("\t-w --without-next\t\t\t Hide next tetrimino (def: false)\n");
    my_putstr("\t-D --debug\t\t\t\t Debug mode (def: false)\n");
}

static bool should_print_usage(const int ac, char * const av[])
{
    register int index = 0;

    for (index = 0; index < ac; index += 1) {
        if (my_mass_strcmp(av[index], "-h", "--help"))
            return (true);
    }
    return (false);
}

int main(const int ac, char * const av[])
{
    if (should_print_usage(ac, av)) {
        print_usage(av[0]);
        return (0);
    }
    return (tetris(ac, av));
}