#include<stdio.h>
int main()
{
	int m,d,y,numb;
	float price;
	printf("Enter item number:");
	scanf_s("%d",&numb);
	printf("Enter unit price:");
	scanf_s("%f", &price);
	printf("Enter purchase date(mm/dd/yyyy):");
	scanf_s("%d/%d/%d", &m, &d, &y);
	/*printf("%d,%d,%d,%d", m, d, y, numb);*/
	printf("Item\tUnit\t\tPurchace\n");
	printf("\tPrice\t\tDate\n");
	printf("%3d\t$%7.2f\t%04d%02d%02d", numb, price, y, m, d);
	return 0;

}