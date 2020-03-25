/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris_frame_template
*/

#include "tetris.h"

const frame_t left_panel_template = {
    .board = NULL,
    .size = (dimensions_t) {30, 10},
    .anchor = (pos_t) {-1, 0},
    .offset = (pos_t) {3, 0},
    .component_nb = 5,
    .components = NULL
};

const frame_component_t high_score_template = {
    .data = 0,
    .display_str = NULL,
    .display_str_color = COLOR_GREEN,
    .name = "High Score :",
    .name_color = COLOR_CYAN,
    .pos = (pos_t) {2, 2}
};

const frame_component_t score_template = {
    .data = 0,
    .display_str = NULL,
    .display_str_color = COLOR_GREEN,
    .name = "Score :",
    .name_color = COLOR_CYAN,
    .pos = (pos_t) {2, 3}
};

const frame_component_t level_template = {
    .data = 0,
    .display_str = NULL,
    .display_str_color = COLOR_GREEN,
    .name = "Level :",
    .name_color = COLOR_CYAN,
    .pos = (pos_t) {2, 5}
};

const frame_component_t lines_template = {
    .data = 0,
    .display_str = NULL,
    .display_str_color = COLOR_GREEN,
    .name = "Lines :",
    .name_color = COLOR_CYAN,
    .pos = (pos_t) {2, 6}
};

const frame_component_t timer_template = {
    .data = 0,
    .display_str = NULL,
    .display_str_color = COLOR_GREEN,
    .name = "Timer :",
    .name_color = COLOR_CYAN,
    .pos = (pos_t) {2, 8}
};