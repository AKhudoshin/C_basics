#include <stdio.h>

int main(void) {
	
	unsigned int i;
	int a[5], tmp;
	
	size_t arrayLength = sizeof a / sizeof a[0]; 			// Находим длину массива (для удобства)
	
	for(i=0; i<arrayLength; i++) { scanf("%d", &a[i]); } 	// Вводим массив
	
    for(i=1; i<arrayLength; i++) {
		
		if(a[i-1]>a[i]) { 									//
			tmp = a[i-1]; 									// Переставляем два элемента, чтобы
			a[i-1] = a[i];									// больший находился правее
			a[i] = tmp; 									//
			i = 0;											// И заново просматриваем массив..
		}
	}
	
	for(i=0; i<arrayLength; i++) {
		printf("%d ", a[i]);
	}
	
}
