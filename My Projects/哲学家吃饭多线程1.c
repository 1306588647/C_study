#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
#include <semaphore.h>

sem_t chopsticks[5];//五个信号量分别表示筷子状态
int chopsticks_con[5] = { 1,1,1,1,1 };//定义筷子状态用于判断

//定义互斥锁，用来限制在哲学家两个筷子都拿到之前，不得有其他哲学家动筷子
pthread_mutex_t mutex;

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

		//加锁，此时只有上一行饿了的哲学家才能拿筷子，其他哲学家不行
		pthread_mutex_lock(&mutex);

		//此哲学家左边筷子信号量减一，减一后信号量为0，继续执行
		sem_wait(&chopsticks[leftchopstick-1]);
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
		
		//由于上面的哲学家已经拿到两根筷子，此时就可以解锁了
		pthread_mutex_unlock(&mutex);

		printf("%d号哲学家开始吃饭！\n",numID);
		delay(50000);//模拟吃饭所用的时间

		sem_post(&chopsticks[leftchopstick-1]);
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

	pthread_mutex_init(&mutex, NULL);//初始化互斥锁

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

	//销毁互斥锁
	pthread_mutex_destroy(&mutex);
	return 0;
}




//哲学家由于互斥锁将拿筷子的代码锁起来了，所以其他哲学家即使很饿也只能等着3号哲学家将另一个筷子拿起来后，另外的哲学家才能拿，导致吃饭效率很低。