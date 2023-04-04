/*
** EPITECH PROJECT, 2023
** layer_list.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"
#include "t_mem.h"
#include <t_string.h>
#include <canva/canva_structs.h>

void select_layer(sprite *button)
{
    paint_s *paint_datas = thashmap_get(button->host->map_datas,
        "paint")->value;
    list_layer_s *layer = ((button_s *)button->sprite_datas)->parent;

    paint_datas->actual_frame_buffer = layer->buffer;
}

void toggle_layer_visibility(sprite *check_box)
{
    check_box_s *check_box_datas = check_box->sprite_datas;
    list_layer_s *layer = check_box_datas->parent;

    layer->buffer->visible = check_box_datas->check;
}

void add_layer(sprite *button)
{
    create_layer(button->host);
}
