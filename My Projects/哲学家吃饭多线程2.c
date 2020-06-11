#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
#include <semaphore.h>

sem_t chopsticks[5];//五个信号量分别表示筷子状态
sem_t max;//表示最多max个人拿起左边的筷子，不超过4

int chopsticks_con[5] = { 1,1,1,1,1 };//定义筷子状态用于判断


//定义一个数组，将哲学家们进行编号
int philosophers[5] = {1,2,3,4,5 };

//定义延迟函数，用来模拟哲学家思考和吃饭的时间
void delay(int len)
{
	int i = rand() % len;
	int x;
	while (i > 0)
	{
		x = rand() % len;
		while (x > 0)
		{
			x--;
		}
		i--;
	}
}

void* philosopher(void* index)
{
	//对传入的哲学家编号进行解引用
	int numID = *(int *)index;
	int leftchopstick;
	int rightchopstick;
	if (numID == 5)
	{
		leftchopstick = numID;
		rightchopstick = 1;
	}
	else
	{
		leftchopstick = numID;
		rightchopstick = numID + 1;
	}
	
	while (1)
	{
		int i;
		printf("%d号哲学家正在思考问题。\n", numID);
		delay(50000);//模拟哲学家思考时间
		printf("%d号哲学家想吃饭。\n",numID);

		//此哲学家左边筷子信号量减一，减一后信号量为0，继续执行
		sem_wait(&chopsticks[leftchopstick-1]);
		sem_wait(&max);//当哲学家拿起左边筷子，信号量-1
		chopsticks_con[leftchopstick - 1]--;
		printf("%d号哲学家拿了%d号筷子，只有一根，不能吃饭。\n", numID, leftchopstick);
		printf("空闲筷子：");
		for ( i = 0; i < 5; i++)
		{
			if (chopsticks_con[i])
			{
				printf("%d号\t",i+1);
			}
		}
		printf("\n");
		sem_wait(&chopsticks[rightchopstick-1]);
		chopsticks_con[rightchopstick - 1]--;
		printf("%d号哲学家拿了%d号筷子，有两只筷子，可以吃饭。\n", numID, rightchopstick);
		printf("空闲筷子：");
		for (i = 0; i < 5; i++)
		{
			if (chopsticks_con[i])
			{
				printf("%d号\t", i + 1);
			}
		}
		printf("\n");

		printf("%d号哲学家开始吃饭！\n",numID);
		delay(50000);//模拟吃饭所用的时间

		sem_post(&chopsticks[leftchopstick-1]);
		sem_post(&max);//当哲学家放下左边筷子，信号量+1
		chopsticks_con[leftchopstick - 1]++;
		printf("%d号哲学家放下%d号筷子。\n",numID,leftchopstick);
		printf("空闲筷子：");
		for (i = 0; i < 5; i++)
		{
			if (chopsticks_con[i])
			{
				printf("%d号\t", i + 1);
			}
		}
		printf("\n");
		sem_post(&chopsticks[rightchopstick-1]);
		chopsticks_con[rightchopstick - 1]++;
		printf("%d号哲学家放下%d号筷子。\n",numID,rightchopstick);
		printf("空闲筷子：");
		for (i = 0; i < 5; i++)
		{
			if (chopsticks_con[i])
			{
				printf("%d号\t", i + 1);
			}
		}
		printf("\n");
	}
}

int main()
{
	srand(time(NULL));//初始化随机函数
	
	pthread_t thread[5];//声明五个线程

	int i;

	//初始化信号量
	for ( i = 0; i < 5; i++)
	{
		sem_init(&chopsticks[i], 0, 1);
	}
	sem_init(&max, 0, 4);//最多允许四个人拿起左边筷子


	//创建线程
	for (i = 0; i < 5; i++) {
		pthread_create(&thread[i], NULL, philosopher, &philosophers[i]);
	}

	//挂起线程
	for (i = 0; i < 5; i++) {
		pthread_join(thread[i], NULL);
	}

	//撤销信号量
	for (i = 0; i < 5; i++) {
		sem_destroy(&chopsticks[i]);
	}

	return 0;
}


