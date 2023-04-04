/*
** EPITECH PROJECT, 2023
** create_list.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <canva/canva_structs.h>
#include <canva/canva_functions.h>
#include <t_mem.h>

static void init_button(scene *scene_datas, list_s *new_list,
    sfFloatRect bounds)
{
    sprite *up = create_button(scene_datas,
        (sfVector2f){bounds.left + bounds.width + 30, bounds.top + 25},
        "assets/up-arrow.png", list_up_exec);
    sprite *down = create_button(scene_datas,
        (sfVector2f){bounds.left + bounds.width + 30,
        bounds.top + bounds.height - 25}, "assets/down-arrow.png",
        list_down_exec);

    ((button_s *)up->sprite_datas)->host = new_list->host;
    ((button_s *)down->sprite_datas)->host = new_list->host;
    tlist_add(new_list->list_button, up);
    tlist_add(new_list->list_button, down);
}

sprite *create_list(scene *scene_datas, sfVector2f pos,
    sfVector2f scale, uint32_t max_showed_ligne)
{
    sprite *list_sprite = new_sprite(scene_datas, "assets/bg_modal.png", 11);
    sfFloatRect bounds;
    list_s *new_list = tcalloc(1, sizeof(list_s));

    list_sprite->sprite_datas = new_list;
    new_list->host = list_sprite;
    new_list->index = 0;
    new_list->max_showed_ligne = max_showed_ligne;
    new_list->list_button = tlist_new();
    new_list->list_ligne = tlist_new();
    sfSprite_setPosition(list_sprite->sf_sprite, pos);
    sfSprite_setScale(list_sprite->sf_sprite, scale);
    bounds = sfSprite_getGlobalBounds(list_sprite->sf_sprite);
    init_button(scene_datas, new_list, bounds);
    return list_sprite;
}
