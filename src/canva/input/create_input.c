/*
** EPITECH PROJECT, 2023
** create_input.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <canva/canva_structs.h>
#include <canva/canva_functions.h>
#include <t_mem.h>

static void init_input_event(sprite *input_sprite)
{
    sprite_add_event_update_function(input_sprite, input_over);
    sprite_add_event_update_function(input_sprite, input_click);
    sprite_add_event_update_function(input_sprite, input_key_press);
    sprite_add_clock_update_function(input_sprite, input_indicator);
}

static void init_input_datas(input_s *input)
{
    int size = input->type == number_only ? 6 : 40;

    input->select = false;
    input->max_char = size;
    input->content = tcalloc(1, size);
    input->temp_text_string = tcalloc(1, size);
    input->length = 0;
    input->last_tick = 0;
    input->indicator_toggle = false;
    input->on_change = NULL;
    input->on_select = NULL;
}

sprite *create_input(scene *scene_datas, input_type_e type,
    sfVector2f pos, sfVector2f scale)
{
    sprite *input_sprite = new_sprite(scene_datas, "assets/input.png", 10);
    input_s *input = tcalloc(1, sizeof(input_s));
    sfFloatRect bound;

    sfSprite_setScale(input_sprite->sf_sprite, scale);
    sfSprite_setPosition(input_sprite->sf_sprite, pos);
    bound = sfSprite_getGlobalBounds(input_sprite->sf_sprite);
    sprite_add_flag(input_sprite, "canva_input");
    input_sprite->sprite_datas = input;
    input->type = type;
    input->max_showed_char = (int)(bound.width / 30);
    input->text_datas = new_text(scene_datas, "", "assets/font.ttf",
        (rgb){0, 0, 0});
    init_input_datas(input);
    init_input_event(input_sprite);
    sfText_setPosition(input->text_datas->sf_text,
        (sfVector2f){bound.left + bound.width / 4,
        pos.y - (bound.height / 2) + 8});
    return input_sprite;
}
