#include<stdio.h>
//选基准：从数组中任选一元素作为基准值（pivot）
// 分区：将数组分为两部分——小于基准的左子数组 + 大于基准的右子数组
// 递归：对左右子数组重复上述过程，直至子数组长度为1（天然有序）。
void swap(int* a, int* b){
	int temp=*a;
    *a=*b;
    *b=temp;
}
int yfy(int a[], int low, int high){
    int temp = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (a[j] <= temp){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}
void quick(int a[], int low, int high){
    if (low < high) {
        int pi = yfy(a, low, high); 
        quick(a, low, pi - 1);        
        quick(a, pi + 1, high);       
    }
}
