#include <stdio.h>
#include <math.h>

int main()
{
	int i, k, R, num[100];
	long N, a, b, c;
	while (scanf("%ld%d", &N, &R) != EOF)
	{
		a = abs(N);
		b = R;
		i = 0;
		c = -1;
		while (c != 0)
		{
			c = a / b;
			num[i++] = a % b;
			a = c;
		}
		if (N < 0)
			printf("-");
		for (k = i - 1; k >= 0; k--)
		{
			if (num[k] < 10)
				printf("%d", num[k]);
			else
				printf("%c", 'A' + (num[k] - 10));
		}
		printf("\n");
	}
	return 0;
}
