/*
** EPITECH PROJECT, 2023
** button_set_visibility.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <canva/canva_structs.h>

void button_set_visibility(sprite *sprite_datas, bool visibility)
{
    sprite_datas->visible = visibility;
    ((button_s *)sprite_datas->sprite_datas)->img->visible = visibility;
}
