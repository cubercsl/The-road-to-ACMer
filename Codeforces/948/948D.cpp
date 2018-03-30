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

const int N = 3e5 + 5;
struct Trie
{
    int cnt[N << 5], ch[N << 5][2];
    int sz, rt;
    void init() { sz = 0, rt = newnode(); }
    int newnode()
    {
        clr(ch[sz], -1), cnt[sz] = 0;
        return sz++;
    }
    void insert(const int& x, const int& v)
    {
        int u = rt;
        for (int i = 30; ~i; i--)
        {
            int c = x >> i & 1;
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
            cnt[u] += v;
        }
    }
    int query(const int& x)
    {
        int u = rt, ans = 0;
        for (int i = 30; ~i; i--)
        {
            int c = x >> i & 1;
            if (cnt[ch[u][c]] == 0)
                ans |= (c ^ 1) << i, u = ch[u][c ^ 1];
            else
                ans |= c << i, u = ch[u][c];
        }
        return ans;
    }
} gao;

int a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    gao.init();
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        static int x;
        cin >> x;
        gao.insert(x, 1);
    }
    for (int i = 0; i < n; i++)
    {
        int x = gao.query(a[i]);
        cout << (x ^ a[i]) << " ";
        gao.insert(x, -1);
    }
    return 0;
}
