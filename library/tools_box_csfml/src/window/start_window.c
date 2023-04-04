/*
** EPITECH PROJECT, 2023
** init_window.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_sprite.h>
#include <Class/t_text.h>

static void window_update_entity(window *self)
{
    sfVector2u size;

    if (!self->mode_update) {
        size = sfRenderWindow_getSize(self->window);
        self->mode.width = size.x;
        self->mode.height = size.y;
        self->mode_update = true;
    }
    list_foreach(((scene *)self->actual_scene->value)->list_sprites, node) {
        if (!((sprite *) node->value)->visible)
            continue;
        sfRenderWindow_drawSprite(self->window,
            ((sprite *) node->value)->sf_sprite, NULL);
    }
    list_foreach(((scene *)self->actual_scene->value)->list_texts, node) {
        if (!((text *) node->value)->visible)
            continue;
        sfRenderWindow_drawText(self->window,
            ((text *) node->value)->sf_text,NULL);
    }
}

int start_window(window *self)
{
    sfColor background = sfColor_fromRGB(81, 90, 90);

    while (sfRenderWindow_isOpen(self->window)) {
        while (sfRenderWindow_pollEvent(self->window, &self->event))
            window_event_update(self);
        window_clock_update(self);
        sfRenderWindow_clear(self->window, background);
        window_update_entity(self);
        sfRenderWindow_display(self->window);
        self->deltatime = ((float)sfClock_getElapsedTime(self->global_clock)
                .microseconds - (float)self->last_tick) / 10000;
        self->last_tick = sfClock_getElapsedTime(self->global_clock)
                .microseconds;
    }
    window_destroy(self);
    return 0;
}
