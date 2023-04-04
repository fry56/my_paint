/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_sprite.h>
#include <Class/t_text.h>

void clear_sprite(scene *temp)
{
    sprite *temp_sprite;

    list_foreach(temp->list_sprites, node) {
        temp_sprite = node->value;
        sprite_destroy(temp_sprite);
    }
}

void clear_text(scene *temp)
{
    text *temp_text;

    list_foreach(temp->list_texts, node) {
        temp_text = node->value;
        text_destroy(temp_text);
    }
}

void window_destroy(window *self)
{
    for (u32 i = 0; i < self->map_scenes->size; ++i) {
        if (self->map_scenes->map[i] == NULL)
            continue;
        clear_sprite(self->map_scenes->map[i]->value);
        clear_text(self->map_scenes->map[i]->value);
        list_foreach(self->map_scenes->map[i]->childs_node, node) {
            clear_sprite(node->value);
            clear_text(node->value);
        }
    }
    sfClock_destroy(self->global_clock);
    sfRenderWindow_destroy(self->window);
}
