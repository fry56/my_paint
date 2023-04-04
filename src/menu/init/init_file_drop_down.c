/*
** EPITECH PROJECT, 2023
** init_file_drop_down.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"
#include "t_mem.h"

void init_file_drop_down(scene *scene_datas)
{
    drop_down_menu_s *file_menu = ((button_s *)create_drop_down_menu(scene_datas
        , (sfVector2f){30, 30}
        , "assets/files.png")->sprite_datas)->datas;
    button_s *new_file = create_button(scene_datas, (sfVector2f){0,0}
        , "assets/new-file.png", new_file_exec)->sprite_datas;
    button_s *open_file = create_button(scene_datas, (sfVector2f){0,0}
        , "assets/open-folder.png", NULL)->sprite_datas;
    button_s *save_file = create_button(scene_datas, (sfVector2f){0,0}
        , "assets/save.png", save_file_exec)->sprite_datas;

    add_button_to_drop_down(file_menu, new_file);
    add_button_to_drop_down(file_menu, open_file);
    add_button_to_drop_down(file_menu, save_file);
}
