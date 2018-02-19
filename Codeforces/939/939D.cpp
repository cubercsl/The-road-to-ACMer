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

int fa[30];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) fa[y] = x;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < 26; i++) fa[i] = i;
    for (int i = 0; i < n; i++) unite(s[i] - 'a', t[i] - 'a');
    vector<PII> ans;
    for (int i = 0; i < 26; i++)
    {
        if (find(i) == i) continue;
        ans.pb(mp(i, find(i)));
    }
    cout << ans.size() << endl;
    for (auto& t : ans) printf("%c %c\n", t.X + 'a', t.Y + 'a');
    return 0;
}