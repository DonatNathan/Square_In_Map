/*
** EPITECH PROJECT, 2022
** LIB
** File description:
** It's the file that contain prototypes of my lib functions
*/

#ifndef LIB_H_
    #define LIB_H_

    #include <stdio.h>

int my_atoi(char *str);
void my_putchar(char c);
int my_getnbr(char const *str);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char *src, int n);
int my_printf(char *s, ...);
char *my_itoa(int nb);
int puissance(int y);
char **str_to_array(char *map, char stop);
void my_fputstr(char const *str, char *file_name);
char **my_split_tab(char *argv, char char_);

#endif /* LIB_H_ */
