/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** put_nbr
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void put_nbr(int nb)
{
    int num;

    if (nb > -2147483648 && nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb <= 2147483647 && nb > 9) {
        num = nb % 10;
        put_nbr(nb / 10);
        my_putchar(num + 48);
    }
}
