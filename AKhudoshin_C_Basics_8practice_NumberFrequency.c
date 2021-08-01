#include <stdio.h>

int main()
{
	unsigned int i, max = 0, numberOfMaxInArray = 0;
	int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char c;
    while( (c=getchar())!='.') {
		if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c==' ')) {
			++c;														// Игнорируем буквы
		}
		if(c=='0') { a[0]++; }											
		if(c=='1') { a[1]++; }
		if(c=='2') { a[2]++; }
		if(c=='3') { a[3]++; }
		if(c=='4') { a[4]++; }
		if(c=='5') { a[5]++; }
		if(c=='6') { a[6]++; }
		if(c=='7') { a[7]++; }
		if(c=='8') { a[8]++; }
		if(c=='9') { a[9]++; }
	}
	for(i=0; i<10; i++) {
		if(a[i]>max) { 
			max = a[i]; 
			numberOfMaxInArray = i;
		}
		printf("number %d: %d times\n", i, a[i]);
	}
	
		printf("Number %d is the most frequent number in the string, it was inserted %d times \n", numberOfMaxInArray, max);
	
	
    return 0;
}


