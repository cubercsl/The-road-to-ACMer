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
const int N = 1 << 18;
namespace Hash
{
ull p[N];
const static ull mod = 1e9 + 7;
void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++) p[i] = p[i - 1] * mod;
}
vector<ull> make(const string& s)
{
    int n = s.length();
    vector<ull> v(n + 1);
    for (int i = 1; i <= n; i++) v[i] = v[i - 1] * mod + s[i - 1];
    return v;
}
ull get(int l, int r, const vector<ull>& h) { return h[r] - h[l] * p[r - l]; }
};

bool check(int k, const vector<vector<ull> >& s, const vector<ull>& t)
{
    int p = 0, id = 0;
    int n = t.size() - 1, cnt = s.size();
    unordered_set<ull> m;
    for (int i = 0; i + k < s[id].size(); i++) m.insert(Hash::get(i, i + k, s[id]));
    while (p + k - 1 < n)
    {
        ull cur = Hash::get(p, p + k, t);
        if (m.find(cur) == m.end())
            p++;
        else
        {
            id++;
            if (id == cnt) return true;
            m.clear();
            for (int i = 0; i + k < s[id].size(); i++) m.insert(Hash::get(i, i + k, s[id]));
            p += k;
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    Hash::init();
    string T;
    cin >> T;
    vector<ull> t = Hash::make(T);
    int n;
    cin >> n;
    int l = 1, r = T.length(), ans = -1;
    vector<string> S(n);
    vector<vector<ull> > s(n);
    for (auto& ss : S) cin >> ss, r = min(r, (int)ss.length());
    for (int i = 0; i < n; i++) s[i] = Hash::make(S[i]);
    while (l <= r)
    {
        int m = l + r >> 1;
        if (check(m, s, t))
            l = m + 1, ans = m;
        else
            r = m - 1;
    }
    cout << ans << endl;
    return 0;
}