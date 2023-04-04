/*
** EPITECH PROJECT, 2023
** init_tools.c
** File description:
** desc
*/

#include <struct.h>
#include <functions.h>

void init_tools(scene *scene_datas, paint_s *paint_datas)
{
    paint_datas->tool_index = 0;
    init_pen(0, scene_datas, paint_datas);
    init_eraser(1, scene_datas, paint_datas);
}
