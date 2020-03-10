/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** get_tetriminos.c
*/

#include <stdbool.h>
#include <fcntl.h>
#include "my.h"
#include "tetris.h"

// char **shape;
// char *name;
// dimensions_t dims;
// size_t color;
// struct tetrimino_s *next;

static bool fill_first_tetrimino_line(const int fd, tetrimino_t *node)
{
    char **first_line = NULL;
    int color_tmp = 0;

    if (!node || fd == -1)
        return (false);
    first_line = my_str_to_word_array(get_next_line(fd), " ", 1);
    if (my_arrlen(first_line) != 3)
        return (false);
    node->dims.width = my_absolute_getnbr(first_line[0]);
    if (node->dims.width <= 0)
        return (false);
    node->dims.height = my_absolute_getnbr(first_line[1]);
    if (node->dims.height <= 0)
        return (false);
    color_tmp = my_absolute_getnbr(first_line[2]);
    if (color_tmp < 0)
        return (false);
    node->color = (size_t)color_tmp;
    return (true);
}

ssize_t get_shape_line(const int fd)
{
    char *line = NULL;
    ssize_t line_len = 0;

    line = get_next_line(fd);
    if (line) {
        line_len = my_strlen(line);
        free(line);
        return (line_len);
    }
    return (-1);
}

static ssize_t get_shape_alloc_size(const int fd, const dimensions_t dims)
{
    ssize_t max_len = -1;
    ssize_t tmp_len = -1;
    size_t nb_lines = 0;

    do {
        tmp_len = get_shape_line(fd);
        if (tmp_len > max_len)
            max_len = tmp_len;
        if (tmp_len > 0)
            nb_lines += 1;
    } while (tmp_len > -1);
    if (nb_lines == 0 || nb_lines != dims.height || max_len != dims.width)
        return (-1);
    lseek(fd, 0, SEEK_SET);
    my_skip_a_file_line(fd);
    return (max_len);
}

static bool fill_shape(const int fd, tetrimino_t *node)
{
    register size_t index = 0;

    if (!node || fd == -1)
        return (false);
    if (!get_shape_alloc_size(fd, node->dims) <= 0)
        return (false);
    node->shape = malloc(sizeof(char *) * node->dims.height);
    if (!node->shape)
        return (false);
    for (index = 0; index < node->dims.height; node->shape[index] = NULL);
    index = 0;
    while (index < node->dims.height) {
        node->shape[index] = malloc(sizeof(char *) * node->dims.height);
        index += 1;
    }
    return (true);
}

bool get_tetrimino(tetrimino_t *node, const char file_name[])
{
    char *absolute_path = NULL;
    int fd = -1;

    if (!node || !file_extension_determ(file_name, ".tetrimino"))
        return (false);
    *node = (tetrimino_t){NULL, NULL, {0, 0}, 0, NULL};
    node->name = my_strndup(file_name, my_strlen(file_name) - 10);
    if (!node->name)
        return (false);
    absolute_path = my_strcat("./tetriminos/", file_name);
    if (!absolute_path)
        return (false);
    fd = open(absolute_path, O_RDONLY);
    if (fd == -1)
        return (false);
    if (!fill_first_tetrimino_line(fd, node))
        return (false);
    if (!fill_shape(fd, node))
        return (false);
    my_printf("shape = %p, name = %s, dims.width = %d, dims.height = %d, color = %lu, next = %p\n",
                node->shape, node->name, node->dims.height, node->dims.width, node->color, node->next);
    return (true);
}