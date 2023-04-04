/*
** EPITECH PROJECT, 2023
** button_set_sacle.c
** File description:
** desc
*/

#include <canva/canva_structs.h>

void button_set_scale(sprite *button, sfVector2f scale)
{
    button_s *button_datas = button->sprite_datas;

    sfSprite_setScale(button->sf_sprite, scale);
    sfSprite_setScale(button_datas->img->sf_sprite, scale);
}
