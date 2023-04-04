/*
** EPITECH PROJECT, 2023
** input_set_default_value.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_sprite.h>
#include <canva/canva_structs.h>
#include <t_string.h>
#include <t_mem.h>

void input_set_default_value(sprite *input_sprite, char *value)
{
    input_s *input_datas = input_sprite->sprite_datas;

    input_datas->length = tstr_len(value);
    tstr_cpy(input_datas->content, value);
    tstr_cpy(input_datas->temp_text_string, value);
    sfText_setString(input_datas->text_datas->sf_text, value);
}
