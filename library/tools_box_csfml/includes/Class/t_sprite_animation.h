/*
** EPITECH PROJECT, 2022
** t_class_sprite_animation.h
** File description:
** desc
*/
#ifndef t_class_sprite_animation
    #define t_class_sprite_animation

    #include <t_list.h>
    #include <SFML/Graphics.h>

    typedef struct animation {
        char *name;
        sfTexture *sf_texture;
        bool loop;
        t_list *list_frame_rect;
        float frame_rate;
    } animation;

    bool animation_auto_gen_frame(animation *self, int nbr_sprites
        , int nbr_sprite_per_line, sfIntRect rect_start);
    bool animation_add_frame(animation *self, sfIntRect rect);
    bool animation_remove_frame(animation *self, size_t index);
    void animation_set_loop(animation *self, bool loop);
    bool animation_set_frame_rate(animation *self, float frame_rate);
    animation *new_animation(char *name, char *path,
        bool loop, float frame_rate);
#endif //t_class_sprite_animation
