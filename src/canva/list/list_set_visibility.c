/*
** EPITECH PROJECT, 2023
** list_set_visibility.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <canva/canva_structs.h>
#include <canva/canva_functions.h>

void list_set_visibility(sprite *list_sprite, bool visibility)
{
    list_s *list = list_sprite->sprite_datas;

    list_sprite->visible = visibility;
    list_foreach(list->list_ligne, node)
        ((list_line_s *)((sprite *)node->value)->sprite_datas)->
            set_visibility(node->value, visibility);
    list_foreach(list->list_button, node)
        button_set_visibility(node->value, visibility);
}
