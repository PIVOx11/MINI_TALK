#include "../Headers/minitalk.h"

unsigned char    byte;


void handler(int sig)
{
    static int     bit;

    if (sig == SIGINT)
    {    
        write(1, "\nSERVER EXIT !\n", 15);
        exit(1);
    }
        if (sig == SIGUSR1)
    {
        byte |= (1 << 7 - bit);
    }
    bit++;
    if (bit == 8)
    {
        write(1, &byte, 1);
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
    sigaction(SIGINT, &sa, NULL);

    putnbr(getpid());
    write(1, "\n", 1);
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