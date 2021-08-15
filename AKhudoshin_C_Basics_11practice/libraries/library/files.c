#include "files.h"

void print_dir_contents(const char *strdir) {
	
	DIR *dir;
	struct dirent *entry;
	struct stat file_info;
	char full_name[255] = {0};
	
	dir = opendir(strdir);
	
	if(dir) {
		while(entry = readdir(dir)) {
			if(entry->d_name[0] == '.') {
				continue;
			}
			snprintf(full_name, 254, "%s\%s", strdir, entry->d_name);
			if(stat(entry->d_name, &file_info) == 0) {
				printf("size %ld bytes ", file_info.st_size);
			}
			printf("full_name %s\n", full_name);
			memset(full_name, 0, 255);
		}
	}
}
