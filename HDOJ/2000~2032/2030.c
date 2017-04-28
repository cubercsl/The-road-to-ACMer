#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	char s[10000];
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		int cnt = 0;
		gets(s);
		for (int i = 0; i < strlen(s); i++)
			if (s[i] < 0)
				cnt++;
		printf("%d\n", cnt / 2);
	}
	return 0;
}
