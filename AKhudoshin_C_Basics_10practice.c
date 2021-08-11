#include <stdio.h>
#include <io.h>

int main()
{
	FILE *f1, *f2;
      
    static char fileName1[100]={0}, fileName2[100]={0};
    char buffer[512];
    int n;
    size_t size;
    
    printf("Enter source file: ");
    scanf("%s", &fileName1);
    
    printf("\nEnter destination file: ");
	scanf("%s", &fileName2);
    
    f1 = fopen(fileName1, "rb");
       
    if (f1 != NULL) {
		f2 = fopen(fileName2, "wb");
		while ((n = read(fileno(f1), buffer, sizeof buffer)) > 0) {
			write(fileno(f2), buffer, n);  
		}
        fseek(f1, 0, SEEK_END);
        size = ftell(f1);
		printf("Copy of '%s' file done. Transfered %llu bytes.\n", fileName1, size);
    } else {
        printf("Error. Can't open file %s\n", fileName1);
        return 0;
    }
    fclose(f1);
    fclose(f2);
}
