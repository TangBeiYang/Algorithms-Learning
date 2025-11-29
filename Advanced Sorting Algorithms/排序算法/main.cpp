#include"head.h"
int main()
{
    int m[] = { 4, 2,-2, 8, 3, 3, 1 };
	int n = sizeof(m) / sizeof(m[0]);
    printf("≈≈–Ú«∞: ");
    for (int i = 0; i < n; i++) printf("%d ", m[i]);
    gui(m,0,n-1);
    printf("\n≈≈–Ú∫Û: ");
    for (int i = 0; i < n; i++) printf("%d ", m[i]);
	return 0;
}