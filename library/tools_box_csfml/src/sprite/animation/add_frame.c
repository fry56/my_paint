/*
** EPITECH PROJECT, 2023
** add_frame.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <stdlib.h>

bool animation_add_frame(animation *self, sfIntRect rect)
{
    sfIntRect *temp_rect;

    if ((temp_rect = malloc(sizeof(sfIntRect))) == NULL)
        return false;
    *temp_rect = rect;
    tlist_add(self->list_frame_rect, temp_rect);
    return true;
}
