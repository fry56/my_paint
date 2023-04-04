/*
** EPITECH PROJECT, 2023
** check_box_events.c
** File description:
** desc
*/

#include <canva/canva_functions.h>
#include <canva/canva_structs.h>
#include <t_mem.h>

void check_box_click(sprite *sprite_datas, window *window_datas)
{
    check_box_s *check_box = sprite_datas->sprite_datas;

    if (window_datas->event.type != sfEvtMouseButtonPressed)
        return;
    if (!sprite_is_mouse_click(sprite_datas, &window_datas->event))
        return;
    check_box->check = !check_box->check;
    check_box->img->visible = check_box->check;
    if (check_box->on_change != NULL)
        check_box->on_change(sprite_datas);
}
