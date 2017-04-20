/* search.c */

#include "search.h"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <dirent.h>

/**
 * Recursively search through the provided root directory
 * @param   root        Path to directory
 * @param   settings    Settings structure
 * @return  Whether or not the search was successful.
 */
int	    search(const char *root, const Settings *settings) {
	struct dirent * dentry;

	DIR * parent_dir = opendir(root);

	if (parent_dir == NULL) { //check if directory is openable
		return EXIT_FAILURE;
	}
	
	while ((dentry = readdir(parent_dir)) != NULL) { //read
		is_directory_empty()
		if (filter(root, settings) == false) { //file passes all the tests
			execute(root, settings);
		}
		search(, settings); //sprintf
	}

	closedir(parent_dir); //close

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
