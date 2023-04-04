/*
** EPITECH PROJECT, 2023
** create_layer.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <struct.h>
#include <functions.h>
#include <config.h>
#include <canva/canva_structs.h>

static void init_layer(scene *scene_datas, paint_s *paint_datas, sprite *buffer)
{
    sprite *layer_sprite = sprite_get_by_flag(scene_datas, "list_layer");

    add_layer_ligne_to_list(scene_datas, layer_sprite, buffer);
    paint_datas->actual_frame_buffer = buffer;
    tlist_add(paint_datas->list_frame_buffer, buffer);
    sfTexture_updateFromPixels(paint_datas->actual_frame_buffer->sf_texture,
        ((frame_buffer_s *)paint_datas->actual_frame_buffer->sprite_datas)->buf,
        paint_datas->width, paint_datas->height, 0, 0);
}

static void init_layer_pos(paint_s *paint_datas, sprite *new_layer)
{
    sfVector2f pos = {LAYER_START_X, LAYER_START_Y};
    sfVector2f scale = {1, 1};

    if (paint_datas->actual_frame_buffer != NULL) {
        pos = sfSprite_getPosition(paint_datas->actual_frame_buffer->sf_sprite);
        scale = sfSprite_getScale(paint_datas->actual_frame_buffer->sf_sprite);
    }
    sfSprite_setScale(new_layer->sf_sprite, scale);
    sfSprite_setOrigin(new_layer->sf_sprite, (sfVector2f){0, 0});
    sfSprite_setPosition(new_layer->sf_sprite, pos);
}

frame_buffer_s *create_layer(scene *scene_datas)
{
    paint_s *paint_datas = thashmap_get(scene_datas->map_datas, "paint")->value;
    frame_buffer_s *new_buffer;
    sprite *new_layer;
    sfTexture *new_texture;

    if (!paint_datas->init || paint_datas->list_frame_buffer->length >= 10)
        return NULL;
    new_buffer = create_frame_buffer(paint_datas->width,
        paint_datas->height);
    new_layer = new_sprite(scene_datas, NULL,
        (int)paint_datas->list_frame_buffer->length);
    new_texture = sfTexture_create(paint_datas->width,
        paint_datas->height);
    init_layer_pos(paint_datas, new_layer);
    new_layer->sf_texture = new_texture;
    new_layer->sprite_datas = new_buffer;
    sfSprite_setTexture(new_layer->sf_sprite, new_texture, sfFalse);
    init_layer(scene_datas, paint_datas, new_layer);
    return new_buffer;
}
