/* search.c */

#include "search.h"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <sys/stat.h>

#include <dirent.h>

/**
 * Recursively search through the provided root directory
 * @param   root        Path to directory
 * @param   settings    Settings structure
 * @return  Whether or not the search was successful.
 */
int	    search(const char *root, const Settings *settings) {	
    struct dirent * dentry;
    // struct stat inode;
    DIR * parent_dir = opendir(root);
    char path[BUFSIZ];
    if (parent_dir == NULL) { //check if directory is openable
    	return EXIT_FAILURE;
    }
    while ((dentry = readdir(parent_dir)) != NULL) { //read
        sprintf(path, "%s/%s", root, dentry->d_name);
        
        if (strcmp(dentry->d_name, ".") != 0 && strcmp(dentry->d_name, "..") != 0) {
            if (filter(path,settings) == false)
                execute(path,settings);
            if (dentry->d_type == DT_DIR) 
                search(path,settings);
        }
    }
    closedir(parent_dir); //close
    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
