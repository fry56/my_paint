/*
** EPITECH PROJECT, 2023
** create_button.c
** File description:
** desc
*/

#include <canva/canva_functions.h>
#include <canva/canva_structs.h>
#include <t_mem.h>

static void set_animation(scene *scene_datas, sprite *button)
{
    animation *defaults_anim = thashmap_get(scene_datas->host->map_global_datas,
        "anim_btn_default")->value;
    animation *over_anim = thashmap_get(scene_datas->host->map_global_datas,
        "anim_btn_over")->value;
    animation *click_anim = thashmap_get(scene_datas->host->map_global_datas,
        "anim_btn_click")->value;

    new_animator(button);
    animator_add_animation(button->animator, defaults_anim);
    animator_add_animation(button->animator, over_anim);
    animator_add_animation(button->animator, click_anim);
    animator_play_animation(button->animator, "btn_default");
}

sprite *create_button(scene *scene_datas, sfVector2f pos,
    char *img_path, void (*click)(sprite *sprite_datas))
{
    sprite *button = new_sprite(scene_datas, "assets/button.png", 11);
    button_s *new_button = tcalloc(1, sizeof(button_s));

    new_button->img = new_sprite(scene_datas, img_path, 12);
    button->sprite_datas = new_button;
    new_button->host = button;
    new_button->click = click;
    set_animation(scene_datas, button);
    sfSprite_setPosition(button->sf_sprite, pos);
    sfSprite_setPosition(new_button->img->sf_sprite, pos);
    sprite_add_event_update_function(button, button_click);
    sprite_add_event_update_function(button, button_over);
    sprite_add_flag(button, "canva_button");
    return button;
}
