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
    DIR *d = opendir(path);
    bool reject = false;
    struct stat inode;
    if (lstat(path, &inode) != 0) return reject;
    else if (access(path, settings->access) != 0) reject = true;
    else if (inode.st_mode != settings->type) reject = true;
    else if (is_directory_empty(path) != true ) reject = true;
    else if (fnmatch(settings->name, basename(path), FNM_PATHNAME) != 0) reject = true;
    else if (fnmatch(settings->path, path, FNM_PATHNAME) != 0 ) reject = true;
    else if (settings->perm != inode.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO)) reject= true;
    else if (settings->newer < get_mtime(path)) reject = true;
    else if (settings->uid != inode.st_uid) reject = true;
    else if (settings->gid != inode.st_gid) reject = true;
    return reject;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
