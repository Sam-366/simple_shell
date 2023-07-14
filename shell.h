#ifndef SHELL_H
#define SHELL_H

extern char **environ;
/* global constants */
#define BUFFER_SIZE 1024

/* libs includes */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>

#endif /* SHELL_H */
