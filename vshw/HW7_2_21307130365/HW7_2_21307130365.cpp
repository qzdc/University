#include<stdio.h>
#include<string.h>
int main()
{
	char a[105], b[105], test[105];
	int n, i, j, key, rank;
	printf("Enter a line of text:\n");
	gets(a);
	n = strlen(a);
	for(i = 0; i < n; i++)
		test[i] = 1;
	printf("Enter the key: ");
	scanf("%d", &key);
	i = 0;
	j = 0;
	while(j != n){
		rank = 0;
		for(; rank != key;i = (i + 1) % n){
			if(test[i])
				rank++;
			if(rank == key){
				b[i] = a[j++];
				test[i] = 0;
			}
		}
	}
	b[n ] = '\0';
	printf("The cipher text:\n");
	puts(b);
	return 0;
 } 
