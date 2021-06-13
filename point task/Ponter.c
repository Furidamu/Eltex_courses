#include <stdio.h>

struct Data {
	char a;
	char b;
	char c;
	int d;
	struct Data *Ptr;
};

int main (void) {
	struct Data exmp;
	
	printf("%d\t %d\n", sizeof(exmp), sizeof(exmp.Ptr));
	printf("%p\t %p\n", exmp, exmp.Ptr);

	return 0;
}
