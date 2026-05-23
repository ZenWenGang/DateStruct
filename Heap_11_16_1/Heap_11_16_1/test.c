#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
//创建数据
void CreateNDate()
{
	int n = 10000;
	srand(time(0));
	FILE* fin = fopen("data.txt", "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int x = (rand() + i) % 100000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
	fin = NULL;
}

void TopK()
{
	int k = 0;
	printf("请输入k:");
	scanf("%d", &k);
	//建堆
	int* HeapK = (int*)malloc(k * sizeof(int));
	if (HeapK == NULL)
	{
		perror("malloc fail");
		return;
	}
	//读取文件前k个数
	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &HeapK[i]);
	}
	//建小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(HeapK, k,i );
	}

	//剩下的n-k个数依次跟堆顶数据比较
	int x = 0;
	while (fscanf(fout, "%d", &x) > 0)
	{
		if (x > HeapK[0])
		{
			HeapK[0] = x;
			AdjustDown(HeapK, k, 0);
		}
	}

	//打印出最大前k个
	printf("最大前%d个数：", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", HeapK[i]);
	}
	printf("\n");
}
int main()
{
	//CreateNDate();

	TopK();
	return 0;
}