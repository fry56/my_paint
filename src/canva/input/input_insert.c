/*
** EPITECH PROJECT, 2023
** input_insert.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_scene.h>
#include <Class/t_sprite.h>
#include <canva/canva_structs.h>
#include <t_string.h>
#include <t_mem.h>

void update_indicator(input_s *input_datas)
{
    char *temp = input_datas->content;

    if (input_datas->length > input_datas->max_showed_char)
        temp += input_datas->length - input_datas->max_showed_char;
    free(input_datas->temp_text_string);
    input_datas->temp_text_string = tstr_cpy(NULL, temp);
    sfText_setString(input_datas->text_datas->sf_text,
        input_datas->temp_text_string);
}

static bool insert_char(sprite *sprite_datas,
    input_s *input_datas, sfKeyCode key)
{
    if (key == 57) {
        input_datas->content[input_datas->length] = ' ';
        return true;
    }
    if (key == -1) {
        input_datas->content[input_datas->length] = '.';
        return true;
    }
    if (key <= -1 || key >= 26)
        return false;
    input_datas->content[input_datas->length] =
        (char)(scene_is_key_press(sprite_datas->host,
        -1) ? key + 65 : key + 97);
    return true;
}

static bool insert_number(input_s *input_datas, sfKeyCode key)
{
    if (key <= 74 || key >= 85)
        return false;
    input_datas->content[input_datas->length] = (char)(key - 27);
    return true;
}

void input_insert(sprite *sprite_datas, input_s *input_datas, sfKeyCode key)
{
    if (input_datas->type == number_only) {
        if (!insert_number(input_datas, key))
            return;
    }
    if (input_datas->type == char_only) {
        if (!insert_char(sprite_datas, input_datas, key))
            return;
    }
    if (input_datas->type == char_number) {
        if (!insert_number(input_datas, key) &&
            !insert_char(sprite_datas, input_datas, key))
            return;
    }
    input_datas->length++;
    input_datas->content[input_datas->length] = '\0';
    update_indicator(input_datas);
    if (input_datas->on_change != NULL)
        input_datas->on_change(sprite_datas);
}

void remove_char(sprite *sprite_datas, input_s *input_datas)
{
    if (input_datas->length == 0)
        return;
    input_datas->content[input_datas->length - 1] = '\0';
    input_datas->length--;
    update_indicator(input_datas);
    if (input_datas->on_change != NULL)
        input_datas->on_change(sprite_datas);
}
