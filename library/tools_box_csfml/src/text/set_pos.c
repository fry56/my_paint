/*
** EPITECH PROJECT, 2022
** set_pos.c
** File description:
** desc
*/

#include <Class/t_text.h>

void text_set_pos(text *self, int x, int y)
{
    sfText_setPosition(self->sf_text, (sfVector2f){x, y});
}
