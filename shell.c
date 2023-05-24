#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * show_shell_prompt - Display the shell prompt
 *
*/
void show_shell_prompt(void)
{
printf("$ "); /* Display the shell prompt */
}

/**
* read_user_command - Reads the user command from stdin
* Return: The user command as a string
*/
char *read_user_command(void)
{
char *command = NULL;
size_t buffer_size = 0;
ssize_t getline_input;

show_shell_prompt();
getline_input = getline(&command, &buffer_size, stdin);

if (getline_input == -1)
{
if (feof(stdin))
{
printf("\n"); /*end of file (Ctrl+D) is reached */
exit(EXIT_SUCCESS);
}
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}

return (command);
}

/**
* parse_arguments - Parses the command line and arguments
* @command: The user command to parse
* @argv: The array to store the command and arguments
* Return: The number of arguments
*/
int parse_arguments(char *command, char *argv[])
{
int argc = 0;
char *token;

token = strtok(command, " \t\n");

while (token != NULL)
{
argv[argc++] = token;
token = strtok(NULL, " \t\n");
}

argv[argc] = NULL;

return (argc);
}

/**
* execute_user_command - Executes the user command using execve
* @argv: The array containing the command and arguments
* Return: 0 on success, -1 on failure
*/
int execute_user_command(char *argv[])
{
if (execvp(argv[0], argv) == -1)
{
perror("execvp");
return (-1);
}

return (0);
}

/**
* main - Entry point of the shell program
* Return: Always 0
*/
int main(void)
{
char *command;
char *argv[BUFFER_SIZE];

while (1)
{
command = read_user_command();
parse_arguments(command, argv);
execute_user_command(argv);
free(command);
}

return (0);
}

