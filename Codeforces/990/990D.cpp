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

const int N = 1 << 10;
int s[N][N];

void gao(int x, int y, int n)
{
    int c = n - x;
    clr(s, 0);
    for (int i = 0; i < c; i++) s[i][i + 1] = s[i + 1][i] = 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, a, b;
    cin >> n >> a >> b;
    if (a > 1 && b > 1) return cout << "NO" << endl, 0;
    if (n == 2 || n == 3)
        if (a == 1 && b == 1) return cout << "NO", 0;
    if (a > b)
        gao(a, b, n);
    else
    {
        gao(b, a, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i ^ j) s[i][j] ^= 1;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << s[i][j];
        cout << endl;
    }
    return 0;
}