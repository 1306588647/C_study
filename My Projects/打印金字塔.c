#include<stdio.h>
void main()
{
	int n;
	scanf("%d",&n);
	int i, j,k;
	for ( k = 1; k <=n ; k++)
	{
		for (i = n-k; i >= 0; i--)
		{
			putchar(' ');
		}
		for (j = 1; j <=2*(k-1)+1 ; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}
}