/*
** EPITECH PROJECT, 2023
** eraser_click.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <functions.h>
#include <t_mem.h>
#include <tools/tools_structs.h>

void eraser_click(paint_s *paint_datas, sfVector2f pos)
{
    uint32_t column = 0;
    tool_eraser_s *eraser = paint_datas->tools[paint_datas->tool_index]->datas;
    sfVector2f temp_pos;

    for (uint32_t i = 0; i < eraser->thickness; column++) {
        temp_pos = (sfVector2f){pos.x + (float)column, pos.y + (float)i};
        set_frame_buffer_pixel_color(
            paint_datas->actual_frame_buffer->sprite_datas,
            temp_pos, sfWhite);
        if (column == eraser->thickness) {
            i++;
            column = -1;
        }
    }
    sfTexture_updateFromPixels(paint_datas->actual_frame_buffer->sf_texture,
        ((frame_buffer_s *)paint_datas->actual_frame_buffer->sprite_datas)->buf,
        paint_datas->width, paint_datas->height, 0, 0);
}
