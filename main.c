/* driver.c */

#include "search.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <unistd.h>
/* Globals */

char * PROGRAM_NAME = NULL;
char * PATH = NULL;
/* Functions */

void	    usage(const char *program_name, int status) {
    fprintf(stderr, "Usage: %s PATH [OPTIONS] [EXPRESSION]\n", program_name);
    fprintf(stderr, "\nOptions:\n");
    fprintf(stderr, "    -executable     File is executable or directory is searchable to user\n");
    fprintf(stderr, "    -readable       File readable to user\n");
    fprintf(stderr, "    -writable       File is writable to user\n\n");
    fprintf(stderr, "    -type [f|d]     File is of type f for regular file or d for directory\n\n");
    fprintf(stderr, "    -empty          File or directory is empty\n\n");
    fprintf(stderr, "    -empty          File or directory is empty\n\n");
    fprintf(stderr, "    -name  pattern  Base of file name matches shell pattern\n");
    fprintf(stderr, "    -path  pattern  Path of file matches shell pattern\n\n");
    fprintf(stderr, "    -perm  mode     File's permission bits are exactly mode (octal)\n");
    fprintf(stderr, "    -newer file     File was modified more recently than file\n\n");
    fprintf(stderr, "    -uid   n        File's numeric user ID is n\n");
    fprintf(stderr, "    -gid   n        File's numeric group ID is n\n");
    fprintf(stderr, "\nExpressions:\n\n");
    fprintf(stderr, "    -print          Display file path (default)\n");
    fprintf(stderr, "    -exec cmd {} ;  Execute command on path\n");
    exit(status);
}

/* Main Execution */

int	    main(int argc, char *argv[]) {
    /* Defining Variables */
    //default values for settings
    Settings settings = {
        .access = 0,
        .uid = -1,
        .gid = -1,
    };
    
    PROGRAM_NAME = argv[0];
    PATH = argv[1];
    int argrind = 1;
    while (argrind < argc && strlen(argv[argrind]) > 1 && argv[argrind][0] == '-') {
        char * arg = argv[argrind++];

        if streq(arg, "-executable")
        switch(arg[1]) {
            case 'h':
                usage(0);
                break;
            case 'executable':
                settings.access |= X_OK;
                break;
            case 'readable':
                settings.access |= R_OK;
                break;
            case 'writable':
                settings.access |= W_OK;
                break;
            case 'type':
                settings.type
                break;
            case 'empty':
                settings.
                break;
            case 'name':
                break;
            case 'path':
                break;
            case 'perm':
                break;
            case 'newer':
                break;
            case 'uid':
                break;
            case 'gid':
                break;
            case 'print':
                break;
            case 'exec':
                break;
            default:
                usage(1);
                break;
        }
    }
    
    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
