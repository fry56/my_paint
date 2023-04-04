/*
** EPITECH PROJECT, 2022
** map_new.c
** File description:
** desc
*/

#include <t_map.h>
#include <stdlib.h>
#include <t_mem.h>

t_map *tmap_new(void)
{
    t_map *new_map = tcalloc(1, sizeof(t_map));

    return new_map;
}
