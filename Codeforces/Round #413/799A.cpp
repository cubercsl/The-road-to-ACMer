#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t, k, d;
	while (cin >> n >> t >> k >> d)
	{
		int no = ceil(1.0 * n / k) * t;
		int yes = 0;
		int cnt = 0;
		while (cnt < n)
		{
			yes += t;
			cnt += k;
			if (yes > d)
				cnt += k;
		}
		if (yes < no)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}