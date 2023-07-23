#include "shell.h"

#define MAX_INPUT_LENGTH 1024
#define PROMPT "$ "

void execute_command(char **args) 
{
       	pid_t pid = fork();

	if (pid < 0) 
	{
		perror("Fork failed");
	} 
	else if (pid == 0) 
	{
		if (execvp(args[0], args) == -1) 
		{
			perror("Execution failed");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	} 
	else 
	{
        int status;
        waitpid(pid, &status, 0);
	}
}
int main(int argc, char *argv[]) 
{
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_INPUT_LENGTH / 2 + 1];
	
	while (1) 
	{
		printf("myshell> ");
		fflush(stdout);

        
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) 
	{
            
            break;
        }

        /* Tokenize the input */

        char *token = strtok(input, " \t\n");
        int arg_index = 0;
        while (token != NULL) 
	{
		args[arg_index++] = token;
		token = strtok(NULL, " \t\n");
	}
        args[arg_index] = NULL; 
	
	if (arg_index > 0) 
	{
		if (strcmp(args[0], "exit") == 0) 
		{
                break;
		} 
		else if (strcmp(args[0], "cd") == 0) 
		{
			if (arg_index > 1) 
			{
				if (chdir(args[1]) != 0) 
				{
					perror("cd failed");
				}
			} 
			else 
			{
                }
                continue;
            }
        }
        execute_command(args);
    }

    return 0;
}

