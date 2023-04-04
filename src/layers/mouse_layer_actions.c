/*
** EPITECH PROJECT, 2023
** mouse_layer_actions.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_scene.h>
#include <functions.h>
#include <t_mem.h>

static void get_mouse_pos(window *window_datas, sfVector2f *pos,
    paint_s *paint_datas)
{
    sfVector2u size = sfRenderWindow_getSize(window_datas->window);
    sfVideoMode default_size = window_datas->mode;
    float y_a = ((float)size.y / (float)default_size.height);
    sfVector2f layer_pos = sfSprite_getPosition(
        paint_datas->actual_frame_buffer->sf_sprite);

    if (window_datas->event.type == sfEvtMouseButtonPressed) {
        *pos = (sfVector2f){((float)window_datas->event.mouseButton.x -
            layer_pos.x) / paint_datas->zoom,
            ((float)window_datas->event.mouseButton.y -
            (layer_pos.y * y_a)) / paint_datas->zoom};
    } else {
        *pos = (sfVector2f) {((float)window_datas->event.mouseMove.x -
            layer_pos.x) / paint_datas->zoom,
            ((float)window_datas->event.mouseMove.y -
            (layer_pos.y * y_a)) / paint_datas->zoom};
    }
}

void mouse_layer_actions(scene *scene_datas, sfClock *clock_datas UNUSED)
{
    paint_s *paint_datas;
    sfVector2f pos;

    if (scene_datas->host->event.type != sfEvtMouseButtonPressed &&
        scene_datas->host->event.type != sfEvtMouseMoved)
        return;
    if (!scene_is_key_press(scene_datas, 0))
        return;
    paint_datas = thashmap_get(scene_datas->map_datas, "paint")->value;
    if (!paint_datas->init)
        return;
    get_mouse_pos(scene_datas->host, &pos, paint_datas);
    if (pos.x < 0 || pos.y < 0 || pos.x > (float)paint_datas->width ||
        pos.y > (float)paint_datas->height)
        return;
    paint_datas->tools[paint_datas->tool_index]
        ->mouse_click_actions(paint_datas, pos);
}
