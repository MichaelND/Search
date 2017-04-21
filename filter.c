/* filter.c */

#include "search.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>

#include <dirent.h>
#include <fnmatch.h>
#include <sys/stat.h>
#include <unistd.h>


#include <libgen.h>
/**
 * Test whether or not the given path should be filtered out of the output.
 * @param   path        Path to file or directory.
 * @param   settings    Settings structure.
 * @return  Whether or not the path should be excluded from the output (true to
 * exclude, false to include).
 */
bool        filter(const char *path, const Settings *settings) {
    bool reject = false;
    struct stat inode;
    if (lstat(path, &inode) != 0) reject = true;
    else if (settings->access != 0 && access(path, settings->access) != 0) reject = true;
    else if (settings->type != 0 && inode.st_mode != settings->type) reject = true;
    else if (settings->empty != false && is_directory_empty(path) != true) reject = true;
    else if (settings->name != NULL && fnmatch(settings->name, basename(path), FNM_PATHNAME) != 0) reject = true;
    else if (settings->path != NULL && fnmatch(settings->path, path, FNM_PATHNAME) != 0) reject = true;
    else if (settings->perm != 0 && settings->perm != inode.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO)) reject = true;
    else if (settings->newer != 0 && settings->newer < get_mtime(path)) reject = true;
    else if (settings->uid != -1 && settings->uid != inode.st_uid) reject = true;
    else if (settings->gid != -1 && settings->gid != inode.st_gid) reject = true;
    return reject;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
