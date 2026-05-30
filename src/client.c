#include <signal.h>
#include <stdlib.h>
#include "../ft_printf/ft_printf.h"


void send_string(int pid, char *str)
{

}
int main(int ac, char **av)
{
    int     pid;

    pid = ft_atoi(av[1]);
    if (pid <= 0 || !av[2])
        return 0;
    send_string(pid, av[2]);


    
}
