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

struct Node
{
    int l, r;
    int id;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<Node> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].l >> v[i].r;
        v[i].id = i + 1;
    }
    sort(v.begin(), v.end(), [](const Node& a, const Node& b) {
        return a.l < b.l || a.l == b.l && a.r > b.r;
    });
    int L = v[0].l, R = v[0].r, id = v[0].id;
    for (int i = 1; i < n; i++)
    {
        if (v[i].r <= R) return cout << v[i].id << " " << id << endl, 0;
        if (v[i].r > R) R = v[i].r, id = v[i].id;
    }
    cout << -1 << " " << -1 << endl;

    return 0;
}