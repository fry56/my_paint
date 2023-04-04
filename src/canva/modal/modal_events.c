/*
** EPITECH PROJECT, 2023
** modal_events.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <canva/canva_structs.h>
#include <canva/canva_functions.h>

static bool close_finded_modal(sprite *modal_datas, sprite *sprite_datas)
{
    list_foreach(((modal_s *)modal_datas->sprite_datas)->list_button, node) {
        if (sprite_datas == node->value) {
            modal_toggle(modal_datas);
            return true;
        }
    }
    return false;
}

void modal_close_exc(sprite *sprite_datas)
{
    list_foreach(sprite_datas->host->list_sprites, node) {
        if (!sprite_have_flag(node->value, "canva_modal"))
            continue;
        if (close_finded_modal(node->value, sprite_datas))
            return;
    }
}
