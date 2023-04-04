##
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

SRC = 	\
	src/main.c \
	\
	src/menu/init_menu.c \
	\
	src/menu/init/init_help_drop_down.c \
	src/menu/init/init_file_drop_down.c \
	src/menu/init/init_edit_drop_down.c \
	\
	src/canva/button/create_button.c \
	src/canva/button/button_events.c \
	src/canva/button/init_button_animations.c \
	src/canva/button/button_set_visibility.c \
	src/canva/button/button_set_position.c \
	src/canva/button/button_set_sacle.c \
	src/canva/button/button_mouve.c \
	src/canva/button/destroy_button.c \
	\
	src/canva/drop_down_menu/create_drop_down_menu.c \
	src/canva/drop_down_menu/drop_down_menu_toggle.c \
	src/canva/drop_down_menu/add_button_to_drop_down.c \
	\
	src/canva/input/input_set_visibility.c \
	src/canva/input/create_input.c \
	src/canva/input/input_events.c \
	src/canva/input/input_insert.c \
	src/canva/input/input_set_default_value.c \
	src/canva/check_box/destroy_check_box.c \
	\
	src/canva/check_box/check_box_events.c \
	src/canva/check_box/check_box_set_vidibility.c \
	src/canva/check_box/create_check_box.c \
	src/canva/check_box/check_box_set_position.c \
	src/canva/check_box/check_box_set_scale.c \
	src/canva/check_box/check_box_mouve.c \
	\
	src/canva/list/create_list.c \
	src/canva/list/list_set_visibility.c \
	src/canva/list/list_events.c \
	src/canva/list/list_add_ligne.c \
	\
	src/canva/modal/create_modal.c \
	src/canva/modal/modal_toggle.c \
	src/canva/modal/modal_events.c \
	\
	src/menu/events/new_file_modal_events.c \
	\
	src/menu/functions/new_file.c \
	src/menu/functions/save_file.c \
	src/menu/functions/zoom.c \
	src/menu/functions/layer_list_call.c \
	src/menu/functions/layer_list_functions.c \
	src/menu/functions/help.c \
	src/menu/functions/about.c \
	\
	src/layers/mouve_layer.c \
	src/layers/create_layer.c \
	src/layers/mouse_layer_actions.c \
	src/layers/update_layer.c \
	src/layers/set_layer_default_color.c \
	\
	src/utils/frame_buffer.c \
	src/utils/assets_checker.c \
	\
	src/tools/init_tools.c \
	src/tools/inits/init_eraser.c \
	src/tools/inits/init_pen.c \
	src/tools/functions/pen/pen_click.c \
	src/tools/functions/pen/pen_thickness.c \
	src/tools/functions/pen/pen_change_color.c \
	src/tools/functions/eraser/eraser_click.c \
	src/tools/functions/eraser/eraser_thickness.c \
	\
	src/tools/functions/toggle_tools_elem.c \
	src/tools/functions/select_tools.c \
	\
	src/menu/init/init_zoom.c \
	src/menu/init/init_new_file_modal.c \
	src/menu/init/init_save_file_modal.c \
	src/menu/init/init_layer_list.c \
	src/menu/init/init_about_modal.c \
	src/menu/init/init_help_modal.c \

OBJ = $(SRC:.c=.o)

INCLUDE_FLAGS = \
	-I includes\
	-I library/tools_box/includes\
	-I library/tools_box_csfml/includes

C_WARNING_FLAGS = -Wextra -Wall
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

# Library
LIB_FLAGS = \
	-lm \
	-L library/tools_box_csfml -l:tools_box_csfml.a \
	-L library/tools_box -l:tools_box.a \
	-lcsfml-graphics -lcsfml-window -lcsfml-system \

NAME = my_paint

GCC = gcc

all: $(NAME)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

$(NAME): tools_box tools_box_csfml $(OBJ)
	@$(GCC) -o $@ $(OBJ) $(INCLUDE_FLAGS) $(LIB_FLAGS)
.PHONY: $(NAME)

clean:
	@rm -f $(OBJ)
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

### Library ###
tools_box:
	make -C library/tools_box

tools_box_csfml:
	make -C library/tools_box_csfml
