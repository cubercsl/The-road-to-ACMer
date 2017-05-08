#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a[1002], b[1002];
	while (cin >> n)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		bool flag = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i];
			if (a[i] != b[i])
				flag = 1;
		}
		if (flag)
			cout << "rated" << endl;
		else
		{
			for (int i = 1; i < n; i++)
				if (a[i] > a[i - 1] || b[i] > b[i - 1])
				{
					flag = 1;
					break;
				}
			if (flag)
				cout << "unrated" << endl;
			else
				cout << "maybe" << endl;
		}
	}
	return 0;
}
