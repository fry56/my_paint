/*
** EPITECH PROJECT, 2023
** init_zoom.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"
#include "t_mem.h"

void init_zoom(scene *scene_datas)
{
    create_button(scene_datas, (sfVector2f){1880,30}
        , "assets/zoom_more.png", zoom_more_exec);
    create_button(scene_datas, (sfVector2f){1880,80}
        , "assets/zoom_less.png", zoom_less_exec);
}
