/*
** EPITECH PROJECT, 2023
** list_events.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include "canva/canva_functions.h"
#include "canva/canva_structs.h"

void list_up_exec(sprite *button_sprite)
{
    sprite *list_sprite = ((button_s *)button_sprite->sprite_datas)->host;
    sfFloatRect bounds = sfSprite_getGlobalBounds(list_sprite->sf_sprite);
    list_s *list_datas = list_sprite->sprite_datas;
    uint32_t index = 0;

    if (list_datas->index == 0)
        return;
    list_datas->index--;
    list_foreach(list_datas->list_ligne, node) {
        if (index < list_datas->index ||
            index >= list_datas->index + list_datas->max_showed_ligne)
            ((list_line_s *)node->value)->set_visibility(node->value, false);
        if (index >= list_datas->index && index < list_datas->max_showed_ligne)
            ((list_line_s *)node->value)->set_visibility(node->value, true);
        ((list_line_s *)node->value)->mouve(node->value,
            (sfVector2f){0,
            (bounds.height / (float)list_datas->max_showed_ligne)});
        index++;
    }
}

void list_down_exec(sprite *button_sprite)
{
    sprite *list_sprite = ((button_s *)button_sprite->sprite_datas)->host;
    sfFloatRect bounds = sfSprite_getGlobalBounds(list_sprite->sf_sprite);
    list_s *list_datas = list_sprite->sprite_datas;
    uint32_t index = 0;
    if (list_datas->list_ligne->length == list_datas->index +
        list_datas->max_showed_ligne)
        return;
    list_datas->index++;
    list_foreach(list_datas->list_ligne, node) {
        if (index < list_datas->index ||
            index >= list_datas->index + list_datas->max_showed_ligne)
            ((list_line_s *)node->value)->set_visibility(node->value, false);
        if (index >= list_datas->index &&
            index < list_datas->index + list_datas->max_showed_ligne)
            ((list_line_s *)node->value)->set_visibility(node->value, true);
        ((list_line_s *)node->value)->mouve(node->value,
            (sfVector2f){0,
            -(bounds.height / (float)list_datas->max_showed_ligne)});
        index++;
    }
}
