/*
** EPITECH PROJECT, 2023
** zoom.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"
#include <functions.h>

void zoom_more_exec(sprite *sprite_datas)
{
    paint_s *paint_datas = thashmap_get(sprite_datas->host->map_datas,
        "paint")->value;

    if (paint_datas->zoom < 5)
        paint_datas->zoom += 0.25f;
    update_layer(sprite_datas->host, sprite_datas->host->host);
    set_layer_pos(sprite_datas->host, paint_datas,
        (sfVector2f){LAYER_START_X, LAYER_START_Y * 0.60});
}

void zoom_less_exec(sprite *sprite_datas)
{
    paint_s *paint_datas = thashmap_get(sprite_datas->host->map_datas,
        "paint")->value;

    if (paint_datas->zoom > 0.25)
        paint_datas->zoom -= 0.25f;
    update_layer(sprite_datas->host, sprite_datas->host->host);
    set_layer_pos(sprite_datas->host, paint_datas,
        (sfVector2f){LAYER_START_X, LAYER_START_Y * 0.60});
}
