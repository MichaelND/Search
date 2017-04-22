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
		printf("%s\n", path);

	if (settings->exec_argc != 0) {
		pid_t pid = fork();
		if (pid < 0) {
			return EXIT_FAILURE;
		}
		if (pid == 0) {
			char * v[settings->exec_argc + 1]; //last element equal to null if path matches path in cur
			for (int i = 0; i <= settings->exec_argc; i++) {
				if (strcmp(settings->exec_argv[i], "{}") == 0)
					v[i] = path;
				else
					v[i] = settings->exec_argv[i];
			}

			v[settings->exec_argc] = NULL;
			
			if (execvp(v[0], v) < 0) {
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
