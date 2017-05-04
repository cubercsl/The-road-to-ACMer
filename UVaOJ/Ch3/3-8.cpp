// Repeating Decimals, ACM?ICPC World Finals 1990, UVa202

/*Sample Input
76 25
5 43
1 397
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;

	while (cin >> a >> b)
	{
		int quot[3000];
		int remain[3000];
		int repeat = 0;
		int re_start, re_end;

		memset(quot, 0, sizeof(quot));
		memset(remain, 0, sizeof(remain));
		int ans_int = a / b;
		remain[0] = a % b;
		for (int i = 0; i < 3000; i++)
		{
			quot[i] = remain[i] * 10 / b;
			remain[i + 1] = remain[i] * 10 % b;
			// cout << quot[i] << endl;
			for (int j = 0; j < i; j++)
				if (remain[i] == remain[j])
				{
					repeat = i - j;
					re_start = j;
					re_end = i;
					break;
				}
			if (repeat)
				break;
		}

		cout << a << "/" << b << " = " << ans_int << ".";
		for (int i = 0; i < re_end; i++)
		{
			if (i == 50)
			{
				cout << "...";
				break;
			}
			if (i == re_start)
				cout << "(";
			cout << quot[i];
		}
		cout << ")" << endl;

		cout << "   " << repeat << " = number of digits in repeating cycle" << endl;
		cout << endl;
	}
	return 0;
}
