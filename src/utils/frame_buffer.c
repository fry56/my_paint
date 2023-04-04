/*
** EPITECH PROJECT, 2022
** framebuffer.c
** File description:
** desc
*/

#include <struct.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Export.h>
#include <stdlib.h>
#include <t_mem.h>
#include <t_ctype.h>

frame_buffer_s *create_frame_buffer(uint32_t width, uint32_t height)
{
    frame_buffer_s *frame = malloc(sizeof(frame_buffer_s));

    frame->width = width;
    frame->height = height;
    frame->buf = tcalloc(height * width * 4, sizeof(sfUint8));
    return frame;
}

void test_put_pixel(frame_buffer_s *dest, sfUint32 color, sfUint32 x,
    sfUint32 y)
{
    sfUint8 *buf = dest->buf + (dest->width * y + x) * 4;
    color_t c = { .raw = color };
    uint16_t b;

    if (c.a == 0)
        return;
    if (c.a == 255) {
        buf[3] = 255;
        buf[2] = c.b;
        buf[1] = c.g;
        buf[0] = c.r;
    } else {
        b = 256 - c.a;
        buf[3] = 255;
        buf[2] = (c.b * b + buf[2] * c.a) >> 8;
        buf[1] = (c.g * b + buf[1] * c.a) >> 8;
        buf[0] = (c.r * b + buf[0] * c.a) >> 8;
    }
}

frame_buffer_s *frame_buffer_compos(frame_buffer_s *dest, frame_buffer_s *src)
{
    for (sfUint32 i = 0; i < dest->width * dest->height; i++) {
        sfUint32 color = *(sfUint32 *)(src->buf + i * 4);
        sfUint32 x = i % dest->width;
        sfUint32 y = i / dest->width;
        test_put_pixel(dest, color, x, y);
    }
    return dest;
}

void set_frame_buffer_pixel_color(frame_buffer_s *frame,
    sfVector2f pos, sfColor color)
{
    tsize_t start_point = frame->width * (int)pos.y + (int)pos.x;
    sfUint32 *ptr = (sfUint32 *)&color;

    if (pos.x > (float)frame->width || pos.y > (float)frame->height)
        return;
    if (pos.x < 0 || pos.y < 0)
        return;
    ((sfUint32 *)frame->buf)[start_point] = *ptr;
}
