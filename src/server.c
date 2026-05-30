#include <signal.h>
#include "../ft_printf/ft_printf.h"

void handler(int sig)
{
    ft_printf("Signal is HEREEEEEEEEEEEE :(\n");
}

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sigaction(11, &sa, NULL);

    ft_printf("PID: %d\n", getpid());
    while (1)
    {

    }
}