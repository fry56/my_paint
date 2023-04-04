/*
** EPITECH PROJECT, 2023
** button_events.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_scene.h>
#include <Class/t_sprite.h>
#include <canva/canva_structs.h>

void button_click(sprite *sprite_datas, window *window_datas)
{
    if (window_datas->event.type != sfEvtMouseButtonPressed)
        return;
    if (!sprite_is_mouse_click(sprite_datas, &window_datas->event))
        return;
    animator_play_animation(sprite_datas->animator, "btn_click");
    if (((button_s *)sprite_datas->sprite_datas)->click != NULL)
        ((button_s *)sprite_datas->sprite_datas)->click(sprite_datas);
}

void button_over(sprite *sprite_datas, window *window_datas)
{
    if (window_datas->event.type != sfEvtMouseMoved)
        return;
    if (!sprite_is_mouse_over(sprite_datas, &window_datas->event)) {
        animator_play_animation(sprite_datas->animator, "btn_default");
        return;
    }
    animator_play_animation(sprite_datas->animator, "btn_over");
}
