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
    fprintf(stderr, "    -name  pattern  Base of file name matches shell pattern\n");
    fprintf(stderr, "    -path  pattern  Path of file matches shell pattern\n\n");
    fprintf(stderr, "    -perm  mode     File's permission bits are exactly mode (octal)\n");
    fprintf(stderr, "    -newer file     File was modified more recently than file\n\n");
    fprintf(stderr, "    -uid   n        File's numeric user ID is n\n");
    fprintf(stderr, "    -gid   n        File's numeric group ID is n\n");
    fprintf(stderr, "    -nemo           Easter Egg\n");
    fprintf(stderr, "\nExpressions:\n\n");
    fprintf(stderr, "    -print          Display file path (default)\n");
    fprintf(stderr, "    -exec cmd {} ;  Execute command on path\n");
    exit(status);
}

Settings settings = {
    .access = 0,
    .uid = -1,
    .gid = -1,
    .print = false,
};

/* Main Execution */

int	    main(int argc, char *argv[]) {
    /* Defining Variables */
    //default values for settings
    
    PROGRAM_NAME = argv[0];
    PATH = argv[1];
    int argind = 2;
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char * arg = argv[argind++];

        if (arg[1] == 'h')
            usage(PROGRAM_NAME, 0);
        else if (streq(arg, "-executable")) {
            settings.access |= X_OK;
        }
        else if (streq(arg, "-readable")) {
            settings.access |= R_OK;
        }
        else if (streq(arg, "-writable")) {
            settings.access |= W_OK;
        }
        else if (streq(arg, "-type")) {
            arg = argv[argind++];
            if (streq(arg, "f"))
                settings.type |= S_IFREG;
            else if (streq(arg, "d"))
                settings.type |= S_IFDIR;
        }
        else if (streq(arg, "-empty")) { //unsure
            settings.empty = 1;
        }
        else if (streq(arg, "-name")) {
            settings.name = argv[argind++];
        }
        else if (streq(arg, "-path")) {
            settings.path = argv[argind++];
        }
        else if (streq(arg, "-perm")) {
            char * ptr;
            arg = argv[argind++];
            settings.perm = strtol(arg, &ptr, 8);
        }
        else if (streq(arg, "-newer")) {
            settings.newer = get_mtime(argv[argind++]);
        }
        else if (streq(arg, "-uid")) {
            settings.uid = atoi(argv[argind++]);
        } 
        else if (streq(arg, "-gid")) {
            settings.gid = atoi(argv[argind++]);
        }
        else if (streq(arg, "-print"))
            settings.print = true;
        else if (streq(arg, "-exec")) {
            settings.exec_argv = &argv[argind];
            while (!streq(argv[argind++], ";")) {
                settings.exec_argc++;
            }
        }
        // else if (streq(arg, "-nemo")) {
        //     while (1) {
        //         printf("Just Keeping Swimming...\n");
        //         printf("><(((('>\n");
        //         sleep(2);
        //     }
        // }
    }

    if (!settings.print && !settings.exec_argc)
        settings.print = true;

    if (PATH != NULL) {
        if (filter(PATH, &settings) == false)
            execute(PATH, &settings);

        search(PATH, &settings);
    }
    
    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
