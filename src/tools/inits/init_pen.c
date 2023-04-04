/*
** EPITECH PROJECT, 2023
** init_pen.c
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

static void init_color(scene *scene_datas, tools_s *new_tool_pen)
{
    sprite *button_red = create_button(scene_datas,
        (sfVector2f){1860, 400}, "assets/red_pen.png", pen_change_color);
    sprite *button_bleu = create_button(scene_datas,
        (sfVector2f){1860, 500}, "assets/bleu_pen.png", pen_change_color);
    sprite *button_pink = create_button(scene_datas,
        (sfVector2f){1860, 600}, "assets/pink_pen.png", pen_change_color);
    sprite *button_green = create_button(scene_datas,
        (sfVector2f){1860, 700}, "assets/green_pen.png", pen_change_color);
    sprite *button_orange = create_button(scene_datas,
        (sfVector2f){1860, 800}, "assets/orange_pen.png", pen_change_color);
    sprite_add_flag(button_green, "button_green");
    sprite_add_flag(button_orange, "button_orange");
    sprite_add_flag(button_pink, "button_pink");
    sprite_add_flag(button_bleu, "button_bleu");
    sprite_add_flag(button_red, "button_red");
    tlist_add(new_tool_pen->list_button, button_red);
    tlist_add(new_tool_pen->list_button, button_bleu);
    tlist_add(new_tool_pen->list_button, button_pink);
    tlist_add(new_tool_pen->list_button, button_green);
    tlist_add(new_tool_pen->list_button, button_orange);
}

static void init_pen_menu(scene *scene_datas, tools_s *new_tool_pen)
{
    text *text_size = new_text(scene_datas, "Thickness",
        "assets/font.ttf", (rgb){0, 0, 0});
    sprite *size = create_input(scene_datas, number_only,
        (sfVector2f){1860, 290}, (sfVector2f){1.10f, 1});
    sprite *img = new_sprite(scene_datas, "assets/pen.png", 11);
    ((input_s *)size->sprite_datas)->on_change = set_pen_thickness;

    sfSprite_setPosition(img->sf_sprite, (sfVector2f){1860, 170});
    input_set_default_value(size, "5");
    sfText_setPosition(text_size->sf_text, (sfVector2f){1800, 220});
    sfText_setCharacterSize(text_size->sf_text, 28);
    tlist_add(new_tool_pen->list_text, text_size);
    tlist_add(new_tool_pen->list_input, size);
    tlist_add(new_tool_pen->list_sprite, img);
    init_color(scene_datas, new_tool_pen);
}

void init_pen(int index, scene *scene_datas, paint_s *paint_datas)
{
    tools_s *new_tool_pen = tcalloc(1, sizeof(tools_s));

    if (new_tool_pen == NULL)
        return;
    new_tool_pen->visibility = true;
    new_tool_pen->list_sprite = tlist_new();
    new_tool_pen->list_input = tlist_new();
    new_tool_pen->list_text = tlist_new();
    new_tool_pen->list_button = tlist_new();
    new_tool_pen->type = pen;
    new_tool_pen->datas = tcalloc(1, sizeof(tool_pen_s));
    ((tool_pen_s *)new_tool_pen->datas)->color = sfRed;
    ((tool_pen_s *)new_tool_pen->datas)->thickness = 5;
    new_tool_pen->mouse_click_actions = pen_click;
    paint_datas->tools[index] = new_tool_pen;
    init_pen_menu(scene_datas, new_tool_pen);
}
