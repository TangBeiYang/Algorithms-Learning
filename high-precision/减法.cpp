#include<stdio.h>
#include<string.h>
#define N 1000
int main()
{
    char s1[N], s2[N], s3[N];
	int a[N], b[N], c[N], la, lb, i, flag = 0;
	scanf("%s", s1); 
	scanf("%s", s2);                                          //用数组保存输入的数据
	la = strlen(s1); 
	lb = strlen(s2);
	if (la < lb)
	{
		strcpy(s3, s1); strcpy(s1, s2); strcpy(s2, s3);
		i = la; la = lb; lb = i;
		flag = 1;                                             //flag用来表示是否输出负号的状态
	}
	else if (la == lb)
	{
		for (i = 0; i < la; i++)
		{
			if (s1[i] > s2[i]) { break; }
			else if (s1[i] < s2[i]) 
			{ 
				strcpy(s3, s1); strcpy(s1, s2); strcpy(s2, s3);
				flag = 1; break; 
			}
		}                                                    //判断输入的两数大小，保证大数减小数
		if (i == la) { printf("0"); return 0; }
	}
    for (i = 0; i < la; i++)
		a[i] = s1[la - i - 1] - '0';
	for (i = 0; i < lb; i++)
		b[i] = s2[lb - i - 1] - '0';
    for (i = 0; i < la; i++)
	{
		if(a[i]<b[i])
        {
            a[i+1]--;
            a[i]+=10;
        }
		c[i]=a[i]-b[i];                                      //核心算法
	}
    while (c[la - 1] == 0 && la > 0) la--;                   //删除前面的所有0
	if (flag) { printf("-"); }                               //检测flag状态
    for (i = la - 1; i >= 0; i--)
		printf("%d", c[i]);
    return 0;
}