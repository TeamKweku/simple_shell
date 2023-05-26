#include "shell.h"
/**
  * print_error_msgs - function prints error messages to stdout
  * @shell: name of the shell program
  * @exit_status: status code of program
  * @prog: rate of run of command
  */
void print_error_msgs(char *shell, int exit_status, char *prog)
{
	char rev_exit_status[BUFFSIZE];
	char status_buffer[BUFFSIZE];
	int i = 0, len;

	while (exit_status != 0)
	{
		rev_exit_status[i++] = (exit_status % 10) + '0';
		exit_status /= 10;
	}
	rev_exit_status[i] = '\0';


	len = _strlen(rev_exit_status) - 1;
	for (i = 0; rev_exit_status[i]; i++)
		status_buffer[i] = rev_exit_status[len--];
	status_buffer[i] = '\0';

	write(STDOUT_FILENO, shell, _strlen(shell));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, status_buffer, _strlen(status_buffer));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, prog, _strlen(prog));
	write(STDOUT_FILENO, ": not found\n", 12);
}
