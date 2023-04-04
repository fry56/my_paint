/*
** EPITECH PROJECT, 2023
** init_new_file_modal.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"

void init_help_modal(scene *scene_datas)
{
    sprite *modal = create_modal(scene_datas, "New File",
        "modal_help", (sfVector2f){4, 3});
    sprite *help = new_sprite(scene_datas, "assets/help.png", 11);
    modal_s *modal_datas = modal->sprite_datas;

    sfSprite_setPosition(help->sf_sprite, (sfVector2f){940, 550});
    tlist_add(modal_datas->list_sprite, help);
    modal_toggle(modal);
}
