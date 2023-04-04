/*
** EPITECH PROJECT, 2023
** button_set_position.c
** File description:
** desc
*/

#include <canva/canva_structs.h>

void button_set_position(sprite *button, sfVector2f pos)
{
    button_s *button_datas = button->sprite_datas;

    sfSprite_setPosition(button->sf_sprite, pos);
    sfSprite_setPosition(button_datas->img->sf_sprite, pos);
}
