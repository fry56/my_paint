/*
** EPITECH PROJECT, 2023
** about.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"

void about_exec(sprite *sprite_datas)
{
    sprite *modal = sprite_get_by_flag(sprite_datas->host, "modal_about");

    modal_toggle(modal);
}
