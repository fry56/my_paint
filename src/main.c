/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_scene.h>
#include <functions.h>
#include <t_mem.h>
#include <canva/canva_structs.h>
#include <t_string.h>

static binded_ket_s key_binde[6] = {
        {0, sfEvtMouseButtonPressed, sfEvtMouseButtonReleased},
        {sfKeyLeft, sfEvtKeyPressed, sfEvtKeyReleased},
        {sfKeyRight, sfEvtKeyPressed, sfEvtKeyReleased},
        {sfKeyUp, sfEvtKeyPressed, sfEvtKeyReleased},
        {sfKeyDown, sfEvtKeyPressed, sfEvtKeyReleased}
};

void init_paint(scene *scene_datas)
{
    paint_s *new_paint = tcalloc(1, sizeof(paint_s));

    if (new_paint == NULL)
        return;
    new_paint->width = 0;
    new_paint->height = 0;
    new_paint->init = false;
    new_paint->list_frame_buffer = tlist_new();
    init_tools(scene_datas, new_paint);
    scene_add_clock_update_function(scene_datas, mouse_layer_actions);
    scene_add_clock_update_function(scene_datas, mouve_layer);
    scene_add_event_update_function(scene_datas, resize_window_event);
    for (int i = 0; i < 6; ++i)
        scene_add_key_bind(scene_datas, key_binde[i].key,
            key_binde[i].press_event, key_binde[i].unpress_event);
    thashmap_add(scene_datas->map_datas, "paint", new_paint);
}

int main(void)
{
    window *window_datas;
    scene *scene_datas;

    if (!assets_checker())
        return 84;
    window_datas = new_window("Paint", (sfVideoMode){1920, 1080, 32});
    scene_datas = new_scene(window_datas, "main", NULL, NULL);
    sfRenderWindow_setKeyRepeatEnabled(window_datas->window, sfFalse);
    window_datas->global_clock = sfClock_create();
    init_menu(scene_datas);
    init_paint(scene_datas);
    start_window(window_datas);
    return 0;
}
