#include <bits/stdc++.h>
using namespace std;
long long cnt;
void merge_sort(int *A, int x, int y, int *T)
{
	if (y - x > 1)
	{
		int m = x + (y - x) / 2;
		int p = x, q = m, i = x;
		merge_sort(A, x, m, T);
		merge_sort(A, m, y, T);
		while (p < m || q < y)
		{
			if (q >= y || (p < m && A[p] <= A[q]))
				T[i++] = A[p++];
			else
			{
				T[i++] = A[q++];
				cnt += m - p;
			}
		}
		for (i = x; i < y; i++)
			A[i] = T[i];
	}
}

int main()
{
	int n;
	int a[100002];
	int t[100002];
	while (scanf("%d", &n) != EOF)
	{
		memset(a, 0, sizeof(a));
		memset(t, 0, sizeof(t));
		cnt = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		merge_sort(a, 0, n, t);
		printf("%lld\n", cnt);
	}
	return 0;
}
