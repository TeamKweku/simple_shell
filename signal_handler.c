#include "shell.h"

/**
 * signal_handler - function handles the SIGINT from the terminal
 * @signum: the value of interruption
 *
 * Return: nothing
 */

void signal_handler(int signum)
{
	(void)signum;
	write(1, "\n$ ", 3);
}
