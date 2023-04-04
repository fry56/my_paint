/*
** EPITECH PROJECT, 2022
** new_text.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_text.h>
#include <stdlib.h>
#include <t_string.h>

void init_new_text(text *new_text, char *content, rgb rgb)
{
    new_text->visible = true;
    new_text->sf_text = sfText_create();
    new_text->sf_color = sfColor_fromRGB(rgb.red, rgb.green, rgb.blue);
    sfText_setFont(new_text->sf_text, new_text->sf_font);
    sfText_setString(new_text->sf_text, content);
    sfText_setColor(new_text->sf_text, new_text->sf_color);
    new_text->list_flags = tlist_new();
}

text *new_text(scene *scene_datas, char *content
    , char *font, rgb rgb)
{
    text *new_text = malloc(sizeof(text));
    t_list_node *new_text_node;

    if (new_text == NULL)
        return NULL;
    if ((new_text_node = tlist_add(scene_datas->list_texts
        , new_text)) == NULL) {
        free(new_text);
        return NULL;
    }
    if (font == NULL)
        font = "assets/font/Fruit Days.ttf";
    if ((new_text->sf_font = sfFont_createFromFile(font)) == NULL) {
        free(new_text);
        return NULL;
    }
    new_text->host = scene_datas;
    new_text->text_node = new_text_node;
    init_new_text(new_text, content, rgb);
    return new_text;
}
