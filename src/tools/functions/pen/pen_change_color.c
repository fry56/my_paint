/*
** EPITECH PROJECT, 2023
** pen_change_color.c
** File description:
** desc
*/

#include <struct.h>
#include <tools/tools_structs.h>
#include <Class/t_window.h>
#include <canva/canva_structs.h>

void pen_change_color(sprite *button)
{
    paint_s *paint_datas = thashmap_get(button->host->map_datas,
        "paint")->value;
    if (sprite_have_flag(button, "button_red")) {
        ((tool_pen_s *)paint_datas->tools[0]->datas)->color = sfRed;
    }
    if (sprite_have_flag(button, "button_bleu")) {
        ((tool_pen_s *)paint_datas->tools[0]->datas)->color = sfBlue;
    }
    if (sprite_have_flag(button, "button_pink")) {
        ((tool_pen_s *)paint_datas->tools[0]->datas)->color = sfMagenta;
    }
    if (sprite_have_flag(button, "button_green")) {
        ((tool_pen_s *)paint_datas->tools[0]->datas)->color = sfGreen;
    }
    if (sprite_have_flag(button, "button_orange")) {
        ((tool_pen_s *)paint_datas->tools[0]->datas)->color =
        sfColor_fromRGB(220, 118, 51);
    }
}
