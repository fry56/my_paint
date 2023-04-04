/*
** EPITECH PROJECT, 2023
** layer_list_functions.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"
#include "t_mem.h"
#include <t_string.h>
#include <canva/canva_structs.h>

void destroy_layer_ligne(list_line_s *line)
{
    list_layer_s *layer = line->datas;

    text_destroy(layer->name_text);
    destroy_check_box(layer->visible_check_box);
    destroy_button(layer->button_select);
}
