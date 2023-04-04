/*
** EPITECH PROJECT, 2023
** eraser_thickness.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <functions.h>
#include <tools/tools_structs.h>
#include <canva/canva_structs.h>
#include <t_string.h>

void set_eraser_thickness(sprite *sprite_datas)
{
    paint_s *paint_datas = thashmap_get(sprite_datas->host->map_datas,
        "paint")->value;
    tool_eraser_s *eraser = paint_datas->tools[paint_datas->tool_index]->datas;
    input_s *input_datas = sprite_datas->sprite_datas;
    int thickness = tstr_to_number(input_datas->content);

    if (thickness <= 40) {
        eraser->thickness = tstr_to_number(input_datas->content);
        sfText_setColor(input_datas->text_datas->sf_text,
            sfColor_fromRGB(131, 145, 146));
    } else {
        sfText_setColor(input_datas->text_datas->sf_text, sfRed);
    }
}
