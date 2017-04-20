/* expression.c */

#include "search.h"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <dirent.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * Executes the -print or -exec expressions (or both) on the specified path.
 * @param   path        Path to a file or directory
 * @param   settings    Settings structure.
 * @return  Whether or not the execution was successful.
 */
int	    execute(const char *path, const Settings *settings) {
	if (settings->print == true)
		printf(path);

	if (settings->exec_argc != 0) {
		pid_t pid = fork();
		if (pid < 0) {
			return EXIT_FAILURE;
		}
		else if (pid == 0) {
			char *v[] = {} //last element equal to null if path matches path in cur
			if (execvp(settings->exec_argv[0], settings->exec_argv) < 0) {
				_exit(EXIT_FAILURE);
			}
		}
		else { //parent
			int status;
			while ((pid = wait(&status)) < 0);
		}
	}
    return 0;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
