#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[102], v[102];
int b[100000];
int dp[102];

int main()
{
    while (cin >> n >> m)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            cin >> v[i] >> c[i];
        int id = 0;
        for (int i = 0; i < n; i++)
        {
            int k = 1;
            while (c[i] > k)
            {
                b[id++] = k * v[i];
                c[i] -= k, k <<= 1;
            }
            b[id++] = c[i] * v[i];
        }
        for (int i = 0; i < id; i++)
            for (int j = m; j >= b[i]; j--)
                dp[j] = max(dp[j], dp[j - b[i]] + b[i]);
        cout << dp[m] << endl;
    }
    return 0;
}
