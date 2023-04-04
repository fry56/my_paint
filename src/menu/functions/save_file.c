/*
** EPITECH PROJECT, 2023
** save_file.c
** File description:
** desc
*/

#include "canva/canva_functions.h"
#include "canva/canva_structs.h"
#include <t_string.h>
#include <t_list.h>

static const char *file_extension[] = {
        "png",
        "jpg",
        "bmp",
        NULL
};

static bool is_valide_extension(char *extension)
{
    for (int i = 0; file_extension[i] != NULL; ++i) {
        if (tstr_cmp(extension, file_extension[i]) == 0)
            return true;
    }
    return false;
}

static bool check_input_datas(char *name)
{
    t_list *split;

    if (tstr_len(name) == 0)
        return false;
    split = tstr_split(name, ".");
    if (split->length == 1) {
        tlist_free(split);
        return false;
    }
    if (!is_valide_extension(split->tail->value))
        return false;
    tlist_free(split);

    return true;
}

static sfImage *layer_compose(paint_s *paint_datas)
{
    frame_buffer_s *temp = create_frame_buffer(paint_datas->width,
        paint_datas->height);
    sfTexture *temp_texture;
    sfImage *new_img;

    list_foreach(paint_datas->list_frame_buffer, node) {
        frame_buffer_compos(temp, ((sprite *) node->value)->sprite_datas);
    }

    temp_texture = sfTexture_create(paint_datas->width, paint_datas->height);
    sfTexture_updateFromPixels(temp_texture,temp->buf,
        paint_datas->width, paint_datas->height, 0,0);
    new_img = sfTexture_copyToImage(temp_texture);
    sfTexture_destroy(temp_texture);
    return new_img;
}

void save_file(sprite *sprite_datas)
{
    paint_s *paint_datas = thashmap_get(
        sprite_datas->host->map_datas, "paint")->value;
    sprite *modal = sprite_get_by_flag(sprite_datas->host, "modal_save_file");
    char *name = ((input_s *)sprite_get_by_flag(
        sprite_datas->host, "modal_save_file_name")->sprite_datas)->content;

    if (!check_input_datas(name))
        return;
    sfImage_saveToFile(layer_compose(paint_datas), name);
    modal_toggle(modal);
}

void save_file_exec(sprite *sprite_datas)
{
    paint_s *paint_datas = thashmap_get(
            sprite_datas->host->map_datas, "paint")->value;
    sprite *modal = sprite_get_by_flag(sprite_datas->host, "modal_save_file");
    if (!paint_datas->init)
        return;
    modal_toggle(modal);
}
