/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** It's the file that countains main functions on my program
*/

#include "../include/bsq.h"

int file_errors(int file_descriptor, int size)
{
    if (file_descriptor == -1) {
        write(2, "Program failed to open file\n", 28);
        return (84);
    } else if (size == -1) {
        write(2, "Program failed to read file\n", 28);
        return (84);
    }
    return (0);
}
