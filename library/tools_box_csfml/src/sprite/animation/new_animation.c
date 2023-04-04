/*
** EPITECH PROJECT, 2022
** new_animation.c
** File description:
** desc
*/

#include <Class/t_sprite_animation.h>
#include <stdlib.h>

animation *new_animation(char *name, char *path, bool loop, float frame_rate)
{
    animation *new_animation = malloc(sizeof(animation));

    if (new_animation == NULL)
        return NULL;
    new_animation->sf_texture = sfTexture_createFromFile(path, NULL);
    new_animation->name = name;
    new_animation->loop = loop;
    new_animation->frame_rate = frame_rate;
    new_animation->list_frame_rect = tlist_new();
    return new_animation;
}
