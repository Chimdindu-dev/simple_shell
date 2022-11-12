#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int printpid(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%u", my_pid);
    return (0);

}

/**include in header file practice with this so far to check commands work
 *can commands be called within a folder like bin
 *do bin reasearch
 *all commands will have their executable versions so ./filename
 */