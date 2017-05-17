#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		int n;
		int cnt = 0;
		cin >> n;
		while (n--)
		{
			int num;
			cin >> num;
			if (num > b && num < c)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
