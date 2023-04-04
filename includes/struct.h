/*
** EPITECH PROJECT, 2023
** paint_struct.h
** File description:
** desc
*/
#ifndef paint_struct
    #define paint_struct

    #include <Class/t_window.h>
    #include <Class/t_sprite.h>
    #include <Class/t_text.h>
    #include <t_ctype.h>
    #include <tools/tools_structs.h>
    #include <config.h>

    typedef struct frame_buffer_t {
        uint32_t width;
        uint32_t height;
        sfUint8 *buf;
    } frame_buffer_s;

    typedef struct paint_t {
        bool init;
        float zoom;
        uint32_t width;
        uint32_t height;
        sprite *actual_frame_buffer;
        t_list *list_frame_buffer;
        uint8_t tool_index;
        struct tools_t *tools[NBR_TOOLS];
    } paint_s;

    typedef struct tools_t {
        tool_type_e type;
        bool visibility;
        void *datas;
        void (*mouse_wheel_actions)(struct paint_t *, sfVector2f pos);
        void (*mouse_click_actions)(struct paint_t *, sfVector2f pos);
        t_list *list_text;
        t_list *list_button;
        t_list *list_input;
        t_list *list_sprite;
    } tools_s;

    typedef struct list_layer_t {
        text *name_text;
        struct list_line_t *host;
        sprite *visible_check_box;
        sprite *button_rm;
        sprite *button_select;
        sprite *buffer;
    } list_layer_s;

    typedef struct binded_key_t {
        sfKeyCode key;
        sfEventType press_event;
        sfEventType unpress_event;
    } binded_ket_s;

    typedef union {
        sfUint32 raw;
        struct {
            sfUint8 r;
            sfUint8 g;
            sfUint8 b;
            sfUint8 a;
        };
    } color_t;

#endif //paint_struct
