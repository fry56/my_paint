/*
** EPITECH PROJECT, 2023
** add_key_bind.c
** File description:
** desc
*/

#include <Utils/t_key.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include <t_mem.h>

bool scene_add_key_bind(scene *self, sfKeyCode key,
    sfEventType press_event, sfEventType unpress_envent)
{
    key_bind *new_key;

    if (scene_is_key_bind(self, key))
        return false;
    if ((new_key = tcalloc(1, sizeof(key_bind))) == NULL)
        return false;
    new_key->key = key;
    new_key->is_press = false;
    new_key->timestamp = 0;
    new_key->press_event = press_event;
    new_key->unpress_event = unpress_envent;
    tlist_add(self->list_keys, new_key);
    return true;
}
