#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

#include <files.h>

extern char *optarg;
extern int optind, opterr, optopt;

void help(const char *appname) {
	printf("usage: %s [path]\n", appname);
}

int main(int argc, char **argv) {

	int ret;
    bool print_all = false;
    char *dir;

    if (argc == 1) {
        help(argv[0]);
        return 0;
    }

    while ((ret = getopt(argc, argv, "haf:")) != -1) {
        switch(ret) {
            /* Print help */
            case 'h' : {
                help(argv[0]);
                return 0;
            }
            /* Print all contents(including .. and .) */
            case 'a' : {
                print_all = true;
                break;
            }
            /* Specify directory to open */
            case 'f' : {
                dir = optarg;
                break;
            }
        }
    }
	
	print_dir_contents(dir, print_all);
	
}


