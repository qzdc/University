#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int menu(int s){
	int a1, a2, a3, a4, r;
	if(s == 1|| s ==2)
		printf("����㣺\n");
	srand(time(NULL));	
	char a[3][25] = {"Very good!","Excellent!","Keep up the good work!"};
	char b[3][40] = {"No.Please try again.","Wrong.Try once more.","No.Keep trying."};
	switch(s){
		case 1: 
			a1 = rand() % 10;
			a2 = rand() % 10;
			a3 = a1 * a2;
			r = rand() % 3;
			printf("%d��%d=", a1, a2);
			scanf("%d", &a4);
			if (a3 == a4){
				printf("%s\n", a[r]);
				return 1;
			}
			else {
				printf("%s\n", b[r]);
				printf("%d��%d=%d\n", a1, a2, a3);
				return 1;
			}
			break;
		case 2: 
			a1 = rand() % 90 + 10;
			a2 = rand() % 100;
			a3 = a1 * a2;
			r = rand() % 3;
			printf("%d��%d=", a1, a2);
			scanf("%d", &a4);
			if (a3 == a4){
				printf("%s\n", a[r]);
				return 1;
			}
			else {
				printf("%s\n", b[r]);
				printf("%d��%d=%d\n", a1, a2, a3);
				return 1;
			}
			break;
		case 3:
			return 0;
			break;
	}
}

int main()
{
	int s, i = 1;
	printf("/***�˷�С����***/\n");
	while(i){
		printf("��ѡ��\n\t1.һλ���˷�\n\t2.��λ���˷�\n\t3.�˳�С����\n") ; 
		scanf("%d", &s);
		i = menu(s);	
	}
	return 0;
}
