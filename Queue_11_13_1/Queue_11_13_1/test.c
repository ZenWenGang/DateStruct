#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d",QueueFront(&q) );
		QueuePop(&q);//只有删掉一个数据才能取到下一个数据
	}
	printf("\n");
	QueueDestroy(&q);
	return 0;
}