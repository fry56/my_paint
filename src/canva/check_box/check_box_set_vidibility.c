/*
** EPITECH PROJECT, 2023
** check_box_set_vidibility.c
** File description:
** desc
*/
#include <Class/t_sprite.h>
#include <canva/canva_structs.h>

void check_box_set_visibility(sprite *sprite_datas, bool visibility)
{
    sprite_datas->visible = visibility;
    if (visibility)
        ((check_box_s *)sprite_datas->sprite_datas)->img->visible =
            ((check_box_s *)sprite_datas->sprite_datas)->check;
    else
        ((check_box_s *)sprite_datas->sprite_datas)->img->visible = false;
}
