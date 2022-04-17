/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** It's the file that countains main functions on my program
*/

#include "../include/bsq.h"

square *count_size(char *buffer, int cmpt_size, int start, square *info_square)
{
    int stop = 1;

    for (int cmpt_l = 0; cmpt_l <= cmpt_size && stop == 1 && cmpt_l <
    (info_square->cmpt_y - cmpt_size); cmpt_l += 1) {
        for (int cmpt_c = 0; cmpt_c <= cmpt_size && stop == 1 && cmpt_c <
        (info_square->cmpt_x - cmpt_size); cmpt_c += 1)
            stop = set_stop(buffer[start + cmpt_c + cmpt_l *
            (info_square->cmpt_x + 1)], stop);
    }
    if (stop == 1 && cmpt_size < info_square->cmpt_x && cmpt_size <
    info_square->cmpt_y) {
        cmpt_size += 1;
        info_square = count_size(buffer, cmpt_size, start, info_square);
    } else if (cmpt_size > info_square->size_big) {
        info_square->size_big = cmpt_size;
        info_square->pos_big = start;
    }
    return (info_square);
}

void replace_square(char *buffer, square *info_square, int temp)
{
    for (int cmpt_l = 0; cmpt_l < info_square->size_big; cmpt_l += 1) {
        for (int cmpt_c = 0; cmpt_c < info_square->size_big; cmpt_c += 1) {
            buffer[info_square->pos_big + cmpt_c + cmpt_l *
            (info_square->cmpt_x + 1)] = 'x';
        }
    }
    while (temp >= 0) {
        buffer += 1;
        temp -= 1;
    }
    my_putstr(buffer);
}

square *walk_in_map(char *buffer, square *info_square)
{
    int start = take_size_x(buffer, 0);

    info_square->size_big = 0;
    info_square->pos_big = 0;
    info_square->cmpt_x = take_size_x(buffer, start + 1);
    info_square->cmpt_y = take_size_y(buffer);
    while (start <= (info_square->cmpt_x + 1) * (info_square->cmpt_y -
    info_square->size_big + 1)) {
        info_square = count_size(buffer, 0, start + 1, info_square);
        start += 1;
    }
    return (info_square);
}

int read_file(char const *filepath, struct stat st)
{
    int file_descriptor;
    int size;
    char buffer[st.st_size];
    square *info_square = malloc(sizeof(square));
    int temp;

    file_descriptor = open(filepath, O_RDONLY);
    size = read(file_descriptor, buffer, st.st_size);
    if (file_errors(file_descriptor, size) == 84)
        return (84);
    buffer[st.st_size] = '\0';
    temp = take_size_x(buffer, 0);
    info_square = walk_in_map(buffer, info_square);
    replace_square(buffer, info_square, temp);
    close(file_descriptor);
    free(info_square);
    return (0);
}

int main(int argc, char **argv)
{
    struct stat st;

    if (argc != 2) {
        write(2, "invalid number of params\n", 25);
        return (84);
    }
    stat(argv[1], &st);
    if (read_file(argv[1], st) == 84)
        return (84);
    else
        return (0);
}
