#include <stdio.h>
#define OVERFLOW -2
#define OK 1


//顺序栈实现
#define STACK_INIT_SIZE 20   //顺序栈存储空间初始尺寸
#define STACK_INCREMENT 5    //顺序栈存储空间分配增量


typedef struct 
{
	int* base; //存放栈元素的数组
	int top;          //栈顶指示变量
	int stacksize;     //数组初始尺寸
}SqStack; //自定义结构类型SqStack



//初始化栈
int InitStack(SqStack* s) 
{
	s->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	s->top = 0;  //栈顶始终指向实际栈顶元素下一个位置
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}
//判断栈是否空
int StackIsEmpty(SqStack* s) 
{
	return s->top == 0;
}
//入栈
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
//出栈
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
	printf("请分别输入要转化的数和要转换的进制：\n");
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

