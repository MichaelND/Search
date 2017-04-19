/*utilities.c */

#include "search.h"

#include <errno.h>
#include <string.h>
#include <time.h>

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * Test whether or not a directory is empty.
 * @param   path        Path to directory.
 * @return  Whether or not a directory is empty.
 */
bool        is_directory_empty(const char *path) {
    struct dirent *file; 
    DIR *dir = opendir(path);
    int numFiles = 0;
    bool found = false; 
    if (dir == NULL ) return found;
    while (( file = readdir(dir)) != NULL) {
        numFiles = numFiles + 1;
        if (numFiles > 2) {
            found = true;
            break;
        }
    }
    closedir(dir);
    return found;
}

/**
 * Retrieve the modification time of the given file.
 * @param   path        Path to file of directory.
 * @return  The modification time of the given file.
 */
time_t      get_mtime(const char *path) {
    return 0;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
