#include<stdio.h>
void Positive(int min,int max)
{
	int i, j;
	for (i = min; i <= max; i++)
	{
		for (j = min; j <= i; j++)
		{
			printf("%d��%d=%-3d  ", j, i, j*i);
		}
		printf("\n");
	}
}

void Reverse(int min, int max)
{
	int i, j;
	for (i = max; i >= min; i--)
	{
		for (j = i; j >= min; j--)
		{
			printf("%d��%d=%-3d  ", j, i, j*i);
		}
		printf("\n");
	}
}

int main()
{
	int min, max,temp;
	char a;
	printf("��ֱ��������޺����ޣ�");
	scanf("%d %d", &min, &max);
	if (min > max)
	{
		temp = min;
		min = max;
		max = temp;
	}
	printf("�Ƿ�����y/n��:");
	getchar();
	fflush(stdin);
	scanf("%c", &a);
	if (a == 'y')Positive(min, max);
	else Reverse(min, max);
}
