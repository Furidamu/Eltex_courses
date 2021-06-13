#include <stdio.h>

struct data {
	int a;
	char b; 
	char c;
	char d;
	double e;
};

int main () {
	
	struct data info;

	int x = 100;
	int *ptr1, *ptr2, *ptr3;
	int size = 0, size1 = 0;
	
	ptr1 = &x;
	ptr2 = ptr1;

	info.a = 1;
	ptr3 = &info.a;
	
	printf("ptr1 = %d\tptr2 = %d\n", *ptr1, *ptr2); //print value ptr1 and ptr2
	
	printf("ptr1 = %p\t ptr2 =  %p\n", ptr1, ptr2); //print addres ptr1 and ptr2;

	size = sizeof (info);// size struct;

	size1 = sizeof(info.a);
		
	printf("Addres struct info = %p\n ptr3 = %d\n", ptr3, *ptr3);

	printf("size1 = %d\n", size1);//print size data.a

	printf("size struct = %d\n", size); //print size struct INFO

	return 0;
}
