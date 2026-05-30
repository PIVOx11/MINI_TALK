#include <signal.h>
#include <stdlib.h>


int main(int ac, char **av)
{
    int pid = atoi(av[1]);
    kill(pid, 11);
    
}