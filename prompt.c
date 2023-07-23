#include "shell.h"

#define PROMPT "$ "
#define MAX_INPUT_LENGTH 100

int main() 
{
       	char input[MAX_INPUT_LENGTH];
       
	while (1) 
	{
		printf(PROMPT);
		
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) 
		{
			break;
		}
		size_t len = strlen(input);
		if (len > 0 && input[len - 1] == '\n') 
		{
			input[len - 1] = '\0';
		}
		printf("Command entered: %s\n", input);
	}
	return 0;
}
