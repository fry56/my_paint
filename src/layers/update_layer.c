/*
** EPITECH PROJECT, 2023
** update_layer.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_scene.h>
#include <functions.h>
#include <t_mem.h>
#include <config.h>

void update_layer(scene *scene_datas, window *window_datas)
{
    paint_s *paint_datas;
    sprite *temp_sprite;
    sfVector2u size = sfRenderWindow_getSize(window_datas->window);
    sfVideoMode default_size = window_datas->mode;
    float x_a = ((float)default_size.width / (float)size.x);
    float y_a = ((float)default_size.height / (float)size.y);

    paint_datas = thashmap_get(scene_datas->map_datas, "paint")->value;
    if (!paint_datas->init)
        return;
    list_foreach(paint_datas->list_frame_buffer, node) {
        temp_sprite = node->value;
        sfSprite_setScale(temp_sprite->sf_sprite,
            (sfVector2f){ paint_datas->zoom * x_a, paint_datas->zoom * y_a});
    }
}

void resize_window_event(scene *scene_datas, window *window_datas)
{
    if (window_datas->event.type != sfEvtResized)
        return;
    update_layer(scene_datas, window_datas);
}
