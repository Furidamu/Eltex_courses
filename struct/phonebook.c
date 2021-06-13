
#include <stdio.h>

struct data {
	int number[12];
	char name[10];
	char last_name[10];
};

int main(void) {

	int key = 0;
	struct data book [5];

	for (int i = 0; i < 5; i++) {
	printf("Input number: ");
	scanf("%d", book[i].number);
	
	printf("Input name: ");
	scanf("%s", book[i].name);

	printf("Input last name: ");
	scanf("%s", book[i].last_name);
	}

	for (int i = 0; i < 5; i++) {
		printf("Number:%d\t Name:%s\t Last name:%s\n", *book[i].number, book[i].name, book[i].last_name);
	}
	
	printf("Input key\n");
	scanf("%d", &key);

	for (int i = 0; i < 5; i++) {
		if (key == *book[i].number) {
			 printf("Number:%d\t Name:%s\t Last name:%s \n", *book[i].number, book[i].name, book[i].last_name);
		}
	}

    return 0;
}
