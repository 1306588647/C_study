#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct student
{
	char StudentName[MAX];
	long StudentID;
	float score[3];						//三门成绩
	struct student* next;
}STU;

void LeadStuendt(STU* head);			//1.从文件导入数据
void FindStudent(STU* head);			//2.查找学生信息
STU* AddStudent(STU *head);				//3.添加学生信息
void ModifyStudent(STU* head);			//4.修改学生信息
void DeleteStudent(STU* head);			//5.删除学生信息
void StatisticsStudent(STU* head);		//6.统计学生成绩
void SortStudent(STU* head);			//7.学生成绩排序
void PrintStudent(STU* head);			//8.输出学生所有信息
void SaveStudent(STU* head);			//9.将信息保存到电脑文件


int main()
{
	STU *head=(STU *)malloc(sizeof(STU));		
	head->next = NULL;
	int a;
	while (1)
	{
		system("cls");
		printf("-----------------------------------------------------------------------------\n");
		printf("||                                成绩管理系统                             ||\n");
		printf("-----------------------------------------------------------------------------\n");
		printf("*                              1.读取学生信息文件（需符合功能9保存的格式  ）*\n");
		printf("*                              2.查询学生信息                               *\n");
		printf("*                              3.添加学生信息                               *\n");
		printf("*                              4.修改学生信息                               *\n");
		printf("*                              5.删除学生信息                               *\n");
		printf("*                              6.学生成绩统计                               *\n");
		printf("*                              7.学生成绩排序                               *\n");
		printf("*                              8.输出学生所有信息                           *\n");
		printf("*                              9.保存学生信息到电脑                         *\n");
		printf("*                              0.退出系统                                   *\n");
		printf("-----------------------------------------------------------------------------\n");


		printf("请输入功能序号：");
		scanf("%d", &a);
		fflush(stdin);
		switch (a)
		{
		case 1:
			system("cls");
			LeadStuendt(head);				//从电脑导入数据
			break;
		case 2:
			system("cls");
			FindStudent(head);				//查找数据
			break;
		case 3:
			system("cls");
			head = AddStudent(head);		//添加数据
			break;
		case 4:
			system("cls");
			ModifyStudent(head);			//修改数据	
			break;
		case 5:
			system("cls");
			DeleteStudent(head);			//删除数据
			break;
		case 6:
			system("cls");
			StatisticsStudent(head);		//统计数据
			break;
		case 7:
			system("cls");
			SortStudent(head);				//排序数据
			break;
		case 8:
			system("cls");
			PrintStudent(head);				//打印数据
			break;
		case 9:
			system("cls");
			SaveStudent(head);				//保存数据
			break;
		case 0:
			exit(0);
		default:
			printf("序号输入错误请重新输入!\n");
			printf("按回车键重新输入。");
			getchar(); getchar(); getchar();
			system("cls");
			break;
		}
	}
}


