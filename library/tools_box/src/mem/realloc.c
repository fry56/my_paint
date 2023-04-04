/*
** EPITECH PROJECT, 2022
** realloc.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <t_mem.h>

void *trealloc(void *tmem, tsize_t size, tsize_t new_size)
{
    void *newmem;

    if (!new_size) {
        free(tmem);
        return NULL;
    }
    if (tmem == NULL)
        return (tcalloc(1, new_size));
    newmem = tcalloc(1, new_size);
    if (newmem == NULL)
        return NULL;
    tmemcpy(newmem, tmem, size);
    free(tmem);
    return newmem;
}
