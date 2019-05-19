#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct student
{
	char StudentName[MAX];
	long StudentID;
	float score[3];						//���ųɼ�
	struct student* next;
}STU;

void LeadStuendt(STU* head);			//1.���ļ���������
void FindStudent(STU* head);			//2.����ѧ����Ϣ
STU* AddStudent(STU *head);				//3.���ѧ����Ϣ
void ModifyStudent(STU* head);			//4.�޸�ѧ����Ϣ
void DeleteStudent(STU* head);			//5.ɾ��ѧ����Ϣ
void StatisticsStudent(STU* head);		//6.ͳ��ѧ���ɼ�
void SortStudent(STU* head);			//7.ѧ���ɼ�����
void PrintStudent(STU* head);			//8.���ѧ��������Ϣ
void SaveStudent(STU* head);			//9.����Ϣ���浽�����ļ�


int main()
{
	STU *head=(STU *)malloc(sizeof(STU));		
	head->next = NULL;
	int a;
	while (1)
	{
		system("cls");
		printf("-----------------------------------------------------------------------------\n");
		printf("||                                �ɼ�����ϵͳ                             ||\n");
		printf("-----------------------------------------------------------------------------\n");
		printf("*                              1.��ȡѧ����Ϣ�ļ�������Ϲ���9����ĸ�ʽ  ��*\n");
		printf("*                              2.��ѯѧ����Ϣ                               *\n");
		printf("*                              3.���ѧ����Ϣ                               *\n");
		printf("*                              4.�޸�ѧ����Ϣ                               *\n");
		printf("*                              5.ɾ��ѧ����Ϣ                               *\n");
		printf("*                              6.ѧ���ɼ�ͳ��                               *\n");
		printf("*                              7.ѧ���ɼ�����                               *\n");
		printf("*                              8.���ѧ��������Ϣ                           *\n");
		printf("*                              9.����ѧ����Ϣ������                         *\n");
		printf("*                              0.�˳�ϵͳ                                   *\n");
		printf("-----------------------------------------------------------------------------\n");


		printf("�����빦����ţ�");
		scanf("%d", &a);
		fflush(stdin);
		switch (a)
		{
		case 1:
			system("cls");
			LeadStuendt(head);				//�ӵ��Ե�������
			break;
		case 2:
			system("cls");
			FindStudent(head);				//��������
			break;
		case 3:
			system("cls");
			head = AddStudent(head);		//�������
			break;
		case 4:
			system("cls");
			ModifyStudent(head);			//�޸�����	
			break;
		case 5:
			system("cls");
			DeleteStudent(head);			//ɾ������
			break;
		case 6:
			system("cls");
			StatisticsStudent(head);		//ͳ������
			break;
		case 7:
			system("cls");
			SortStudent(head);				//��������
			break;
		case 8:
			system("cls");
			PrintStudent(head);				//��ӡ����
			break;
		case 9:
			system("cls");
			SaveStudent(head);				//��������
			break;
		case 0:
			exit(0);
		default:
			printf("��������������������!\n");
			printf("���س����������롣");
			getchar(); getchar(); getchar();
			system("cls");
			break;
		}
	}
}


