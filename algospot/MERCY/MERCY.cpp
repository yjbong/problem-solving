#include<stdio.h>

void Algospotprintf(int n);

int main()
{
	int n; // n<=10

	scanf("%d", &n);

	Algospotprintf(n);
	return 0;

}

void Algospotprintf(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("Hello Algospot!\n");
	}
}