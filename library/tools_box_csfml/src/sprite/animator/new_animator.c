/*
** EPITECH PROJECT, 2022
** new_animator.c
** File description:
** desc
*/

#include <stdlib.h>
#include <Class/t_sprite.h>

void init_animator(animator *animator)
{
    animator->animation_frame = 0;
    animator->map_animation = thashmap_new(1024);
    animator->list_callback = tlist_new();
    animator->played_animation = NULL;
    animator->default_animation = NULL;
    animator->last_clock_update = 1000;
}

animator *new_animator(sprite *self)
{
    animator *new_animator = malloc(sizeof(animator));
    if (new_animator == NULL)
        return NULL;
    init_animator(new_animator);
    new_animator->host = self;
    self->animator = new_animator;
    return new_animator;
}
