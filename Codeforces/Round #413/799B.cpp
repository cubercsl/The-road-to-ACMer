#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

struct cloth
{
	int p, a, b;
};

bool cmp(cloth a, cloth b)
{
	return a.p < b.p;
}

int n, m;
struct cloth t[200000];
int c[200000];
bool visit[200000];
int color[4];
int dp[4];
int price;
int main()
{
	while (cin >> n)
	{
		memset(visit, 0, sizeof(visit));
		memset(color, 0, sizeof(color));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
			cin >> t[i].p;
		for (int i = 0; i < n; i++)
		{
			cin >> t[i].a;
			dp[t[i].a]++;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> t[i].b;
			dp[t[i].b]++;
		}
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> c[i];
		sort(t, t + n, cmp);
		for (int i = 0; i < m; i++)
		{

			if (i)
				cout << " ";
			if (dp[c[i]] == 0)
				cout << "-1";
			else
			{
				for (int j = color[c[i]]; j < n; j++)
					if (visit[j] == 0 && (c[i] == t[j].a || c[i] == t[j].b))
					{
						price = t[j].p;
						visit[j] = 1;
						color[c[i]] = j + 1;
						dp[t[j].a]--;
						dp[t[j].b]--;
						break;
					}

				cout << price;
			}
		}
		cout << endl;
	}
	return 0;
}
