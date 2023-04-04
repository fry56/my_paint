/*
** EPITECH PROJECT, 2022
** t_class_window.h
** File description:
** desc
*/
#ifndef t_class_window
    #define t_class_window

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <t_list.h>
    #include <t_hashmap.h>
    #include <Utils/t_key.h>

    typedef struct window {
        sfVideoMode mode;
        sfRenderWindow *window;
        sfEvent event;
        bool mode_update;
        t_hashmap *map_global_datas;
        t_hashmap *map_scenes;
        t_hashmap_node *actual_scene;
        sfClock *global_clock;
        long long last_tick;
        float deltatime;
    } window;

    bool window_change_scene(window *self, char *scene_name);
    window *new_window(char *name, sfVideoMode mode);
    void window_clock_update(window *window_datas);
    void window_event_update(window *window_datas);
    void window_destroy(window *self);
    int start_window(window *self);
#endif //t_class_window
