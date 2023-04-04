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
    text *text_name = new_text(scene_datas, "Name :",
        "assets/font.ttf", (rgb){0, 0, 0});

    text_set_font_size(text_name, 24);
    sfText_setPosition(text_name->sf_text, (sfVector2f){900, 490});
    tlist_add(modal_datas->list_text, text_name);
}

static void init_input(scene *scene_datas, modal_s *modal_datas)
{
    sprite *name = create_input(scene_datas, char_only,
        (sfVector2f){960, 550}, (sfVector2f){4, 1});

    input_set_default_value(name, "image.png");
    sprite_add_flag(name, "modal_save_file_name");
    tlist_add(modal_datas->list_input, name);
}

void init_save_file_modal(scene *scene_datas)
{
    sprite *modal = create_modal(scene_datas, "Save File",
        "modal_save_file", (sfVector2f){1, 0.8f});
    modal_s *modal_datas = modal->sprite_datas;
    sprite *button_valide = create_button(scene_datas,
        (sfVector2f){960, 605}, "assets/check.png", save_file);

    init_text(scene_datas, modal_datas);
    init_input(scene_datas, modal_datas);
    tlist_add(modal_datas->list_button, button_valide);
    modal_toggle(modal);
}
