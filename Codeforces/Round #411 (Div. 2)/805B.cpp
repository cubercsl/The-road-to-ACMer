#include <bits/stdc++.h>
using namespace std;

int main()
{
	char str[] = "aabb";
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cout << str[i % 4];
		cout << endl;
	}
	return 0;
}