//1.���ļ���������
void LeadStuendt(STU* head)
{	
	char No[65];
	STU* new,*p=head;
	FILE *fp = fopen("StudentScore.doc","r");
	if (!fp)
	{
		printf("�ļ���ʧ�ܣ�\n");
		printf("���س����������˵�\n");
		getchar(); getchar();
		return;
	}
	fgets(No,64,fp);					//����һ�е�����ѧ����Щ��ʶ������
	while (p->next!=NULL)				//��ָ���Ƶ����һ���ڵ�
	{
		p = p->next;
	}
	while (!feof(fp))					//��������
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
	while (p->next->next!=NULL)				//����feof()�ڽ�����ʱ�򻹻��ٶ�ȡһ�����ݣ�����һ������ɾ��
	{
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	printf("��ȡ�ļ��ɹ���\n");
	printf("���س����������˵���\n");
	getchar(); getchar();
}



//2.����ѧ����Ϣ
void FindStudent(STU* head)
{
	int n;
	int flag = 0;
	STU* move = head->next;
	char name[MAX];
	int ID;
	if (head->next == NULL)
	{
		printf("��ѧ����Ϣ���������ѧ����Ϣ��\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
		return;
	}
A:	system("cls");
	printf("1.����������ѯ\n");
	printf("2.����ѧ�Ų�ѯ\n");
	printf("�������Ϊ��");
	scanf("%d",&n);
	fflush(stdin);
	system("cls");
	if (n == 1)					
	{

		printf("������������ѧ����������");
		scanf("%s", name);
		fflush(stdin);
	}
	else if (n == 2)
	{
		printf("������������ѧ����ѧ�ţ�");
		scanf("%ld",&ID);
		fflush(stdin);
	}
	else
	{
		printf("��������ȷ����ţ�\n");
		printf("���س����������롣");
		getchar(); getchar(); getchar();
		goto A;
	}
	printf("����        ");
	printf("ѧ��        ");
	printf("����        ");
	printf("��ѧ        ");
	printf("Ӣ��        \n");
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
		printf("���ҳɹ���\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
	}
	else
	{
		printf("����ʧ�ܣ���ѧ�������ڣ�\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
	}

}



//3.���ѧ����Ϣ
STU* AddStudent(STU* head)
{
	STU* new;
	STU* p = head;
	int i, n;
	int x;							//��������ĺϷ���
B:	system("cls");
	printf("������Ҫ��Ӽ�λѧ����Ϣ��");
	x = scanf("%d", &n);
	fflush(stdin);
	if (x != 1 || n <= 0)
	{
		printf("��������ȷ�����ѧ��������\n");
		printf("���س��������������ѧ��������");
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
			printf("�������%dλѧ����Ϣ��\n", i + 1);
			printf("������");
			scanf("%s", new->StudentName);
			fflush(stdin);
			printf("ѧ�ţ�");
			scanf("%ld", &new->StudentID);
			fflush(stdin);
Chinese:	printf("���ĳɼ���");
			x = scanf("%f", &new->score[0]);
			fflush(stdin);
			if (x != 1 || new->score[0] < 0)
			{
				printf("���ĳɼ��Ƿ���\n");
				getchar();
				goto Chinese;
			}
Math:		printf("��ѧ�ɼ���");
			x = scanf("%f", &new->score[1]);
			fflush(stdin);
			if (x != 1 || new->score[1] < 0)
			{
				printf("��ѧ�ɼ��Ƿ���\n�밴�س�����������ѧ�ɼ���");
				getchar();
				goto Math;
			}

English:	printf("Ӣ��ɼ���");
			x = scanf("%f", &new->score[2]);
			fflush(stdin);
			if (x != 1 || new->score[2] < 0)
			{
				printf("Ӣ��ɼ��Ƿ���\n�밴�س���������Ӣ��ɼ���");
				getchar();
				goto English;
			}
			p->next = new;
			p = new;
		}
		printf("���ѧ���ɹ���\n");
		printf("���س����������˵���");
		getchar(); getchar();
	}
	return head;
}

//4.�޸�ѧ����Ϣ
void ModifyStudent(STU* head)
{
	int ID;
	STU* move = head->next;
	if (head->next == NULL)
	{
		printf("��ѧ����Ϣ���������ѧ����Ϣ��\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
		return;
	}
	printf("����Ҫ�޸�ѧ����Ϣ��ѧ�ţ�");
	scanf("%ld",&ID);
	fflush(stdin);
	while (move)
	{
		if (move->StudentID == ID)
		{
			printf("���ĳɼ���");
			scanf("%f", &move->score[0]);
			fflush(stdin);
			printf("��ѧ�ɼ���");
			scanf("%f", &move->score[1]);
			fflush(stdin);
			printf("Ӣ��ɼ���");
			scanf("%f", &move->score[2]);
			fflush(stdin);
			printf("��Ϣ�޸ĳɹ���\n");
			printf("���س����������˵���");
			getchar(); getchar();
			return;
		}
		else
		{
			move = move->next;
		}
	}
	printf("δ�ҵ���ѧ����Ϣ��\n");
	printf("���س����������˵���");
	getchar(); getchar();
}




//5.ɾ��ѧ����Ϣ
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
		printf("��ѧ����Ϣ���������ѧ����Ϣ��\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
		return;
	}
C:	system("cls");
	printf("1.��������ɾ��\n");
	printf("2.����ѧ��ɾ��\n");
	printf("�������Ϊ��");
	scanf("%d", &n);
	fflush(stdin);
	system("cls");
	if (n == 1)
	{

		printf("������������ѧ����������");
		scanf("%s", name);
		fflush(stdin);
	}
	else if (n == 2)
	{
		printf("������������ѧ����ѧ�ţ�");
		scanf("%ld", &ID);
		fflush(stdin);
	}
	else
	{
		printf("��������ȷ����ţ�\n");
		printf("���س����������롣");
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
		printf("ɾ���ɹ���\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
	}
	else
	{
		printf("ɾ��ʧ�ܣ���ѧ�������ڣ�\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
	}
}



//6.ͳ��ѧ���ɼ�
void StatisticsStudent(STU* head)
{
	STU* move = head->next;
	int count=0,num,x;
	float low, high;
	if (head->next == NULL)
	{
		printf("��ѧ����Ϣ���������ѧ����Ϣ��\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
		return;
	}
D:	system("cls");
	printf("1.����\n");
	printf("2.��ѧ\n");
	printf("3.Ӣ��\n");
	printf("������Ҫͳ�Ƶ�ѧ�ƣ�");
	x=scanf("%d",&num);
	fflush(stdin);
	if (x!=1||num<0||num>3)
	{
		printf("��������ȷ�ı�ţ�\n");
		printf("���س����������롣");
		getchar(); getchar(); getchar();
		goto D;
	}
E:	printf("������һ�������Σ��磺60--70����\n");
	scanf("%f", &low); 
	getchar();
	getchar(); 
	fflush(stdin);
	scanf("%f", &high); 
	fflush(stdin);
	if (low < 0 || high < 0)
	{
		printf("��������ȷ�ĳɼ�!\n");
		printf("���س����������롣\n");
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
	printf("�÷����ε�ѧ������Ϊ��%d\n",count);
	printf("ͳ�Ƴɹ���\n");
	printf("���س��������˵�\n");
	getchar(); getchar();
	
}

//7.ѧ����Ϣ����
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
		printf("��ѧ����Ϣ���������ѧ����Ϣ��\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
		return;
	}
F:	system("cls");
	printf("1.����\n");
	printf("2.��ѧ\n");
	printf("3.Ӣ��\n");
	printf("����������һ��ѧ������˳��");
	x = scanf("%d", &num);
	fflush(stdin);
	if (x != 1 || num < 0 || num>3)
	{
		printf("��������ȷ�ı�ţ�\n");
		printf("���س����������롣");
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



//8.�������ѧ����Ϣ
void PrintStudent(STU* head)
{
	STU* move=head->next;
	if (head->next == NULL)
	{
		printf("��ѧ����Ϣ���������ѧ����Ϣ��\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
		return;
	}
	printf("����        ");
	printf("ѧ��        ");
	printf("����        ");
	printf("��ѧ        ");
	printf("Ӣ��        \n");
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
	printf("���ѧ�����гɼ��ɹ���\n");
	printf("���س��������˵�\n");
	getchar(); getchar();
}


//9.����Ϣ���浽������
void SaveStudent(STU* head)
{
	FILE* fp = fopen("StudentScore.doc","w");
	if (head->next == NULL)
	{
		printf("��ѧ����Ϣ���������ѧ����Ϣ��\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
		return;
	}
	if (!fp)
	{
		printf("�����ļ�ʧ�ܣ�\n");
		printf("���س��������˵�\n");
		getchar(); getchar();
	}
	STU* move = head->next;

	fprintf(fp,"%s","����           ");
	fprintf(fp,"%s","ѧ��           ");
	fprintf(fp,"%s","����           ");
	fprintf(fp,"%s","��ѧ           ");
	fprintf(fp,"%s","Ӣ��\n");
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
	printf("����ѧ�����гɼ��ɹ���\n");
	printf("���س��������˵�\n");
	getchar(); getchar();
}

