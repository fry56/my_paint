/*
** EPITECH PROJECT, 2023
** canva_structs.h
** File description:
** desc
*/
#ifndef canva_structs
    #define canva_structs

    #include <Class/t_sprite.h>
    #include <Class/t_text.h>

    typedef enum input_type_t {
        number_only,
        char_only,
        char_number
    } input_type_e;

    typedef struct input_t {
        input_type_e type;
        void *parent;
        char *content;
        char *temp_text_string;
        uint32_t max_char;
        uint32_t length;
        text *text_datas;
        sfInt64 last_tick;
        uint32_t max_showed_char;
        void (*on_change)(sprite *);
        void (*on_select)(sprite *);
        bool indicator_toggle;
        bool select;
    } input_s;

    typedef struct drop_down_menu_t {
        bool toggle;
        sprite *button;
        sprite *background;
        t_list *list_buttons;
    } drop_down_menu_s;

    typedef struct button_t {
        sprite *host;
        void *parent;
        sprite *img;
        void *datas;
        void (*click)(sprite *sprite_datas);
    } button_s;

    typedef struct modal_t {
        t_list *list_text;
        t_list *list_button;
        t_list *list_input;
        t_list *list_sprite;
    } modal_s;

    typedef struct list_line_t {
        struct list_t *host;
        void *datas;
        void (*set_visibility)(struct list_line_t *, bool visibility);
        void (*on_click)(struct list_line_t *);
        void (*destroy)(struct list_line_t *);
        void (*mouve)(struct list_line_t *, sfVector2f pos);
    } list_line_s;

    typedef struct list_t {
        sprite *host;
        uint32_t index;
        uint32_t max_showed_ligne;
        t_list *list_ligne;
        t_list *list_button;
    } list_s;

    typedef struct check_box_t {
        sprite *host;
        void *parent;
        sprite *img;
        bool check;
        void *datas;
        void (*on_change)(sprite *sprite_datas);
    } check_box_s;


#endif //canva_structs
