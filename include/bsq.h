/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** It's the .h of my file bsq.c
*/

#ifndef BSQ_H_
    #define BSQ_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "my.h"
    #include <stdlib.h>
    #include <unistd.h>

typedef struct square {
    int size_big;
    int pos_big;
    int cmpt_y;
    int cmpt_x;
} square;

int take_size_x(char *buffer, int start);
int take_size_y(char *buffer);
int file_errors(int file_descriptor, int size);
int set_stop(char my_char, int stop);

#endif /* BSQ_H_ */
