#include <signal.h>
#include "../ft_printf/ft_printf.h"

unsigned char    byte;


void handler(int sig)
{
    static int     bit;

    if (sig == SIGUSR1)
    {
        byte |= (1 << 7 - bit);
    }
    bit++;
    if (bit == 8)
    {
        ft_char(byte);
        bit = 0;
        byte = 0;
    }
}

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = handler;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    ft_printf("PID: %d\n", getpid());
    while (1)
    {
        pause();
    }
}
































// void send_bits(int pid, char c)
// {
//     int     i;
//     char    t;

//     i = 8;
//     t = 0;
//     while (--i >= 0)
//     {
//         t = c >> i;
//         if (t & 1)
//             ft_printf("1 ");
//         else
//             ft_printf("0 ");
//     }
//     ft_printf("\n");
// }