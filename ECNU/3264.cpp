#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a;
	bool b;
	stack<int> stk;
	while (cin >> n)
	{
		while (!stk.empty())
			stk.pop();
		int cnt = n;
		while (n--)
		{
			cin >> a >> b;
			if (b)
				stk.push(a);
			else if (!stk.empty())
			{
				if (a > stk.top())
					do
					{
						stk.pop();
						cnt--;
					} while (!stk.empty() && a > stk.top());
				if (!stk.empty())
					cnt--;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
