/*
** EPITECH PROJECT, 2023
** input_events.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_sprite.h>
#include <canva/canva_structs.h>
#include <t_mem.h>
#include <t_string.h>
#include <canva/canva_functions.h>

void input_indicator(sprite *sprite_datas, sfClock *clock_datas)
{
    input_s *input_datas = sprite_datas->sprite_datas;
    int64_t timestamp = sfClock_getElapsedTime(clock_datas).microseconds;
    char *temp;

    if (timestamp <= input_datas->last_tick || !input_datas->select)
        return;
    if (input_datas->indicator_toggle) {
        sfText_setString(input_datas->text_datas->sf_text,
            input_datas->temp_text_string);
    } else {
        temp = tstr_compos("%s|", input_datas->temp_text_string);
        sfText_setString(input_datas->text_datas->sf_text,
            temp);
        free(temp);
    }
    input_datas->indicator_toggle = !input_datas->indicator_toggle;
    input_datas->last_tick =
        sfClock_getElapsedTime(clock_datas).microseconds + 25 * 10000;
}

void input_key_press(sprite *sprite_datas, window *window_datas)
{
    input_s *input_datas = sprite_datas->sprite_datas;
    sfKeyCode key;

    if (window_datas->event.type != sfEvtKeyPressed || !input_datas->select)
        return;
    key = window_datas->event.key.code;
    if (key == 59) {
        remove_char(sprite_datas, input_datas);
        return;
    }
    if (input_datas->max_char == input_datas->length)
        return;
    input_insert(sprite_datas, input_datas, key);
}

void input_click(sprite *sprite_datas, window *window_datas)
{
    input_s *input_datas = sprite_datas->sprite_datas;
    if (window_datas->event.type != sfEvtMouseButtonPressed)
        return;
    if (!sprite_is_mouse_click(sprite_datas, &window_datas->event)) {
        if (!input_datas->select)
            return;
        sfText_setColor(input_datas->text_datas->sf_text, sfBlack);
        input_datas->select = false;
        sfText_setString(input_datas->text_datas->sf_text,
            input_datas->temp_text_string);
        if (input_datas->length == 0 && input_datas->type == number_only)
            input_insert(sprite_datas, input_datas, 75);
        return;
    }
    sfText_setColor(input_datas->text_datas->sf_text,
        sfColor_fromRGB(131, 145, 146));
    input_datas->select = true;
    if (input_datas->on_select != NULL)
        input_datas->on_select(sprite_datas);
}

void input_over(sprite *sprite_datas, window *window_datas)
{
    input_s *input_datas = sprite_datas->sprite_datas;

    if (window_datas->event.type != sfEvtMouseMoved)
        return;
    if (input_datas->select)
        return;
    if (!sprite_is_mouse_over(sprite_datas, &window_datas->event)) {
        sfText_setColor(input_datas->text_datas->sf_text, sfBlack);
        return;
    }
    sfText_setColor(input_datas->text_datas->sf_text,
        sfColor_fromRGB(170, 183, 184));
}
