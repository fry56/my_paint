/*
** EPITECH PROJECT, 2023
** create_drop_down_menu.c
** File description:
** desc
*/

#include <canva/canva_structs.h>
#include <canva/canva_functions.h>
#include <t_mem.h>

sprite *create_drop_down_menu(scene *scene_datas, sfVector2f pos,
    char *img_path)
{
    drop_down_menu_s *menu = tcalloc(1, sizeof(drop_down_menu_s));

    if (menu == NULL)
        return NULL;
    menu->toggle = false;
    menu->button = create_button(scene_datas, pos, img_path,
        drop_down_menu_toggle);
    ((button_s *)menu->button->sprite_datas)->datas = menu;
    menu->list_buttons = tlist_new();
    menu->background = new_sprite(scene_datas,
        "assets/background_drop_down.png", 10);
    menu->background->visible = false;
    sprite_set_fixed_origin(menu->background, (sfVector2f){ 0, 0});
    sfSprite_setPosition(menu->background->sf_sprite,
        (sfVector2f){pos.x - 10, pos.y + 40});
    sprite_add_flag(menu->button, "canva_drop_down_menu");
    return menu->button;
}
