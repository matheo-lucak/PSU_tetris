/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris_frame_template
*/

#ifndef TETRIS_FRAME_TEMPLATE_H_
#define TETRIS_FRAME_TEMPLATE_H_

#include "tetris.h"

typedef enum left_panel_component_s {
    HIGH_SCORE,
    SCORE,
    LEVEL,
    LINES_DESTROYED,
    TIMER
} left_panel_component_t;

extern const frame_t left_panel_template;
extern const frame_component_t high_score_template;
extern const frame_component_t score_template;
extern const frame_component_t level_template;
extern const frame_component_t lines_template;
extern const frame_component_t timer_template;


#endif /* !TETRIS_FRAME_TEMPLATE_H_ */