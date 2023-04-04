/*
** EPITECH PROJECT, 2023
** input_set_visibility.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <canva/canva_structs.h>

void input_set_visibility(sprite *input_sprite, bool visibility)
{
    input_s *input_datas = input_sprite->sprite_datas;

    input_sprite->visible = visibility;
    if (!visibility)
        input_datas->select = false;
    input_datas->text_datas->visible = visibility;
}
