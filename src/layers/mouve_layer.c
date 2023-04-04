/*
** EPITECH PROJECT, 2023
** mouve_layer.c
** File description:
** desc
*/

#include <Class/t_scene.h>
#include <struct.h>
#include <Class/t_sprite.h>

void mouve_layer_pos(scene *scene_datas, paint_s *paint_datas, sfVector2f pos)
{
    list_foreach(paint_datas->list_frame_buffer, node)
        sfSprite_move(((sprite *)node->value)->sf_sprite,
            (sfVector2f){pos.x * scene_datas->host->deltatime,
            pos.y * scene_datas->host->deltatime});
}

void set_layer_pos(scene *scene_datas, paint_s *paint_datas, sfVector2f pos)
{
    list_foreach(paint_datas->list_frame_buffer, node)
        sfSprite_setPosition(((sprite *)node->value)->sf_sprite,
            (sfVector2f){pos.x * scene_datas->host->deltatime,
            pos.y * scene_datas->host->deltatime});
}

void mouve_layer(scene *scene_datas, sfClock *clock_datas UNUSED)
{
    paint_s *paint_datas = thashmap_get(scene_datas->map_datas, "paint")->value;
    sfVector2f layer_pos;
    if (!paint_datas->init)
        return;
    layer_pos = sfSprite_getPosition(
        paint_datas->actual_frame_buffer->sf_sprite);
    if (scene_is_key_press(scene_datas, sfKeyRight))
        if (layer_pos.x > -(((float)paint_datas->width * paint_datas->zoom) -
            (float)scene_datas->host->mode.width + LAYER_START_X + 128))
            mouve_layer_pos(scene_datas, paint_datas, (sfVector2f) {-1, 0});
    if (scene_is_key_press(scene_datas, sfKeyLeft))
        if (layer_pos.x < LAYER_START_X)
            mouve_layer_pos(scene_datas, paint_datas, (sfVector2f){1, 0});
    if (scene_is_key_press(scene_datas, sfKeyDown))
        if (layer_pos.y > -(((float)paint_datas->height * paint_datas->zoom) -
            (float)scene_datas->host->mode.height + (LAYER_START_Y / 2)))
            mouve_layer_pos(scene_datas, paint_datas, (sfVector2f){0, -1});
    if (scene_is_key_press(scene_datas, sfKeyUp))
        if (layer_pos.y < LAYER_START_Y)
            mouve_layer_pos(scene_datas, paint_datas, (sfVector2f){0, 1});
}
