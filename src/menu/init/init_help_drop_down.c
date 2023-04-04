/*
** EPITECH PROJECT, 2023
** init_help_drop_down.c
** File description:
** desc
*/
#include "canva/canva_functions.h"
#include "canva/canva_structs.h"
#include "t_mem.h"

void init_help_drop_down(scene *scene_datas)
{
    drop_down_menu_s *file_menu = ((button_s *)create_drop_down_menu(scene_datas
            , (sfVector2f){150, 30}
            , "assets/files.png")->sprite_datas)->datas;
    button_s *about = create_button(scene_datas, (sfVector2f){0,0}
            , "assets/info.png", about_exec)->sprite_datas;
    button_s *help = create_button(scene_datas, (sfVector2f){0,0}
            , "assets/question.png", help_exec)->sprite_datas;

    add_button_to_drop_down(file_menu, about);
    add_button_to_drop_down(file_menu, help);
}
