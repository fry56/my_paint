/*
** EPITECH PROJECT, 2023
** init_eraser.c
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

static void init_eraser_menu(scene *scene_datas, tools_s *new_tool_pen)
{
    text *text_size = new_text(scene_datas, "Thickness",
        "assets/font.ttf", (rgb){0, 0, 0});
    sprite *size = create_input(scene_datas, number_only,
        (sfVector2f){1860, 290}, (sfVector2f){1.10f, 1});
    sprite *img = new_sprite(scene_datas, "assets/eraser.png", 11);
    ((input_s *)size->sprite_datas)->on_change = set_eraser_thickness;

    sfSprite_setPosition(img->sf_sprite, (sfVector2f){1860, 170});
    input_set_default_value(size, "5");
    sfText_setPosition(text_size->sf_text, (sfVector2f){1800, 220});
    sfText_setCharacterSize(text_size->sf_text, 28);
    tlist_add(new_tool_pen->list_text, text_size);
    tlist_add(new_tool_pen->list_input, size);
    tlist_add(new_tool_pen->list_sprite, img);
}

void init_eraser(int index, scene *scene_datas, paint_s *paint_datas)
{
    tools_s *new_tool_eraser = tcalloc(1, sizeof(tools_s));

    if (new_tool_eraser == NULL)
        return;
    new_tool_eraser->visibility = true;
    new_tool_eraser->list_sprite = tlist_new();
    new_tool_eraser->list_input = tlist_new();
    new_tool_eraser->list_text = tlist_new();
    new_tool_eraser->list_button = tlist_new();
    new_tool_eraser->type = eraser;
    new_tool_eraser->datas = tcalloc(1, sizeof(tool_pen_s));
    new_tool_eraser->mouse_click_actions = eraser_click;
    ((tool_eraser_s *)new_tool_eraser->datas)->thickness = 5;
    paint_datas->tools[index] = new_tool_eraser;
    init_eraser_menu(scene_datas, new_tool_eraser);
    toggle_tools_elem(new_tool_eraser);
}
