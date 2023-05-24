#ifndef SHELL_H
#define SHELL_H

/**
 * show_shell_prompt - Display the shell prompt
 */
void show_shell_prompt(void);

/**
 * read_user_command - Read the user command from stdin
 *
 * Return: The user command as a string
 */
char *read_user_command(void);

/**
 * parse_arguments - Parses the command line and arguments
 * @command: The user command to parse
 * @argv: The array to store the command and arguments
 * Return: The number of arguments
 */
int parse_arguments(char *command, char *argv[]);

/**
 * execute_user_command - Executes the using the execvp system call.
 * Returns 0 on success, -1 on failure.
 */
int execute_user_command(char *argv[]);
#endif /* SHELL_H */

