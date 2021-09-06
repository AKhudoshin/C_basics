#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

#include "functions.h"

extern char *optarg;
extern int optind, opterr, optopt;

void help(const char *appname) 
  {
    printf("For .csv analysis type %s -f [filename]\n", appname);
    printf("You can use option -m [month number from 1 to 12] to specify info in particullar month\n");
    printf("For help type -h option\n");
  }

int main(int argc, char **argv) 
  {

    int ret;
    bool print_all = true;
    int month = 14;
    char *dir;

    if (argc == 1) {
      help(argv[0]);
      return 0;
    }

    if (argc < 2) {
      return -1;
    }
    while ((ret = getopt(argc, argv, "hm:f:")) != -1) {
        switch(ret) {
            /* Print help */
            case 'h' : {
                help(argv[0]);
                return 0;
            }
            /* Specify month to view */
            case 'm' : {
                print_all = false;
                month = atoi(optarg);
                break;
            }
            /* Specify file to read */
            case 'f' : {
                dir = optarg;
                break;
            }
        }
    }

    read_and_process_file(dir, print_all, month-1);
  }
