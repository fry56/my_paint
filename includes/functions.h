/*
** EPITECH PROJECT, 2023
** paint_functions.h
** File description:
** desc
*/
#ifndef paint_functions
    #define paint_functions

    #include <Class/t_window.h>
    #include <Class/t_scene.h>
    #include <Class/t_sprite.h>
    #include <struct.h>

    void init_menu(scene *scene_datas);
    void init_file_drop_down(scene *scene_datas);
    void init_edit_drop_down(scene *scene_datas);
    void init_help_drop_down(scene *scene_datas);
    void init_new_file_modal(scene *scene_datas);
    void init_save_file_modal(scene *scene_datas);
    void init_help_modal(scene *scene_datas);
    void init_about_modal(scene *scene_datas);
    void init_zoom(scene *scene_datas);

    frame_buffer_s *create_frame_buffer(uint32_t width, uint32_t height);
    void set_frame_buffer_pixel_color(frame_buffer_s *frame,
        sfVector2f pos, sfColor color);
    void set_layer_default_color(frame_buffer_s *frame, sfColor color);
    void set_layer_pos(scene *scene_datas, paint_s *paint_datas,
        sfVector2f pos);
    void mouve_layer_pos(scene *scene_datas, paint_s *paint_datas,
        sfVector2f pos);

    frame_buffer_s *create_layer(scene *scene_datas);
    frame_buffer_s *frame_buffer_compos(frame_buffer_s *dest,
        frame_buffer_s *src);
    void mouve_layer(scene *scene_datas, sfClock *clock_datas UNUSED);
    void mouse_layer_actions(scene *scene_datas, sfClock *clock_datas);
    void update_layer(scene *scene_datas, window *window_datas);
    void resize_window_event(scene *scene_datas, window *window_datas);

    void new_file_exec(sprite *sprite_datas);
    void create_new_file(sprite *sprite_datas);

    void save_file_exec(sprite *sprite_datas);
    void save_file(sprite *sprite_datas);

    void zoom_more_exec(sprite *sprite_datas);
    void zoom_less_exec(sprite *sprite_datas);

    void toggle_tools_elem(tools_s *tools);
    void init_tools(scene *scene_datas, paint_s *paint_datas);
    void init_pen(int index, scene *scene_datas, paint_s *paint_datas);
    void init_eraser(int index, scene *scene_datas, paint_s *paint_datas);
    void select_pen_tool(sprite *button);
    void select_eraser_tool(sprite *button);

    void init_layer_list(scene *scene_datas);
    void select_layer(sprite *button);
    bool delete_layer(sprite *button);
    void toggle_layer_visibility(sprite *button);
    void add_layer_ligne_to_list(scene *scene_datas, sprite *list_sprite,
        sprite *buffer);
    void add_layer(sprite *button);
    void delete_layer_click(sprite *button);
    void destroy_layer_ligne(struct list_line_t *layer);

    void pen_click(paint_s *paint_datas, sfVector2f pos);
    void set_pen_thickness(sprite *sprite_datas);
    void pen_change_color(sprite *button);

    void eraser_click(paint_s *paint_datas, sfVector2f pos);
    void set_eraser_thickness(sprite *sprite_datas);

    void new_file_modal_change_width(sprite *sprite_datas);
    void new_file_modal_change_height(sprite *sprite_datas);

    void about_exec(sprite *sprite_datas);
    void help_exec(sprite *sprite_datas);

    bool assets_checker(void);

#endif //paint_functions
