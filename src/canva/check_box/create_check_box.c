/*
** EPITECH PROJECT, 2023
** create_check_box.c
** File description:
** desc
*/

#include <canva/canva_functions.h>
#include <canva/canva_structs.h>
#include <t_mem.h>

static void set_animation(scene *scene_datas, sprite *check_box)
{
    animation *defaults_anim = thashmap_get(scene_datas->host->map_global_datas,
        "anim_btn_default")->value;
    animation *over_anim = thashmap_get(scene_datas->host->map_global_datas,
        "anim_btn_over")->value;
    animation *click_anim = thashmap_get(scene_datas->host->map_global_datas,
        "anim_btn_click")->value;

    new_animator(check_box);
    animator_add_animation(check_box->animator, defaults_anim);
    animator_add_animation(check_box->animator, over_anim);
    animator_add_animation(check_box->animator, click_anim);
    animator_play_animation(check_box->animator, "btn_default");
}

sprite *create_check_box(scene *scene_datas, sfVector2f pos, bool default_value,
    void (*on_change)(sprite *sprite_datas))
{
    sprite *check_box = new_sprite(scene_datas, "assets/button.png", 11);
    check_box_s *new_check_box = tcalloc(1, sizeof(check_box_s));

    new_check_box->img = new_sprite(scene_datas, "assets/check_box.png", 12);
    new_check_box->img->visible = default_value;
    new_check_box->check = default_value;
    check_box->sprite_datas = new_check_box;
    new_check_box->host = check_box;
    new_check_box->on_change = on_change;
    set_animation(scene_datas, check_box);
    sfSprite_setScale(check_box->sf_sprite, (sfVector2f){0.5f, 0.5f});
    sfSprite_setScale(new_check_box->img->sf_sprite, (sfVector2f){0.5f, 0.5f});
    sfSprite_setPosition(check_box->sf_sprite, pos);
    sfSprite_setPosition(new_check_box->img->sf_sprite, pos);
    sprite_add_event_update_function(check_box, check_box_click);
    sprite_add_event_update_function(check_box, button_over);
    sprite_add_flag(check_box, "canva_check_box");
    return check_box;
}
