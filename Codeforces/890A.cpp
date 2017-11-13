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

int a[6];

bool solve()
{
    do
    {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < 3; i++)
            s1 += a[i], s2 += a[i + 3];
        if (s1 == s2) return true;
    } while (next_permutation(a, a + 6));
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    if (solve())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}