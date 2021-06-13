#include "calculation.h"
#include <stdio.h>
#include <stdlib.h>


int mn ()
{
	float a;
	float b;
	float result;
	int step;
	char time;

	text_menu();
	puts("Selected action:");
	scanf("%d", &step);
	if(step > 0 || step < 5)
	{
		switch (step)
		{
			case 1:
			result = plus(a, b);
			printf("Result = %g\n", result);
			break;

			case 2:
			result = minus(a, b);
			printf("Result = %g\n", result);
			break;

			case 3:
			result = multiplication(a, b);
			printf("Result = %g\n", result);
			break;

			case 4:
			result = division(a, b);
			printf("Result = %g\n", result);
			break;
		}
	}
}
