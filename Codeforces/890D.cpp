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

int L[26];
int R[26];
int fa[26];
bool vis[26];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool same(int x, int y) { return find(x) == find(y); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < 26; i++) fa[i] = i;
    clr(L, -1), clr(R, -1), clr(vis, 0);
    string buf;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        int p = buf[0] - 'a';
        vis[p] = 1;
        for (int j = 1; j < buf.length(); j++)
        {
            int c = buf[j] - 'a';
            vis[c] = 1;
            if (same(p, c) && (L[c] != p || R[p] != c))
            {
                cout << "NO" << endl;
                return 0;
            }
            if (~L[c] && L[c] != p || ~R[p] && R[p] != c)
            {
                cout << "NO" << endl;
                return 0;
            }
            fa[c] = p;
            R[p] = c;
            L[c] = p;
            p = c;
        }
    }
    vector<string> v;
    for (int i = 0; i < 26; i++)
    {
        string tmp;
        if (L[i] == -1 && ~R[i])
            for (int j = i; ~j; j = R[j])
                tmp += 'a' + j;
        if (L[i] == -1 && R[i] == -1 && vis[i])
            tmp += 'a' + i;
        if (tmp != "")
            v.pb(tmp);
    }
    sort(v.begin(), v.end());
    for (auto s : v)
        cout << s;
    cout << endl;
    return 0;
}
