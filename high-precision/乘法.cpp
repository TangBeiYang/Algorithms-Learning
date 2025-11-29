#include<stdio.h>
#include<string.h>
#define N 1000
int main()
{
	char s1[N], s2[N];
	int a[N] = { 0 }, b[N] = { 0 }, c[N] = { 0 };
	int la, lb, lc, i, j;
	scanf("%s", s1);
	scanf("%s", s2);                                //用数组保存输入的数据
	la = strlen(s1);
	lb = strlen(s2);
	lc = la + lb;                                   //两数相乘所得积位数约为乘数位数的积
	for (i = 0; i < la; i++)
		a[i] = s1[la - i - 1] - '0';
	for (i = 0; i < lb; i++)
		b[i] = s2[lb - i - 1] - '0';                //转置方便计算
	for (i = 0; i < la; i++)
		for (j = 0; j < lb; j++)
		{
			c[i + j - 1] += a[i] * b[j];
			c[i + j] += c[i + j - 1] / 10;
			c[i + j - 1] %= 10;                     //核心算法，利用循环嵌套确保不遗漏
		}
	while (c[lc] == 0 && lc > 0) lc--;              //去除前面所有0
	for (i = lc; i >= 0; i--)
		printf("%d", c[i]);
    return 0;
}