#include "../Headers/minitalk.h"


void    putnbr(int nb)
{
    char    c;

    if (nb > 9)
        putnbr(nb / 10);
    c = nb % 10 + 48;
    write(1, &c,1);
}

int      costum_atoi(char *s)
{
    int     i;
    long    nb;

    if (!s || !*s)
        return 0;
    nb = 0;
    i = - 1;
    while(s[++i])
    {
        if (s[i] < '0' || s[i] > '9')
            return 0;
        nb = nb * 10 + s[i] - 48;
        if (nb > INT_MAX)
            return 0;
    }
    return ((int )nb);
}
