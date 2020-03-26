/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_frame
*/

#include "my.h"
#include "tetris.h"

static pos_t compute_frame_pos(frame_t frame, pos_t middle_pos)
{
    pos_t pos = middle_pos;

    if (frame.anchor.x) {
        pos.x += (frame.size.width + frame.offset.x) * frame.anchor.x;
    }
    if (frame.anchor.y) {
        pos.y += (frame.size.height + frame.offset.y) * frame.anchor.y;
    }
    return (pos);
}

static void display_frame_component(frame_component_t component, pos_t pos)
{
    init_pair(component.name_color, component.name_color,
                                            COLOR_BLACK);
    attron(COLOR_PAIR(component.name_color));
    mvprintw(pos.y + component.pos.y,
            pos.x + component.pos.x,
            component.name);
    attroff(COLOR_PAIR(component.name_color));
    free_pair(component.name_color);
    init_pair(component.display_str_color, component.display_str_color,
                                                            COLOR_BLACK);
    attron(COLOR_PAIR(component.display_str_color));
    mvprintw(pos.y + component.pos.y,
            pos.x + component.pos.x + my_strlen(component.name),
            component.display_str);
    attroff(COLOR_PAIR(component.display_str_color));
    free_pair(component.display_str_color);
}

void display_frame(frame_t frame, pos_t middle_pos)
{
    pos_t pos = compute_frame_pos(frame, middle_pos);
    register size_t index = 0;

    if (pos.x < 0 || pos.y < 0)
        return ;
    display_board(frame.board, frame.size, pos);
    for (index = 0; index < frame.component_nb; index += 1) {
        display_frame_component(frame.components[index], pos);
    }
}