/*
** EPITECH PROJECT, 2023
** init_edit_drop_down.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"
#include "t_mem.h"

void init_edit_drop_down(scene *scene_datas)
{
    drop_down_menu_s *edit_menu = ((button_s *)create_drop_down_menu(scene_datas
            , (sfVector2f){90, 30}
            , "assets/art.png")->sprite_datas)->datas;
    button_s *pen = create_button(scene_datas, (sfVector2f){0,0}
            , "assets/pen.png", select_pen_tool)->sprite_datas;
    button_s *eraser = create_button(scene_datas, (sfVector2f){0,0}
            , "assets/eraser.png", select_eraser_tool)->sprite_datas;

    add_button_to_drop_down(edit_menu, pen);
    add_button_to_drop_down(edit_menu, eraser);
}
