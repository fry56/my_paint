/*
** EPITECH PROJECT, 2023
** path_open_file.c
** File description:
** desc
*/

#include <t_path.h>
#include <t_ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <t_mem.h>
#include <t_string.h>

static void init_buf(tfile_s *new_file)
{
    if ((new_file->buf = tcalloc(1, new_file->size + 1)) == NULL)
        return;
    read(new_file->fd, new_file->buf, new_file->size);
    new_file->lignes = 1;
    for (int i = 0; new_file->buf[i] != '\0'; ++i) {
        if (new_file->buf[i] != '\n')
            new_file->lignes++;
    }
}

tfile_s *tpath_open_file(char *path, int flags, bool buff)
{
    int fd = open(path, flags);
    struct stat sb;
    tfile_s *new_file;

    if (fd == -1)
        return NULL;
    if ((new_file = tcalloc(1, sizeof(tfile_s))) == NULL) {
        close(fd);
        return NULL;
    }
    stat(path, &sb);
    new_file->size = sb.st_size;
    new_file->path = tstr_cpy(NULL, path);
    new_file->fd = fd;
    if (buff)
        init_buf(new_file);
    return new_file;
}
