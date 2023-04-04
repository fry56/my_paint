/*
** EPITECH PROJECT, 2023
** init_button_animations.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <functions.h>

void init_button_animation(window *window_datas)
{
    animation *defaults = new_animation("btn_default", "assets/button.png",
        true, 1);
    animation *over = new_animation("btn_over", "assets/button.png",
        true, 1);
    animation *click = new_animation("btn_click", "assets/button.png",
        false, 10);

    animation_add_frame(defaults, (sfIntRect){0, 0, 64, 57});
    animation_add_frame(over, (sfIntRect){128, 0, 64, 57});
    animation_add_frame(click, (sfIntRect){192, 0, 64, 57});
    thashmap_add(window_datas->map_global_datas, "anim_btn_default", defaults);
    thashmap_add(window_datas->map_global_datas, "anim_btn_over", over);
    thashmap_add(window_datas->map_global_datas, "anim_btn_click", click);
}
