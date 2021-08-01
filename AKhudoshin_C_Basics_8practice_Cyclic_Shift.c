#include <stdio.h>

int main(void) {
	
	unsigned int i;
	int a[5], b[5], tmp;
	
	size_t arrayLength = sizeof a / sizeof a[0]; 			// Находим длину массива (для удобства)
	
	for(i=0; i<arrayLength; i++) { scanf("%d", &a[i]); } 	// Вводим массив
	
	tmp = a[0];												// Сохраняем первый элемент массива
	for(i=0; i<arrayLength-1; i++) {
		b[i] = a[i+1];	
	}
	b[arrayLength-1] = tmp;
	
	for(i=0; i<arrayLength; i++) {
		a[i]=b[i];
		printf("%d ", a[i]);
	}
	
}
