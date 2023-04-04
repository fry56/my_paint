/*
** EPITECH PROJECT, 2023
** assets_checker.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <t_path.h>
#include <t_string.h>

static const char *assets_list[] = {
        "assets/ajouter.png",
        "assets/art.png",
        "assets/background_drop_down.png",
        "assets/bg_modal.png",
        "assets/button.png",
        "assets/check.png",
        "assets/check_box.png",
        "assets/circle_cursor.png",
        "assets/close.png",
        "assets/delete.png",
        "assets/down-arrow.png",
        "assets/eraser.png",
        "assets/files.png",
        "assets/font.ttf",
        "assets/input.png",
        "assets/new-file.png",
        "assets/open-folder.png",
        "assets/paint-palette.png",
        "assets/pen.png",
        "assets/question.png",
        "assets/save.png",
        "assets/side_banner.png",
        "assets/square_cursor.png",
        "assets/top_banner.png",
        "assets/up-arrow.png",
        "assets/zoom_less.png",
        "assets/zoom_more.png",
        "assets/yellow_pen.png",
        "assets/red_pen.png",
        "assets/pink_pen.png",
        "assets/orange_pen.png",
        "assets/green_pen.png",
        "assets/info.png",
        "assets/help.png",
        NULL
};

bool assets_checker(void)
{
    char *temp;

    for (int i = 0; assets_list[i] != NULL ; ++i) {
        if (!tpath_is_valide((char *)assets_list[i])) {
            temp = tstr_compos("Assets %s not found !\n", assets_list[i]);
            write(2, temp, tstr_len(temp));
            return false;
        }
    }
    return true;
}
