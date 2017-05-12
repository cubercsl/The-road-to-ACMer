#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long fastpow(long long b)
{
	long long r = 1, base = 2;
	while (b)
	{
		if (b & 1)
			r = r * base % MOD;
		base = base * base % MOD;
		b >>= 1;
	}
	return r - 1;
}

int main()
{
	char str[1000002];
	while (cin >> str)
	{
		int cnt = 0;
		int ans = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == 'a')
				cnt++;
			else if (cnt == 0)
				continue;
			else
				ans += fastpow(cnt);
			ans %= MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
