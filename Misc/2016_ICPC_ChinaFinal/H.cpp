#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long Pow (long long a, long long n)
{
	long long t = 1;
	for(;n ; (a *= a) %= mod, n >>= 1)
		if(n & 1) (t *= a) %= mod;
	return t;
}

int main()
{
	int T, kase = 0;
	cin >> T;
	while(T--)
	{
		long long n, m, k;
		cin >> n >> m >> k;
		long long ans = Pow(k, m * n);
		long long tmp = Pow(k, (m - 1) * (n - 1))* (m * n);
		tmp %= mod;
		for(int i = 1; i < k; i++)
			(ans += tmp * Pow(i, m + n - 2)) %= mod;
		cout << "Case #" << ++kase << ": " << ans << endl;
	}
	return 0;
}
