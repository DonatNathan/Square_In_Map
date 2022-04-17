/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** It's the file that countain size of map functions
*/

int take_size_x(char *buffer, int start)
{
    int cmpt_x = 0;

    while (buffer[start] != '\n') {
        cmpt_x += 1;
        start += 1;
    }
    return (cmpt_x);
}

int take_size_y(char *buffer)
{
    int cmpt = 0;
    int cmpt_y = 0;

    while (buffer[cmpt] != '\0') {
        if (buffer[cmpt] == '\n')
            cmpt_y += 1;
        cmpt += 1;
    }
    return (cmpt_y - 1);
}

int set_stop(char my_char, int stop)
{
    if (my_char != '.')
        stop = 0;
    return (stop);
}
