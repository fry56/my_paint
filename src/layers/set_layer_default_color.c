/*
** EPITECH PROJECT, 2023
** set_layer_default_color.c
** File description:
** desc
*/

#include <struct.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Export.h>
#include <t_ctype.h>

void set_layer_default_color(frame_buffer_s *frame, sfColor color)
{
    sfUint32 *ptr = (sfUint32 *)&color;

    for (uint32_t i = 0; i < frame->width * frame->height; ++i)
        ((sfUint32 *)frame->buf)[i] = *ptr;
}
