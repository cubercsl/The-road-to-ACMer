#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int a[100], lcm;
		int flag = 1;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		lcm = a[n - 1];
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < n; i++)
				if (lcm % a[i] != 0)
				{
					flag = 1;
					break;
				}
			lcm++;
		}
		printf("%d\n", lcm - 1);
	}
	return 0;
}
