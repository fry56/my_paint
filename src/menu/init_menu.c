/*
** EPITECH PROJECT, 2023
** init_menu.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"
#include "t_mem.h"

void init_menu(scene *scene_datas)
{
    sprite *top_banner = new_sprite(scene_datas, "assets/top_banner.png", 10);
    sprite *side_banner = new_sprite(scene_datas, "assets/side_banner.png", 10);

    sfSprite_setPosition(top_banner->sf_sprite, (sfVector2f){1920 / 2, 60});
    sfSprite_setOrigin(side_banner->sf_sprite, (sfVector2f){0, 0});
    sfSprite_setPosition(side_banner->sf_sprite, (sfVector2f){1792, 128});
    init_button_animation(scene_datas->host);
    init_file_drop_down(scene_datas);
    init_edit_drop_down(scene_datas);
    init_help_drop_down(scene_datas);
    init_new_file_modal(scene_datas);
    init_save_file_modal(scene_datas);
    init_layer_list(scene_datas);
    init_about_modal(scene_datas);
    init_help_modal(scene_datas);
    init_zoom(scene_datas);
}
