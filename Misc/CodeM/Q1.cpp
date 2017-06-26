#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{
    int n, m;
    int a[1000], b[1000];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> b[i];
        int ans = INF;
        for (int i = 0; i < m - n + 1; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
                sum += (a[j] - b[i + j]) * (a[j] - b[i + j]);
            ans = min(sum, ans);
        }
        cout << ans << endl;
    }
    return 0;
}
