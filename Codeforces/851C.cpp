#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1005;
int a[maxn][5];
int d[maxn][5];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                cin >> a[i][j];
        if (n > 11)
        {
            cout << 0 << endl;
            continue;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            bool flag = 1;
            for (int j = 0; j < n && flag; j++)
            {
                if (i == j) continue;
                for(int k = 0; k < 5; k++)
                    d[j][k] = a[j][k] - a[i][k];
                for(int k = 0; k < j; k++)
                {
                    double sum = 0;
                    for(int l = 0; l < 5; l++)
                        sum += d[j][l] * d[k][l];
                    // cout << sum << endl;
                    if(sum > 0)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag) ans.pb(i + 1);
        }
        cout << ans.size() << endl;
        for (auto& tmp : ans)
            cout << tmp << endl;
    }
    return 0;
}