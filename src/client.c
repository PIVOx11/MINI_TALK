#include <signal.h>
#include <stdlib.h>
#include "../ft_printf/ft_printf.h"


void send_bits(int pid, char c)
{
    int     i;
    char    t;

    i = 8;
    t = 0;
    while (--i >= 0)
    {
        t = c >> i;
        if (t & 1)
        {
            kill(pid, SIGUSR1);
        }else{
            kill(pid, SIGUSR2);
        }
            usleep(555);
    }

}
int main(int ac, char **av)
{
    int     pid;
    int     i;
    int     j;
    pid = ft_atoi(av[1]);
    if (pid <= 0)
        return 0;
    
    i = 1;
    while (av[++i])
    {    j = 0;
        while (av[i][j])
        {
            send_bits(pid, av[i][j]);
            j++;
        }
        send_bits(pid, ' ');
    }
}
