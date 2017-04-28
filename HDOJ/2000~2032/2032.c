#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int a[30][30];
		for (int i = 0; i < n; i++)
			a[i][0] = a[i][i] = 1;
		for (int i = 2; i < n; i++)
			for (int j = 1; j < i; j++)
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
				printf("%d ", a[i][j]);
			printf("%d\n", a[n - 1][n - 1]);
		}
		printf("\n");
	}
	return 0;
}