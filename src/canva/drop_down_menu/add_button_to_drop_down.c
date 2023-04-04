/*
** EPITECH PROJECT, 2023
** add_button_to_drop_down.c
** File description:
** desc
*/

#include <canva/canva_structs.h>
#include <canva/canva_functions.h>
#include <t_mem.h>

void add_button_to_drop_down(drop_down_menu_s *menu, button_s *button)
{
    sfVector2f pos = sfSprite_getPosition(menu->background->sf_sprite);

    sfSprite_setPosition(button->host->sf_sprite,
        (sfVector2f){pos.x + 38, pos.y + 40 +
        (float)(menu->list_buttons->length * 58)});
    sfSprite_setPosition(button->img->sf_sprite,
        (sfVector2f){pos.x + 38, pos.y + 40 +
        (float)(menu->list_buttons->length * 58)});
    tlist_add(menu->list_buttons, button->host);
    sfSprite_setScale(menu->background->sf_sprite,
    (sfVector2f){0.6f, 0.5f * (float)menu->list_buttons->length});
    button->host->visible = menu->toggle;
    button->img->visible = menu->toggle;
}
