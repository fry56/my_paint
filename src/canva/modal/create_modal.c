/*
** EPITECH PROJECT, 2023
** create_modal.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_scene.h>
#include <t_mem.h>
#include <canva/canva_structs.h>
#include <canva/canva_functions.h>

static void init_modal(sprite *new_modal)
{
    modal_s *modal_datas;

    new_modal->sprite_datas = tcalloc(1, sizeof(modal_s));
    modal_datas = new_modal->sprite_datas;
    modal_datas->list_text = tlist_new();
    modal_datas->list_button = tlist_new();
    modal_datas->list_input = tlist_new();
    modal_datas->list_sprite = tlist_new();
}

static void init_close_button(scene *scene_datas, modal_s *modal_datas,
    sfFloatRect bounds)
{
    sprite *close_datas = create_button(scene_datas,
        (sfVector2f){bounds.left + bounds.width - 5, bounds.top + 5},
        "assets/close.png", modal_close_exc);
    tlist_add(modal_datas->list_button, close_datas);
}

static void init_title_text(scene *scene_datas, modal_s *modal_datas,
    sfFloatRect bounds, char *title)
{
    text *title_datas = new_text(scene_datas, title, "assets/font.ttf",
        (rgb){0, 0, 0});
    tlist_add(modal_datas->list_text, title_datas);
    sfText_setPosition(title_datas->sf_text,
        (sfVector2f){bounds.left + bounds.width / 2, bounds.top + 20});
    text_set_origin_center(title_datas);
}

sprite *create_modal(scene *scene_datas, char *title,
    char *name, sfVector2f scale)
{
    sprite *new_modal = new_sprite(scene_datas, "assets/bg_modal.png", 10);
    modal_s *modal_datas;
    sfFloatRect bounds;

    init_modal(new_modal);
    modal_datas = new_modal->sprite_datas;
    sfSprite_setPosition(new_modal->sf_sprite, (sfVector2f){960, 540});
    sfSprite_setScale(new_modal->sf_sprite, scale);
    bounds = sfSprite_getGlobalBounds(new_modal->sf_sprite);
    sprite_add_flag(new_modal, "canva_modal");
    sprite_add_flag(new_modal, name);
    init_close_button(scene_datas, modal_datas, bounds);
    init_title_text(scene_datas, modal_datas, bounds, title);
    return new_modal;
}
