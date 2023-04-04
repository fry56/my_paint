/*
** EPITECH PROJECT, 2023
** init_new_file_modal.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"

static void init_text(scene *scene_datas, modal_s *modal_datas)
{
    text *text_email = new_text(scene_datas,
        "Any question or bug : jules.danet@epitech.eu",
        "assets/font.ttf", (rgb){0, 0, 0});

    text_set_font_size(text_email, 24);
    text_set_origin_center(text_email);
    sfText_setPosition(text_email->sf_text, (sfVector2f){940, 550});
    tlist_add(modal_datas->list_text, text_email);
}

void init_about_modal(scene *scene_datas)
{
    sprite *modal = create_modal(scene_datas, "About",
        "modal_about", (sfVector2f){2.5f, 0.4f});
    modal_s *modal_datas = modal->sprite_datas;

    init_text(scene_datas, modal_datas);
    modal_toggle(modal);
}
