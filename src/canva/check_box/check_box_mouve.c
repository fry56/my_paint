/*
** EPITECH PROJECT, 2023
** check_box_set_position.c
** File description:
** desc
*/

#include <canva/canva_structs.h>

void check_box_mouve(sprite *check_box, sfVector2f pos)
{
    check_box_s *check_box_datas = check_box->sprite_datas;

    sfSprite_move(check_box->sf_sprite, pos);
    sfSprite_move(check_box_datas->img->sf_sprite, pos);
}
