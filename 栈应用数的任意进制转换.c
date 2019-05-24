#include <stdio.h>
#define OVERFLOW -2
#define OK 1


//˳��ջʵ��
#define STACK_INIT_SIZE 20   //˳��ջ�洢�ռ��ʼ�ߴ�
#define STACK_INCREMENT 5    //˳��ջ�洢�ռ��������


typedef struct 
{
	int* base; //���ջԪ�ص�����
	int top;          //ջ��ָʾ����
	int stacksize;     //�����ʼ�ߴ�
}SqStack; //�Զ���ṹ����SqStack



//��ʼ��ջ
int InitStack(SqStack* s) 
{
	s->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	s->top = 0;  //ջ��ʼ��ָ��ʵ��ջ��Ԫ����һ��λ��
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}
//�ж�ջ�Ƿ��
int StackIsEmpty(SqStack* s) 
{
	return s->top == 0;
}
//��ջ
void Push(SqStack* s, int e) 
{
	if (s->top >= s->stacksize) 
	{
		s->base = (int*)realloc(s->base, (s->stacksize + STACK_INCREMENT) * sizeof(int));
		if (!s->base) exit(OVERFLOW);
		s->stacksize += STACK_INCREMENT;
	}
	s->base[s->top++] = e;
}
//��ջ
int Pop(SqStack* s)
{
	int e;
	e = s->base[--s->top];
	return e;
}

void conversion(SqStack* s)
{
	int num, n;
	InitStack(s);
	printf("��ֱ�����Ҫת��������Ҫת���Ľ��ƣ�\n");
	scanf("%d%d", &num, &n);
	while (num)
	{
		Push(s, num % n);
		num = num / n;
	}
	while (!StackIsEmpty(s))
	{
		printf("%d", Pop(s));
	}
}

int main()
{
	SqStack stk, * s;
	s = &stk;
	conversion(s);
}

