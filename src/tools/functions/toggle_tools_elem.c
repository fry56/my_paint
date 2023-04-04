/*
** EPITECH PROJECT, 2023
** toggle_tools_elm.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <functions.h>
#include <canva/canva_functions.h>

void toggle_tools_elem(tools_s *tools)
{
    tools->visibility = !tools->visibility;
    list_foreach(tools->list_button, node)
        button_set_visibility(node->value, tools->visibility);
    list_foreach(tools->list_text, node)
        ((text *)node->value)->visible = tools->visibility;
    list_foreach(tools->list_input, node)
        input_set_visibility(node->value, tools->visibility);
    list_foreach(tools->list_sprite, node)
        ((sprite *)node->value)->visible = tools->visibility;
}
