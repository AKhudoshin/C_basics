#include <stdio.h>

void multi_ariphmetics(int *summ, int *diff, int *mult, int *div)
{
	int tmp;
	tmp = *summ;
	*summ = tmp + *diff;
	*mult = tmp * *diff;
	*div = tmp / *diff;
	*diff = tmp - *diff;
		
}

int main()
{
    int summ, diff, mult, div;
    
    printf("Insert two values\n");
    scanf("%d %d", &summ, &diff);
    multi_ariphmetics(&summ, &diff, &mult, &div);
    
    printf("Summ = %d,\nDiff = %d,\nMult = %d,\nDiv = %d", summ, diff, mult, div);
	
    return 0;
}


