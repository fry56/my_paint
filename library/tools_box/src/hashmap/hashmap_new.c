/*
** EPITECH PROJECT, 2023
** hashmap_new.c
** File description:
** desc
*/

#include <t_hashmap.h>
#include <stdlib.h>
#include <t_mem.h>
#include <t_ctype.h>

t_hashmap *thashmap_new(u32 size)
{
    t_hashmap *new_hashmap = tcalloc(1, sizeof(t_hashmap));

    if (new_hashmap == NULL)
        return NULL;
    size = size + (int)(size * 0.75);
    new_hashmap->size = size;
    new_hashmap->node_elements = 0;
    new_hashmap->child_elements = 0;
    new_hashmap->map = tcalloc(1, (size * sizeof(t_hashmap_node *)));
    if (new_hashmap->map == NULL) {
        free(new_hashmap);
        return NULL;
    }
    return new_hashmap;
}
