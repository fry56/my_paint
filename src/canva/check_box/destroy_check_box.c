/*
** EPITECH PROJECT, 2023
** destroy_check_box.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <canva/canva_structs.h>
#include <t_mem.h>

void destroy_check_box(sprite *check_box_sprite)
{
    check_box_s *check_box_datas = check_box_sprite->sprite_datas;

    sprite_destroy(check_box_datas->img);
    free(check_box_datas);
    sprite_destroy(check_box_sprite);
}
