/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/

#include <Class/t_sprite_animator.h>
#include "Class/t_sprite.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void sprite_destroy(sprite *self)
{
    tsize_t i = 0;

    sfSprite_destroy(self->sf_sprite);
    if (self->sf_texture != NULL)
        sfTexture_destroy(self->sf_texture);
    self->visible = false;
    tlist_remove(self->host->list_sprites, self->sprite_node);
    if (self->animator != NULL) {
        list_foreach(self->animator->list_callback, node) {
            animator_remove_callback(self->animator, i);
            i++;
        }
        thashmap_clear(self->animator->map_animation);
        free(self->animator);
    }
    tlist_pop(self->list_flags);
    free(self);
}
