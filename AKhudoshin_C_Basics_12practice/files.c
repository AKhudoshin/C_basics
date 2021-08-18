#include "files.h"
#include <sys/stat.h>

void print_dir_contents(const char *strdir, bool all) {
	
	DIR *dir;
	struct dirent *entry;
	struct stat file_info;
	char *full_name;

	full_name = (char*)malloc(255);
	
	dir = opendir(strdir);
	
	if(dir != NULL) {
		while((entry = readdir(dir)) != NULL) {
			
			if(entry->d_name[0] == '.' && !all) {
				continue;
			}
			memset(full_name, 0, 255);	
			sprintf(full_name, "%s%s", strdir, entry->d_name);
			full_name[254] = '\0';
			if(stat(full_name, &file_info) == 0) {
				printf("size %10ld bytes ", file_info.st_size);
			
			}
			printf("full_name %s\n", full_name);
			if((((file_info.st_mode & S_IFMT) == S_IFDIR)) && (entry->d_name[0] != '.')) {
				printf("\nSub directory found: %s\n", full_name);
				sprintf(full_name, "%s/", full_name);
				
				print_dir_contents(full_name, all);
			}
		}
		closedir(dir);
	}
	free(full_name);
}
