/*
** EPITECH PROJECT, 2023
** init_layer_list.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"
#include "t_mem.h"
#include "t_string.h"

void set_layer_line_visibility(list_line_s *line, bool visibility)
{
    list_layer_s *line_datas = line->datas;

    line_datas->name_text->visible = visibility;
    check_box_set_visibility(line_datas->visible_check_box, visibility);
    button_set_visibility(line_datas->button_select, visibility);
}

void mouve_layer_line(list_line_s *line, sfVector2f pos)
{
    list_layer_s *line_datas = line->datas;

    sfText_move(line_datas->name_text->sf_text, pos);
    check_box_mouve(line_datas->visible_check_box, pos);
    button_mouve(line_datas->button_select, pos);
}

static void init_ligne_elem(scene *scene_datas, list_s *list,
    list_layer_s *new_layer)
{
    new_layer->name_text = new_text(scene_datas,
        tstr_compos("Layer %d", (int)list->list_ligne->length),
        "assets/font.ttf", (rgb){0, 0, 0});
    new_layer->visible_check_box = create_check_box(scene_datas,
        (sfVector2f){270, 19}, true, toggle_layer_visibility);
    ((check_box_s *)new_layer->visible_check_box->sprite_datas)->parent =
        new_layer;
    new_layer->button_select = create_button(scene_datas, (sfVector2f){190, 19},
        "assets/pen.png", select_layer);
    ((button_s *)new_layer->button_select->sprite_datas)->parent = new_layer;
    button_set_scale(new_layer->button_select, (sfVector2f){0.5f , 0.5f});
}

void add_layer_ligne_to_list(scene *scene_datas, sprite *list_sprite,
    sprite *buffer)
{
    list_s *list = list_sprite->sprite_datas;
    list_line_s *new_line = tcalloc(1, sizeof(list_line_s));
    list_layer_s *new_layer = tcalloc(1, sizeof(list_layer_s));

    new_line->host = list;
    new_line->datas = new_layer;
    new_layer = new_line->datas;
    new_layer->buffer = buffer;
    new_layer->host = new_line;
    init_ligne_elem(scene_datas, list, new_layer);
    new_line->set_visibility = set_layer_line_visibility;
    new_line->mouve = mouve_layer_line;
    new_line->destroy = destroy_layer_ligne;
    list_add_ligne(list_sprite, new_line);
}

void init_layer_list(scene *scene_datas)
{
    sprite *list_sprite = create_list(scene_datas, (sfVector2f){1600, 55},
        (sfVector2f){1.2f, 0.425f}, 3);
    list_s *list_datas = list_sprite->sprite_datas;
    sprite *button_add = create_button(scene_datas,
        (sfVector2f){1415, 55}, "assets/ajouter.png", add_layer);

    sprite_add_flag(list_sprite, "list_layer");
    tlist_add(list_datas->list_button, button_add);
}
