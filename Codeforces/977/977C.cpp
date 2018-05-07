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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    map<int, int> M;
    for (int i = 0, t; i < n; i++)
    {
        cin >> t;
        M[t]++;
    }
    if (k == 0)
    {
        if (M[1] == 0)
            cout << 1 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    auto it1 = M.begin(), it2 = M.begin();
    ++it2;
    for (; it2 != M.end(); ++it1, ++it2) it2->second += it1->second;
    for (auto& t : M)
        if (t.second == k) return cout << t.first << endl, 0;
    cout << -1 << endl;
    return 0;
}