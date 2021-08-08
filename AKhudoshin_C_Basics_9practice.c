#include <stdio.h>
#include <string.h>
#include <ctype.h>

int str_sum_digits(const char *s) {
	int sum=0, i=0;
	for(i=0; i<20; i++) {
		if( isdigit(s[i]) ) {
			sum = sum + (s[i]-'0');
		}
	}
	return sum;
}
	

int main(void) {
	
	char s[20], c;
    int i=0;
    printf("Enter string w or wo numbers\n");
    while( (c=getchar())!='\n' ) {
		s[i++]=c;		
	}
	
    s[i]='\0';
        
 printf("\nSum of numbers in string is %d\n", str_sum_digits(s));

}
