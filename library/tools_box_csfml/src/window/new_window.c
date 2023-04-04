/*
** EPITECH PROJECT, 2022
** inti.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <stdlib.h>

static void init_window(window *self)
{
    sfRenderWindow_setFramerateLimit(self->window, 60);
    self->mode_update = false;
    self->map_scenes = thashmap_new(1024);
    self->map_global_datas = thashmap_new(1024);
    self->actual_scene = NULL;
    self->last_tick = 0;
    self->deltatime = 0;
}

window *new_window(char *name, sfVideoMode mode)
{
    window *new_window = malloc(sizeof(window));

    if (new_window == NULL)
        return NULL;
    new_window->mode = mode;
    new_window->window = sfRenderWindow_create(mode, name
        , sfResize | sfClose, NULL);
    if (!new_window->window) {
        free(new_window);
        return NULL;
    }
    init_window(new_window);
    return new_window;
}
