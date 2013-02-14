#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int *a, *b, *c;
	int i, j;
	int order = atoi(argv[1]) + 1;

	a = (int *) malloc(order * sizeof(int));
	b = (int *) malloc(order * sizeof(int));
	c = (int *) malloc((pow(2,order) - 1) * sizeof(int));
	
	printf("Enter the coefficients of A with powers in ascending order:\n"\
		"(i.e x^0 x^1 x^2 ... x^n)\n");

	for (i = 0; i < order; i++)
		scanf("%d", &a[i]);

	printf("Enter the coefficients of B with powers in ascending order:\n");

	for (i = 0; i < order; i++) {
		scanf("%d", &b[i]);
	}

	for (i = 0; i < order; i++) {
		for (j = 0; j < order; j++) {
			c[i + j] += a[i] * b[j];
		}
	}

	for (i = 2*order; i >= 0; i--) {
		if (i == 0 && c[i] != 0)
			printf("%c %d ", c[i] < 0 ? '\0' : '+', c[i]);
		else if(c[i] != 0)
			printf("%c %dx^%d ", c[i] < 0 ? '\0' : '+', c[i], i);
	}


	return 0;
}
