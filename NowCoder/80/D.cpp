#include <bits/stdc++.h>
using namespace std;

const int N = 505;
double dp1[1005][N], dp2[1005][N];

int main()
{
    double t;
    int n;
    cin >> t >> n;
    vector<int> v(n);
    for (auto& c : v) cin >> c;
    memset(dp1, 0x7f, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    dp1[0][0] = 0;
    dp2[0][0] = 1e18;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < N; j++)
            for (int k = 0; k + j < N; k++)
            {
                dp1[i + 1][j + k] = min(dp1[i + 1][j + k], max(dp1[i][j], v[i] * 1.0 / (k + 1)));
                dp2[i + 1][j + k] = max(dp2[i + 1][j + k], min(dp2[i][j], v[i] * 1.0 / (k + 1)));
            }
    }

    for (int i = 0; i < N; i++)
        if (dp2[n][i] / dp1[n][i] >= t) return cout << i << endl, 0;
    return 0;
}