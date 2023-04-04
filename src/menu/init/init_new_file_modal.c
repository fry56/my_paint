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
    text *text_width = new_text(scene_datas, "Width :",
        "assets/font.ttf", (rgb){0, 0, 0});
    text *text_height = new_text(scene_datas, "Height :",
        "assets/font.ttf", (rgb){0, 0, 0});

    text_set_font_size(text_width, 24);
    text_set_font_size(text_height, 24);
    sfText_setPosition(text_width->sf_text, (sfVector2f){900, 440});
    sfText_setPosition(text_height->sf_text, (sfVector2f){900, 530});
    tlist_add(modal_datas->list_text, text_width);
    tlist_add(modal_datas->list_text, text_height);
}

static void init_input(scene *scene_datas, modal_s *modal_datas)
{
    sprite *input_width = create_input(scene_datas, number_only,
        (sfVector2f){960, 500}, (sfVector2f){2.5f, 1});
    sprite *input_height = create_input(scene_datas, number_only,
        (sfVector2f){960, 590}, (sfVector2f){2.5f, 1});

    ((input_s *)input_width->sprite_datas)->on_change
        = new_file_modal_change_width;
    ((input_s *)input_height->sprite_datas)->on_change
        = new_file_modal_change_height;
    sprite_add_flag(input_width, "modal_new_file_width");
    sprite_add_flag(input_height, "modal_new_file_height");
    input_set_default_value(input_width, "1920");
    input_set_default_value(input_height, "1080");
    tlist_add(modal_datas->list_input, input_width);
    tlist_add(modal_datas->list_input, input_height);
}

void init_new_file_modal(scene *scene_datas)
{
    sprite *modal = create_modal(scene_datas, "New File",
        "modal_new_file", (sfVector2f){1, 1.20f});
    modal_s *modal_datas = modal->sprite_datas;
    sprite *button_valide = create_button(scene_datas,
        (sfVector2f){960, 650}, "assets/check.png", create_new_file);

    init_text(scene_datas, modal_datas);
    init_input(scene_datas, modal_datas);
    tlist_add(modal_datas->list_button, button_valide);
    modal_toggle(modal);
}
