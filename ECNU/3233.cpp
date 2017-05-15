#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int num = 0;
		while (n > 0)
		{
			num += n / 5;
			n /= 5;
		}
		cout << num << endl;
	}
	return 0;
}
