/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_prog_stats.c
*/

#include "my.h"
#include "tetris.h"

static void print_key(const int c)
{
    my_printf(c == ' ' ? "(space)\n" : "%d\n", c);
}

static void print_selected_keys(const int control_keys[4],
                                const int options_keys[2])
{
    my_putstr("Key Left : ");
    print_key(control_keys[0]);
    my_putstr("Key Right : ");
    print_key(control_keys[1]);
    my_putstr("Key Turn : ");
    print_key(control_keys[2]);
    my_putstr("Key Drop : ");
    print_key(control_keys[3]);
    my_putstr("Key Quit : ");
    print_key(options_keys[0]);
    my_putstr("Key Pause : ");
    print_key(options_keys[1]);
}

static void print_shape_char(const char *shape_line, size_t *x)
{
    size_t tmp = *x;
    size_t star_finder = 0;

    if (shape_line[tmp] == ' ') {
        star_finder = tmp;
        while (shape_line[star_finder] && shape_line[star_finder++] != '*');
        if (!shape_line[star_finder]) {
            *x = star_finder;
            return;
        }
    }
    my_putchar(shape_line[tmp]);
}

static void print_tetrimino_shape(const char * const *shape)
{
    register size_t y = 0;
    size_t x = 0;

    if (!shape)
        return;
    while (shape[y]) {
        for (x = 0; shape[y][x]; x += 1)
            print_shape_char(shape[y], &x);
        my_putchar('\n');
        y += 1;
    }
}

void print_prog_stats(tetrimino_t **tetrimino_list, const option_t options)
{
    int index = 0;

    my_putstr("*** DEBUG MODE ***\n");
    print_selected_keys(options.control_keys, options.option_keys);
    my_putstr(options.game_option >> 1 == 1 ? "Next = Yes\n" : "Next = No\n");
    my_printf("Level = %u\n", options.level);
    my_printf("Size : %lu*%lu\n", options.map_size.width,
                                    options.map_size.height);
    my_printf("Tetriminos: %lu\n", get_tetriminos_nb(tetrimino_list));
}