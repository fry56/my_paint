/*
** EPITECH PROJECT, 2023
** check_box_set_scale.c
** File description:
** desc
*/

#include <canva/canva_structs.h>

void check_box_set_scale(sprite *check_box, sfVector2f scale)
{
    check_box_s *check_box_datas = check_box->sprite_datas;

    sfSprite_setScale(check_box->sf_sprite, scale);
    sfSprite_setScale(check_box_datas->img->sf_sprite, scale);
}