//1.从文件导入数据
void LeadStuendt(STU* head)
{	
	char No[65];
	STU* new,*p=head;
	FILE *fp = fopen("StudentScore.doc","r");
	if (!fp)
	{
		printf("文件打开失败！\n");
		printf("按回车键返回主菜单\n");
		getchar(); getchar();
		return;
	}
	fgets(No,64,fp);					//将第一行的姓名学号这些标识符吸收
	while (p->next!=NULL)				//将指针移到最后一个节点
	{
		p = p->next;
	}
	while (!feof(fp))					//导入数据
	{
		new = (STU*)malloc(sizeof(STU));
		new->next = NULL;
		fscanf(fp,"%s",new->StudentName);
		fscanf(fp, "%ld", &new->StudentID);
		for (int i = 0; i < 3; i++)
		{
			fscanf(fp, "%f", &new->score[i]);
		}
		p->next = new;
		p = new;
	}
	p = head->next;
	head->next = p->next;
	free(p);
	p = head->next;	
	while (p->next->next!=NULL)				//由于feof()在结束的时候还会再读取一行数据，将这一行数据删除
	{
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	printf("读取文件成功！\n");
	printf("按回车键返回主菜单！\n");
	getchar(); getchar();
}



//2.查找学生信息
void FindStudent(STU* head)
{
	int n;
	int flag = 0;
	STU* move = head->next;
	char name[MAX];
	int ID;
	if (head->next == NULL)
	{
		printf("无学生信息，请先添加学生信息！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
		return;
	}
A:	system("cls");
	printf("1.输入姓名查询\n");
	printf("2.输入学号查询\n");
	printf("您输入的为：");
	scanf("%d",&n);
	fflush(stdin);
	system("cls");
	if (n == 1)					
	{

		printf("请输入所查找学生的姓名：");
		scanf("%s", name);
		fflush(stdin);
	}
	else if (n == 2)
	{
		printf("请输入所查找学生的学号：");
		scanf("%ld",&ID);
		fflush(stdin);
	}
	else
	{
		printf("请输入正确的序号！\n");
		printf("按回车键重新输入。");
		getchar(); getchar(); getchar();
		goto A;
	}
	printf("姓名        ");
	printf("学号        ");
	printf("语文        ");
	printf("数学        ");
	printf("英语        \n");
	while (move != NULL)
	{
		if (n == 1)
		{
			if (strcmp(name, move->StudentName))
			{
				move = move->next;
			}
			else
			{
				int i;
				printf("%-12s", move->StudentName);
				printf("%-12ld", move->StudentID);
				for (i = 0; i < 3; i++)
				{
					printf("%-12.2f", move->score[i]);
				}
				printf("\n");
				move = move->next;
				flag = 1;
			}
		}
		else if (n == 2)
		{
			if (ID!=move->StudentID)
			{
				move = move->next;
			}
			else
			{
				int i;
				printf("%-12s", move->StudentName);
				printf("%-12ld", move->StudentID);
				for (i = 0; i < 3; i++)
				{
					printf("%-12.2f", move->score[i]);
				}
				printf("\n");
				move = move->next;
				flag = 1;
			}
		}
		
	}
	if (flag)
	{
		printf("查找成功！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
	}
	else
	{
		printf("查找失败，该学生不存在！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
	}

}



//3.添加学生信息
STU* AddStudent(STU* head)
{
	STU* new;
	STU* p = head;
	int i, n;
	int x;							//检验输入的合法性
B:	system("cls");
	printf("请输入要添加几位学生信息：");
	x = scanf("%d", &n);
	fflush(stdin);
	if (x != 1 || n <= 0)
	{
		printf("请输入正确的添加学生人数！\n");
		printf("按回车键重新输入添加学生人数！");
		getchar(); getchar();
		goto B;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		for (i = 0; i < n; i++)
		{
			new = (STU*)malloc(sizeof(STU));
			new->next = NULL;
			printf("请输入第%d位学生信息：\n", i + 1);
			printf("姓名：");
			scanf("%s", new->StudentName);
			fflush(stdin);
			printf("学号：");
			scanf("%ld", &new->StudentID);
			fflush(stdin);
Chinese:	printf("语文成绩：");
			x = scanf("%f", &new->score[0]);
			fflush(stdin);
			if (x != 1 || new->score[0] < 0)
			{
				printf("语文成绩非法！\n");
				getchar();
				goto Chinese;
			}
Math:		printf("数学成绩：");
			x = scanf("%f", &new->score[1]);
			fflush(stdin);
			if (x != 1 || new->score[1] < 0)
			{
				printf("数学成绩非法！\n请按回车重新输入数学成绩！");
				getchar();
				goto Math;
			}

English:	printf("英语成绩：");
			x = scanf("%f", &new->score[2]);
			fflush(stdin);
			if (x != 1 || new->score[2] < 0)
			{
				printf("英语成绩非法！\n请按回车重新输入英语成绩！");
				getchar();
				goto English;
			}
			p->next = new;
			p = new;
		}
		printf("添加学生成功！\n");
		printf("按回车键返回主菜单！");
		getchar(); getchar();
	}
	return head;
}

//4.修改学生信息
void ModifyStudent(STU* head)
{
	int ID;
	STU* move = head->next;
	if (head->next == NULL)
	{
		printf("无学生信息，请先添加学生信息！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
		return;
	}
	printf("输入要修改学生信息的学号：");
	scanf("%ld",&ID);
	fflush(stdin);
	while (move)
	{
		if (move->StudentID == ID)
		{
			printf("语文成绩：");
			scanf("%f", &move->score[0]);
			fflush(stdin);
			printf("数学成绩：");
			scanf("%f", &move->score[1]);
			fflush(stdin);
			printf("英语成绩：");
			scanf("%f", &move->score[2]);
			fflush(stdin);
			printf("信息修改成功！\n");
			printf("按回车键返回主菜单！");
			getchar(); getchar();
			return;
		}
		else
		{
			move = move->next;
		}
	}
	printf("未找到该学生信息！\n");
	printf("按回车键返回主菜单！");
	getchar(); getchar();
}




//5.删除学生信息
void DeleteStudent(STU* head)
{
	int n;
	char name[MAX];
	int ID;
	STU* right;
	STU* left;
	int flag = 0;
	if (head->next == NULL)
	{
		printf("无学生信息，请先添加学生信息！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
		return;
	}
C:	system("cls");
	printf("1.输入姓名删除\n");
	printf("2.输入学号删除\n");
	printf("您输入的为：");
	scanf("%d", &n);
	fflush(stdin);
	system("cls");
	if (n == 1)
	{

		printf("请输入所查找学生的姓名：");
		scanf("%s", name);
		fflush(stdin);
	}
	else if (n == 2)
	{
		printf("请输入所查找学生的学号：");
		scanf("%ld", &ID);
		fflush(stdin);
	}
	else
	{
		printf("请输入正确的序号！\n");
		printf("按回车键重新输入。");
		getchar(); getchar(); getchar();
		goto C;
	}
	left = head;
	right = left->next;
	while (right)
	{
		if (n == 1)
		{
			if (!strcmp(right->StudentName, name))
			{
				left->next = right->next;
				free(right);
				right = left->next;
				flag = 1;
				break;
			}
			else
			{
				right = right->next;
				left = left->next;
			}
		}
		else if (n == 2)
		{
			if (right->StudentID ==ID)
			{
				left->next = right->next;
				free(right);
				right = left->next;
				flag = 1;
				break;
			}
			else
			{
				right = right->next;
				left = left->next;
			}
		}
	}
	if (flag)
	{
		printf("删除成功！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
	}
	else
	{
		printf("删除失败，该学生不存在！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
	}
}



//6.统计学生成绩
void StatisticsStudent(STU* head)
{
	STU* move = head->next;
	int count=0,num,x;
	float low, high;
	if (head->next == NULL)
	{
		printf("无学生信息，请先添加学生信息！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
		return;
	}
D:	system("cls");
	printf("1.语文\n");
	printf("2.数学\n");
	printf("3.英语\n");
	printf("请输入要统计的学科：");
	x=scanf("%d",&num);
	fflush(stdin);
	if (x!=1||num<0||num>3)
	{
		printf("请输入正确的编号！\n");
		printf("按回车键重新输入。");
		getchar(); getchar(); getchar();
		goto D;
	}
E:	printf("请输入一个分数段（如：60--70）：\n");
	scanf("%f", &low); 
	getchar();
	getchar(); 
	fflush(stdin);
	scanf("%f", &high); 
	fflush(stdin);
	if (low < 0 || high < 0)
	{
		printf("请输入正确的成绩!\n");
		printf("按回车键重新输入。\n");
		getchar(); getchar(); getchar();
		goto E;
	}
	while (move)
	{
		if (move->score[num - 1] >= low && move->score[num - 1] < high)
		{
			count++;
			move = move->next;
		}
		else
		{
			move = move->next;
		}
	}
	printf("该分数段的学生数量为：%d\n",count);
	printf("统计成功！\n");
	printf("按回车返回主菜单\n");
	getchar(); getchar();
	
}

//7.学生信息排序
void SortStudent(STU* head)
{
	STU* move; 
	STU* p;
	STU* max;
	int num,x;
	float temp;
	char NameTemp[MAX];
	long IDTemp;
	if (head->next == NULL)
	{
		printf("无学生信息，请先添加学生信息！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
		return;
	}
F:	system("cls");
	printf("1.语文\n");
	printf("2.数学\n");
	printf("3.英语\n");
	printf("请输入以哪一个学科排列顺序：");
	x = scanf("%d", &num);
	fflush(stdin);
	if (x != 1 || num < 0 || num>3)
	{
		printf("请输入正确的编号！\n");
		printf("按回车键重新输入。");
		getchar(); getchar(); getchar();
		goto F;
	}
	for (p =head->next;p->next!=NULL;p=p->next)
	{
		max = p;
		for(move = p->next;move;move=move->next)
		{
			if (move->score[num - 1] > p->score[num - 1])
			{
				max = move;
			}
		}
		if (max != p)
		{
			strcpy(NameTemp,max->StudentName);
			strcpy(max->StudentName, p->StudentName);
			strcpy(p->StudentName, NameTemp);

			IDTemp = max->StudentID;
			max->StudentID = p->StudentID;
			p->StudentID = IDTemp;
			int i;
			for ( i = 0; i < 3; i++)
			{
				temp = max->score[i];
				max->score[i] = p->score[i];
				p->score[i] = temp;
			}
		}
	}
	system("cls");
	PrintStudent(head);
}



//8.输出所有学生信息
void PrintStudent(STU* head)
{
	STU* move=head->next;
	if (head->next == NULL)
	{
		printf("无学生信息，请先添加学生信息！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
		return;
	}
	printf("姓名        ");
	printf("学号        ");
	printf("语文        ");
	printf("数学        ");
	printf("英语        \n");
	while (move)
	{
		int i;
		printf("%-12s", move->StudentName);
		printf("%-12ld", move->StudentID);
		for (i = 0; i < 3; i++)
		{
			printf("%-12.2f", move->score[i]);
		}
		printf("\n");
		move = move->next;
	}
	printf("输出学生所有成绩成功！\n");
	printf("按回车返回主菜单\n");
	getchar(); getchar();
}


//9.将信息保存到电脑上
void SaveStudent(STU* head)
{
	FILE* fp = fopen("StudentScore.doc","w");
	if (head->next == NULL)
	{
		printf("无学生信息，请先添加学生信息！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
		return;
	}
	if (!fp)
	{
		printf("创建文件失败！\n");
		printf("按回车返回主菜单\n");
		getchar(); getchar();
	}
	STU* move = head->next;

	fprintf(fp,"%s","姓名           ");
	fprintf(fp,"%s","学号           ");
	fprintf(fp,"%s","语文           ");
	fprintf(fp,"%s","数学           ");
	fprintf(fp,"%s","英语\n");
	while (move)
	{
		int i;
		fprintf(fp,"%-15s", move->StudentName);
		fprintf(fp,"%-15ld", move->StudentID);
		for (i = 0; i < 3; i++)
		{
			fprintf(fp,"%-15.2f", move->score[i]);
		}
		fprintf(fp,"%s","\n");
		move = move->next;
	}
	fclose(fp);
	printf("保存学生所有成绩成功！\n");
	printf("按回车返回主菜单\n");
	getchar(); getchar();
}

