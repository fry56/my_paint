/*
** EPITECH PROJECT, 2023
** new_file_modal_events.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <canva/canva_structs.h>
#include <struct.h>
#include <t_string.h>

void new_file_modal_change_width(sprite *sprite_datas)
{
    input_s *input_datas = sprite_datas->sprite_datas;
    int width = tstr_to_number(input_datas->content);

    if (width <= 3840 && width >= 0) {
        sfText_setColor(input_datas->text_datas->sf_text,
            sfColor_fromRGB(131, 145, 146));
    } else {
        sfText_setColor(input_datas->text_datas->sf_text, sfRed);
    }
}

void new_file_modal_change_height(sprite *sprite_datas)
{
    input_s *input_datas = sprite_datas->sprite_datas;
    int height = tstr_to_number(input_datas->content);

    if (height <= 2160 && height >= 0) {
        sfText_setColor(input_datas->text_datas->sf_text,
            sfColor_fromRGB(131, 145, 146));
    } else {
        sfText_setColor(input_datas->text_datas->sf_text, sfRed);
    }
}
