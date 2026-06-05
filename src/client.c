#include "../Headers/minitalk.h"


void send_bits(int pid, char c)
{
    int     i;

    i = 8;
    while (--i >= 0)
    {
        if ((c >> i) & 1)
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

    pid = costum_atoi(av[1]);
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
        if (av[i + 1])
            send_bits(pid, ' ');
    }
}
