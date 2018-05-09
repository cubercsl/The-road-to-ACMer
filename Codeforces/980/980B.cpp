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

char s[4][105];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            s[j][i] = '.';
    if (k & 1)
    {
        s[1][n >> 1] = '#';
        k--;
        for (int i = 1, j = n - 2; k > 0 && i != j; i++, j--, k -= 2) s[1][i] = s[1][j] = '#';
        for (int i = 1, j = n - 2; k > 0 && i != j; i++, j--, k -= 2) s[2][i] = s[2][j] = '#';
    }
    else
    {
        k >>= 1;
        for (int i = 1; i <= k; i++) s[1][i] = s[2][i] = '#';
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++) cout << s[i][j];
        cout << endl;
    }
    return 0;
}