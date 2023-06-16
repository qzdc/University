#define N sizeof list/sizeof list[0];
#include<stdio.h>//已通过样例测试
int* search(int(*p)[5], int n, int id) {
	for (int i = 0; i < n; i++) {
		if (*p[i] == id) {
			return p[i];
		}
	}
	return NULL;
}

void output(int* p) {
	for (int j = 0; j < 5; j++) {
		printf("%-8d", p[j]);
	}
	printf("\n");	
}

int main() {
	int id;
	int list[][5] = { {201001, 75, 85, 77, 59}, {201002, 57, 78, 73, 66},
		{201003, 89, 86, 70, 90}, {201004, 47, 70, 82, 73},
		{201005, 72, 87, 88, 54}, {201006, 90, 96, 99, 99},
		{201007, 81, 97, 99, 67}, {201008, 43, 98, 96, 79},
		{201009, 67, 72, 73, 40}, {201010, 77, 70, 82, 65},
		{201011, 77, 72, 73, 80}, {201012, 47, 70, 82, 73},
		{201013, 77, 82, 83, 50}, {201014, 97, 90, 92, 95},
		{201015, 87, 92, 93, 60}, {201016, 47, 90, 92, 73} };
	int n = N;
	printf("The grade form is: \n");
	for (int i = 0; i < n; i++) {
		output(*(list + i));
	}
	printf("\nEnter a student ID: ");
	scanf_s("%d", &id);
	int* p = search(list, n, id);
	if (p) {
		output(p);
	}
	else {
		printf("The student ID %d is not in the grade form!\n", id);
	}
	return 0;
}