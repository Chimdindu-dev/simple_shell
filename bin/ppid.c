#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int printppid(void)
{
    pid_t my_pid;

    my_pid = getppid();
    printf("%u", my_pid);
    return (0);

}