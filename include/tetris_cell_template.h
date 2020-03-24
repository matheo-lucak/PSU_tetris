/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris_cell_template
*/

#ifndef TETRIS_CELL_TEMPLATE_H_
#define TETRIS_CELL_TEMPLATE_H_

#include "tetris.h"

const cell_t empty_cell = {.cell = ' ', .color = COLOR_YELLOW};
const cell_t side_cell = {.cell = '|', .color = COLOR_YELLOW};
const cell_t topbot_cell = {.cell = '-', .color = COLOR_YELLOW};
const cell_t nwse_cell = {.cell = '/', .color = COLOR_YELLOW};
const cell_t nesw_cell = {.cell = '\\', .color = COLOR_YELLOW};
const cell_t null_cell = {.cell = '\0', .color = COLOR_BLACK};


#endif /* !TETRIS_CELL_TEMPLATE_H_ */
