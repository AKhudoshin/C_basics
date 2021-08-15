#include <stdio.h>
#include <mymath.h>

int main(int argc, char **argv) {
	
	int random = myrandom(100);
	
	printf("Random from libmymath.so = %d\n", random);
	
	return 0;
}
