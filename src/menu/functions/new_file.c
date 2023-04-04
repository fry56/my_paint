/*
** EPITECH PROJECT, 2023
** new_file.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"
#include "t_mem.h"
#include <t_string.h>
#include <canva/canva_structs.h>

static bool insert_size(paint_s *paint_datas, sprite *sprite_datas)
{
    int width = tstr_to_number(((input_s *)sprite_get_by_flag(
        sprite_datas->host, "modal_new_file_width")->sprite_datas)->content);
    int height = tstr_to_number(((input_s *)sprite_get_by_flag(
        sprite_datas->host, "modal_new_file_height")->sprite_datas)->content);

    if (width > 3840 || width <= 0 || height > 2160 || height <= 0)
        return false;
    paint_datas->width = width;
    paint_datas->height = height;
    return true;
}

static void init_new_file(paint_s *paint_datas, sprite *sprite_datas)
{
    create_layer(sprite_datas->host);
    set_layer_default_color(paint_datas->actual_frame_buffer->sprite_datas,
        sfWhite);
    sfTexture_updateFromPixels(paint_datas->actual_frame_buffer->sf_texture,
        ((frame_buffer_s *)paint_datas->actual_frame_buffer->sprite_datas)->buf,
        paint_datas->width, paint_datas->height, 0,
        0);
}

void create_new_file(sprite *sprite_datas)
{
    paint_s *paint_datas = thashmap_get(sprite_datas->host->map_datas,
        "paint")->value;
    sprite *modal = sprite_get_by_flag(sprite_datas->host, "modal_new_file");

    if (!insert_size(paint_datas, sprite_datas))
        return;
    if (paint_datas->init)
        return;
    paint_datas->zoom = 1.0f;
    paint_datas->init = true;
    init_new_file(paint_datas, sprite_datas);
    sfRenderWindow_setTitle(sprite_datas->host->host->window,
        tstr_compos("My Paint %dX%d", paint_datas->width, paint_datas->height));
    modal_toggle(modal);
}

void new_file_exec(sprite *sprite_datas)
{
    sprite *modal = sprite_get_by_flag(sprite_datas->host, "modal_new_file");
    paint_s *paint_datas = thashmap_get(sprite_datas->host->map_datas,
        "paint")->value;
    if (paint_datas->init)
        return;
    modal_toggle(modal);
}
