/*
** EPITECH PROJECT, 2022
** new_sprite.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include <stdlib.h>
#include "Class/t_sprite_animator.h"
#include "t_list.h"
#include "t_map.h"


void init_sprite(sprite *sprite)
{
    sprite->animator = NULL;
    sprite->fixed_origin = false;
    sprite->visible = true;
    sprite->list_clock_update_functions = tlist_new();
    sprite->list_event_update_functions = tlist_new();
    sprite->sf_sprite = sfSprite_create();
    sprite->list_event_update_functions = tlist_new();
    sprite->list_clock_update_functions = tlist_new();
    sprite->list_flags = tlist_new();
}

t_list_node *z_index_list_add(t_list *list_sprites, sprite *new_sprite
    , int z_index)
{
    list_foreach(list_sprites, node) {
        if (((sprite *)node->value)->z_index > z_index)
            return tlist_add_before(list_sprites, node, new_sprite);
    }
    return tlist_add(list_sprites, new_sprite);
}

sprite *new_sprite(scene *scene_datas, char *texture_path, int z_index)
{
    sprite *new_sprite = malloc(sizeof(sprite));
    t_list_node *new_sprite_node;

    if (new_sprite == NULL)
        return NULL;
    if ((new_sprite_node = z_index_list_add(scene_datas->list_sprites
        , new_sprite, z_index))
        == NULL) {
        free(new_sprite);
        return NULL;
    }
    new_sprite->host = scene_datas;
    new_sprite->sprite_node = new_sprite_node;
    new_sprite->z_index = z_index;
    init_sprite(new_sprite);
    new_sprite->sf_texture = NULL;
    if (texture_path != NULL)
        sprite_set_texture(new_sprite, texture_path);
    sprite_set_origin_center(new_sprite);
    return new_sprite;
}
