#include <stdio.h>

int main()
{
	int a[102] = {0}, m, n;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int count = 0, sum = 0, flag = 0;
		for (int i = 0; i < n; i++)
			a[i] = 2 * (i + 1);
		for (int i = 0; i < n; i++)
		{
			sum += a[i];
			count++;
			if (count == m)
			{
				if (flag == 1)
					printf(" ");
				printf("%d", sum / m);
				sum = 0;
				count = 0;
				flag = 1;
			}
		}
		if (sum != 0)
			printf(" %d", sum / count);
		printf("\n");
	}
	return 0;
}
