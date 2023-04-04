/*
** EPITECH PROJECT, 2023
** canva_functions.h
** File description:
** desc
*/
#ifndef canva_functions
    #define canva_functions

    #include <Class/t_window.h>
    #include <Class/t_scene.h>
    #include <canva/canva_structs.h>
    #include <functions.h>

    void button_click(sprite *sprite_datas, window *window_datas);
    void button_over(sprite *sprite_datas, window *window_datas);
    void init_button_animation(window *window_datas);
    sprite *create_button(scene *scene_datas, sfVector2f pos,
        char *img_path, void (*click)(sprite *sprite_datas));
    void button_set_visibility(sprite *sprite_datas, bool visibility);
    void button_set_position(sprite *button, sfVector2f pos);
    void button_set_scale(sprite *button, sfVector2f scale);
    void button_mouve(sprite *button, sfVector2f pos);
    void destroy_button(sprite *button_sprite);

    void drop_down_menu_toggle(sprite *sprite_datas);
    sprite *create_drop_down_menu(scene *scene_datas, sfVector2f pos,
        char *img_path);
    void add_button_to_drop_down(drop_down_menu_s *menu, button_s *button);

    sprite *create_input(scene *scene_datas, input_type_e type,
        sfVector2f pos, sfVector2f scale);
    void input_over(sprite *sprite_datas, window *window_datas);
    void input_click(sprite *sprite_datas, window *window_datas);
    void input_key_press(sprite *sprite_datas, window *window_datas);
    void input_indicator(sprite *sprite_datas, sfClock *clock_datas);
    void remove_char(sprite *sprite_datas, input_s *input_datas);
    void input_insert(sprite *sprite_datas,
        input_s *input_datas, sfKeyCode key);
    void input_set_visibility(sprite *sprite_datas, bool visibility);
    void input_set_default_value(sprite *input_sprite, char *value);

    sprite *create_modal(scene *scene_datas, char *title,
        char *name, sfVector2f scale);
    void modal_toggle(sprite *sprite_datas);
    void modal_close_exc(sprite *sprite_datas);

    sprite *create_list(scene *scene_datas, sfVector2f pos,
        sfVector2f scale, uint32_t max_showed_ligne);
    void list_add_ligne(sprite *list_sprite, list_line_s *new_line);
    void list_set_visibility(sprite *list_sprite, bool visibility);
    void list_up_exec(sprite *list_sprite);
    void list_down_exec(sprite *list_sprite);

    sprite *create_check_box(scene *scene_datas, sfVector2f pos,
        bool default_value, void (*on_change)(sprite *sprite_datas));
    void check_box_click(sprite *sprite_datas, window *window_datas);
    void check_box_set_visibility(sprite *sprite_datas, bool visibility);
    void check_box_set_position(sprite *check_box, sfVector2f pos);
    void check_box_set_scale(sprite *check_box, sfVector2f scale);
    void check_box_mouve(sprite *check_box, sfVector2f pos);
    void destroy_check_box(sprite *check_box_sprite);

#endif //canva_functions
