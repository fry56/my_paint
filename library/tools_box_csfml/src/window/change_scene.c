/*
** EPITECH PROJECT, 2022
** set_scene.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <stdlib.h>

bool window_change_scene(window *self, char *scene_name)
{
    t_hashmap_node *new_scene = thashmap_get(self->map_scenes, scene_name);

    if (new_scene == NULL)
        return false;
    self->actual_scene = new_scene;
    return true;
}
