/*
** EPITECH PROJECT, 2023
** destroy_check_box.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <canva/canva_structs.h>
#include <t_mem.h>

void destroy_button(sprite *button_sprite)
{
    button_s *button_datas = button_sprite->sprite_datas;

    sprite_destroy(button_datas->img);
    free(button_datas);
    sprite_destroy(button_sprite);
}
