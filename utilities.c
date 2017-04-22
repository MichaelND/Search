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
    DIR *dir = opendir(path);
    int numFiles = 0;
    bool empty = true; 
    if (dir == NULL ) {
        fprintf(stderr, "Unable to open: %s\n", strerror(errno));
        return empty;
    }
    while ((readdir(dir)) != NULL) {
        numFiles = numFiles + 1;
        if (numFiles > 2) { // . and ..
            empty = false;
            break;
        }
        else
            empty = true;
    }
    closedir(dir);
    return empty;
}

/**
 * Retrieve the modification time of the given file.
 * @param   path        Path to file of directory.
 * @return  The modification time of the given file.
 */
time_t      get_mtime(const char *path) {
    struct stat sb;
    time_t failure = 0; 
    if (lstat(path, &sb) < 0) {
        perror(path);
        return failure;
    }
    return sb.st_mtime; 
}
/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
