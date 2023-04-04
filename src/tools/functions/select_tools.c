/*
** EPITECH PROJECT, 2023
** select_tools.c
** File description:
** desc
*/

#include <struct.h>
#include <tools/tools_structs.h>
#include <t_mem.h>
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include <canva/canva_structs.h>
#include <canva/canva_functions.h>
#include <t_string.h>

void select_pen_tool(sprite *button)
{
    paint_s *paint_datas = thashmap_get(button->host->map_datas,
        "paint")->value;

    if (paint_datas->tool_index == 0)
        return;
    toggle_tools_elem(paint_datas->tools[paint_datas->tool_index]);
    paint_datas->tool_index = 0;
    toggle_tools_elem(paint_datas->tools[paint_datas->tool_index]);
}

void select_eraser_tool(sprite *button)
{
    paint_s *paint_datas = thashmap_get(button->host->map_datas,
        "paint")->value;

    if (paint_datas->tool_index == 1)
        return;
    toggle_tools_elem(paint_datas->tools[paint_datas->tool_index]);
    paint_datas->tool_index = 1;
    toggle_tools_elem(paint_datas->tools[paint_datas->tool_index]);
}
