/*
** EPITECH PROJECT, 2023
** list_add_ligne.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <canva/canva_structs.h>


void list_add_ligne(sprite *list_sprite, list_line_s *new_line)
{
    list_s *list_datas = list_sprite->sprite_datas;
    sfFloatRect bounds = sfSprite_getGlobalBounds(list_datas->host->sf_sprite);

    tlist_add(list_datas->list_ligne, new_line);
    if (list_datas->list_ligne->length >
        list_datas->index + list_datas->max_showed_ligne)
        new_line->set_visibility(new_line, false);
    new_line->mouve(new_line, (sfVector2f){bounds.left + 10,
        bounds.top + ((bounds.height / (float)list_datas->max_showed_ligne)
        * (float)(list_datas->list_ligne->length - 1))});
}
