/*
** EPITECH PROJECT, 2023
** drop_down_menu_toggle_show.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <canva/canva_structs.h>
#include <canva/canva_functions.h>

void drop_down_menu_toggle(sprite *sprite_datas)
{
    drop_down_menu_s *menu = ((button_s *)sprite_datas->sprite_datas)->datas;

    menu->toggle = !menu->toggle;
    menu->background->visible = menu->toggle;
    list_foreach(menu->list_buttons, node)
        button_set_visibility(node->value, menu->toggle);
}
