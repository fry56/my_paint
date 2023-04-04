/*
** EPITECH PROJECT, 2023
** help.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"

void help_exec(sprite *sprite_datas)
{
    sprite *modal = sprite_get_by_flag(sprite_datas->host, "modal_help");

    modal_toggle(modal);
}
