#include <stdio.h>
#include <stdlib.h>

float plus(float a, float b)
{
	scanf("%f %f", &a, &b);
	return a + b;
}

float minus(float a, float b)
{
	scanf("%f %f", &a, &b);
	return a - b;
}

float multiplication(float a, float b)
{
	scanf("%f %f", &a, &b);
	return a * b;
}

float division(float a, float b)
{
	scanf("%f %f", &a, &b);
	return a / b;
}

void text_menu()
{
	puts("1) Addition");
	puts("2) Subtraction");
	puts("3) Multiplication");
	puts("4) Division");
}


