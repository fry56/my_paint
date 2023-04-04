/*
** EPITECH PROJECT, 2022
** new_scene.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <stdlib.h>
#include <Class/t_scene.h>
#include <Class/t_sprite.h>

static void init_new_scene(scene *new_scene, void (*load)(struct scene *)
    , void (*unload)(struct scene *))
{
    new_scene->list_event_update_functions = tlist_new();
    new_scene->list_clock_update_functions = tlist_new();
    new_scene->list_keys = tlist_new();
    new_scene->list_texts = tlist_new();
    new_scene->map_datas = thashmap_new(1024);
    new_scene->load = load;
    new_scene->unload = unload;
}

scene *new_scene(window *self, char *name
    , void (*load)(struct scene *)
    , void (*unload)(struct scene *))
{
    scene *new_scene = malloc(sizeof(scene));
    t_hashmap_node *new_scene_node;
    if (new_scene == NULL)
        return NULL;
    new_scene->list_sprites = tlist_new();
    if (new_scene->list_sprites == NULL) {
        free(new_scene);
        return NULL;
    }
    if ((new_scene_node = thashmap_add(self->map_scenes, name, new_scene))
        == NULL) {
        free(new_scene->list_sprites);
        free(new_scene);
        return NULL;
    }
    new_scene->host = self;
    if (self->actual_scene == NULL)
        self->actual_scene = new_scene_node;
    init_new_scene(new_scene, load, unload);
    return new_scene;
}
