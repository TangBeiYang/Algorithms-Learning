#include<stdio.h>
#include<stdlib.h>
// 先写一个把两个有序子数组合成一个更大的有序数组，再递归
void merge(int a[], int left, int mid, int right)
{
	// 左子数组是[left..mid]，右子数组是[mid+1..right]
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = (int*)calloc(n1, sizeof(int));
	int* R = (int*)calloc(n2, sizeof(int));
	for (int i = 0; i < n1; i++) L[i] = a[left + i];
	for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) a[k++] = L[i++]; 
		else a[k++] = R[j++];
	}
	while (i < n1) a[k++] = L[i++];
	while (j < n2) a[k++] = R[j++];
	free(R);free(L);
}
void gui(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;  //防止right+left超范围的写法，更安全
		gui(a, left, mid);
		gui(a, mid+1, right);
		merge(a, left, mid, right);
	}
}

