#include<stdio.h>
#include<string.h>
#define N 1000
int main()
{
    char s1[N], s2[N];
	int a[N]={0}, b[N]={0}, sum[N]={0}, la, lb, lmax, i;
	scanf("%s", s1);
	scanf("%s", s2);                                         //用数组保存输入的数据
	la = strlen(s1);
	lb = strlen(s2);
	lmax = (la>lb?la:lb) + 1;
	for (i = 0; i < la; i++)
		a[i] = s1[la - i - 1] - '0';
	for (i = 0; i < lb; i++)
		b[i] = s2[lb - i - 1] - '0';                         //在这里进行转置，方便计算
	for (i = 0; i < lmax-1; i++)
	{
		sum[i] = sum[i] + a[i] + b[i];
		sum[i + 1] = (a[i] + b[i]) / 10;
		sum[i] = sum[i] % 10;                                //核心算法
	}
	if (sum[lmax - 1] == 0 && lmax > 0) lmax--;              //删除前面可能得到的0
	for (i = lmax - 1; i >= 0; i--)
		printf("%d", sum[i]);
	return 0;
}