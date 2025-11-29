#include<stdio.h>
#include<stdlib.h>
//求min和max
//创建计数数组，长度为(max - min + 1)，并初始化为0
//统计每个元素出现次数将计数数组累加，使得count[i]表示原数组中小于等于(i + min)的元素个数（即最后位置）
//反向遍历原数组，将元素放入输出数组的合适位置（位置 = count[arr[i] - min] - 1），然后count[arr[i] - min]减1
//将输出数组的数据拷贝回原数组
void counting(int a[], int n)
{
	if (n <= 0) return;
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));
	if (!count) return; // 内存分配失败
	for (int i = 0; i < n; i++)
		count[a[i] - min]++;
	for (int i = 1; i < max - min + 1; i++)
		count[i] += count[i - 1];
	int* b = (int*)malloc(n * sizeof(int));
	for (int i = n - 1; i >= 0; i--) 
		b[--count[a[i] - min]] = a[i];
	for (int i = 0; i < n; i++)
		a[i] = b[i];
	free(count);free(b);
}