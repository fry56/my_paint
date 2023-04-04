/*
** EPITECH PROJECT, 2022
** update.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>

void window_clock_update(window *window_datas)
{
    scene *actual_scene;

    if (window_datas->actual_scene == NULL)
        return;
    actual_scene = window_datas->actual_scene->value;
    list_foreach(actual_scene->list_clock_update_functions, node) {
        ((void (*)(scene *scene_datas, sfClock *clock))node
                ->value)(actual_scene, window_datas->global_clock);
    }
    clock_update_sprite(actual_scene, window_datas->global_clock);
}

void window_event_update(window *window_datas)
{
    scene *actual_scene;

    if (window_datas->event.type == sfEvtClosed)
        sfRenderWindow_close(window_datas->window);
    if (window_datas->actual_scene == NULL)
        return;
    actual_scene = window_datas->actual_scene->value;
    scene_update_key(actual_scene, window_datas);
    list_foreach(actual_scene->list_event_update_functions, node) {
        ((void (*)(scene *scene_datas, struct window *))node
            ->value)(actual_scene, window_datas);
    }
    event_update_sprite(actual_scene, window_datas);
}
