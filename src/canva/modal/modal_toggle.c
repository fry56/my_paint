/*
** EPITECH PROJECT, 2023
** modal_toggle.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_scene.h>
#include <t_mem.h>
#include <canva/canva_structs.h>
#include <canva/canva_functions.h>

void modal_toggle(sprite *sprite_datas)
{
    modal_s *modal_datas = sprite_datas->sprite_datas;

    sprite_datas->visible = !sprite_datas->visible;
    list_foreach(modal_datas->list_button, node)
        button_set_visibility(node->value, sprite_datas->visible);
    list_foreach(modal_datas->list_text, node)
        ((text *)node->value)->visible = sprite_datas->visible;
    list_foreach(modal_datas->list_input, node)
        input_set_visibility(node->value, sprite_datas->visible);
    list_foreach(modal_datas->list_sprite, node)
        ((sprite *)node->value)->visible = sprite_datas->visible;
}
