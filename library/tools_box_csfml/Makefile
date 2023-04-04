##
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

SRC = \
	src/sprite/new_sprite.c \
	src/sprite/set_pos.c \
	src/sprite/set_texture.c \
	src/sprite/destroy.c \
	src/sprite/update.c \
	src/sprite/add_flag.c \
	src/sprite/remove_flag.c \
	src/sprite/have_flag.c \
	src/sprite/set_origin_center.c \
	src/sprite/set_fixed_origin.c \
	src/sprite/get_by_flag.c \
	\
	src/sprite/animator/new_animator.c \
	src/sprite/animator/play_animation.c \
	src/sprite/animator/set_default.c \
	src/sprite/animator/remove_animation.c \
	src/sprite/animator/add_animation.c \
	src/sprite/animator/have_animation.c \
	src/sprite/animator/update_frame.c \
	src/sprite/animator/callback.c \
	src/sprite/animator/add_callback.c \
	src/sprite/animator/remove_callback.c \
	src/sprite/animator/update.c \
	\
	src/sprite/animation/new_animation.c \
	src/sprite/animation/set_loop.c \
	src/sprite/animation/set_frame_rate.c \
	src/sprite/animation/remove_frame.c \
	src/sprite/animation/auto_gen_frame.c \
	src/sprite/animation/add_frame.c \
	src/sprite/animation/destroy.c \
	\
	src/sprite/events/add_clock_update_function.c \
	src/sprite/events/remove_clock_update_function.c \
	src/sprite/events/add_event_update_function.c \
	src/sprite/events/remove_event_update_function.c \
	src/sprite/events/update.c \
	\
	src/sprite/events/handling/is_mouse_over.c \
	src/sprite/events/handling/is_mouse_click.c \
	\
	src/window/new_window.c \
	src/window/change_scene.c \
	src/window/update.c \
	src/window/new_scene.c \
	src/window/destroy.c \
	src/window/start_window.c \
	\
	src/scene/add_clock_update_function.c \
	src/scene/add_event_update_function.c \
	\
	src/scene/remove_clock_update_function.c \
	src/scene/remove_event_update_function.c \
	\
	src/scene/key/add_key_bind.c \
	src/scene/key/get_key_press_timestamp.c \
	src/scene/key/is_key_bind.c \
	src/scene/key/is_key_press.c \
	src/scene/key/remove_key_bind.c \
	src/scene/key/get_key.c \
	src/scene/key/update_key.c \
	\
	src/text/destroy.c \
	src/text/new_text.c \
	src/text/set_pos.c \
	src/text/set_font_color.c \
	src/text/set_font_size.c \
	src/text/set_origin_center.c \
	src/text/set_content.c \
	src/text/add_flag.c \
	src/text/remove_flag.c \
	src/text/have_flag.c

OBJ = $(SRC:.c=.o)

GCC = gcc

INCLUDE_FLAGS = \
	-lcsfml-graphics -lcsfml-window -lcsfml-system\
	-I includes/ \
	-I ../tools_box/includes/

C_WARNING_FLAGS = -Wextra -Wall
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

all: tools_box_csfml.a
.PHONY : all

tools_box_csfml.a: $(OBJ)
	@ar rc $@ $(OBJ)
.PHONY : tools_box_csfml.a

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete
.PHONY : clean
