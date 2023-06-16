#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//all test sanples have passed:)
//I free the deleted elements in function "encrypt", line 43

struct node
{
	char c;
	struct node* next;
};

struct node* makeLoop(char* p) {
	struct node* h, * p1, * p2;
	h = (struct node*)malloc(sizeof(struct node));
	p1 = h;
	p1->c = *(p++);
	p1->next = NULL;
	while (*p) {
		p2 = (struct node*)malloc(sizeof(struct node));
		p2->c = *(p++);
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
	}
	p1->next = h;
	return h;
}

void encrypt(struct node* h, int key, char* pjm) {
	struct node* p1, * p2;
	int i = 1;	
	p1 = h;
	while (p1->next!=h) {
		p1 = p1->next;
	}
	p2 = h;//p1 is before p2
	while (p2 != p1) {
		if (i++ % key == 0) {
			*(pjm++) = p2->c;
			*pjm = '\0';
			p1->next = p2->next;
			free(p2);

		}
		else
			p1 = p1->next;
		p2 = p1->next;
	}
	*(pjm++) = p2->c;
	*pjm = '\0';
}

int main()
{
	char text[100], cipher[100];
	int key;
	struct node* h;

	puts("Enter some text (length < 100): ");
	gets(text);	//gets(text, sizeof(text));
		printf("Enter the key: ");
	scanf("%d", &key);

	h = makeLoop(text);
	encrypt(h, key, cipher);

	puts("The ciphertext: ");
	puts(cipher);

	return 0;
}