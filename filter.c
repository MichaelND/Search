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
    // DIR *d = opendir(path);
    bool reject = false;
    struct stat inode;
    if (lstat(path, &inode) != 0) reject = true;
    if (access(path, settings->access) != 0 && settings->access != 0) reject = true;
    if (inode.st_mode != settings->type && settings->type != 0) reject = true;
    if (is_directory_empty(path) != true && settings->empty != false) reject = true;
    if (fnmatch(settings->name, basename(path), FNM_PATHNAME) != 0 && settings->name != NULL) reject = true;
    if (fnmatch(settings->path, path, FNM_PATHNAME) != 0 && settings->path != NULL) reject = true;
    if (settings->perm != inode.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO) && settings->perm != 0) reject = true;
    if (settings->newer < get_mtime(path) && settings->newer != 0) reject = true;
    if (settings->uid != inode.st_uid && settings->uid != -1) reject = true;
    if (settings->gid != inode.st_gid && settings->gid != -1) reject = true;
    return reject;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
