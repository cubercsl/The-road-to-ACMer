#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int V, N;
		long long dp[10002];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		cin >> V >> N;
		while (V--)
		{
			int v;
			cin >> v;
			for (int i = v; i <= N; i++)
				dp[i] += dp[i - v];
		}
		cout << dp[N] << endl;
	}
	return 0;
}
