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

typedef unsigned long long ull;
const int maxn = 100001;
ull a[maxn];
map<ull, int> M;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    a[1] = 1, a[2] = 2;
    for (int i = 3; i < maxn; i++) a[i] = a[i - 2] + a[i - 1];
    for (int i = 1; i < maxn; i++) M[a[i]] = i;
    string s;
    while (cin >> s)
    {
        ull num = 0;
        for (auto t : s) (num *= 10) += t - '0';
        cout << M[num] << endl;
    }
    return 0;
}
