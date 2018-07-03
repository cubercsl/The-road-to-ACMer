#include <bits/stdc++.h>
using namespace std;

#pragma optimize("-O3")

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(const bool& b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename A>
string to_string(const A& v)
{
    bool first = true;
    string res = "{";
    for (const auto& x : v)
    {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
#define debug(...) 42;
#define cerr \
    if (false) cout
#endif

template <typename T>
inline void _read(T& x)
{
    cin >> x;
}

template <typename A, typename B>
inline void _read(pair<A, B>& x)
{
    _read(x.first);
    _read(x.second);
}

template <typename T>
inline void _read(vector<T>& x)
{
    for (auto& v : x)
        _read(v);
}

void R() {}

template <typename T, typename... U>
void R(T& head, U&... tail)
{
    _read(head);
    R(tail...);
}

#define endl '\n'

template <typename T>
inline void _write(const T& x)
{
    cout << x << ' ';
}

template <typename A, typename B>
inline void _write(const pair<A, B>& x)
{
    _write(x.first);
    _write(x.second);
}

template <typename T>
inline void _write(const vector<T>& in)
{
    for (const auto& x : in)
        _write(x);
}

void W() { cout << endl; }

template <typename T, typename... U>
void W(const T& head, const U&... tail)
{
    _write(head);
    W(tail...);
}

#define my_sort_unique(c) (sort(c.begin(), c.end()), c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define X first
#define Y second

void go();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    go();
    return 0;
}

/****************************************************************************************************/

const int N = 1 << 20;
vector<PII> G[N];

int pre[N], lowlink[N], sccno[N], dfs_clock, scc_cnt;
stack<int> S;
void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (auto& e : G[u])
    {
        int& v = e.X;
        if (!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (!sccno[v])
            lowlink[u] = min(lowlink[u], pre[v]);
    }
    if (lowlink[u] == pre[u])
    {
        scc_cnt++;
        for (;;)
        {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock = 0, scc_cnt = 0;
    memset(sccno, 0, sizeof(sccno)), memset(pre, 0, sizeof(sccno));
    for (int i = 0; i < n; i++)
        if (!pre[i]) dfs(i);
}

ll sum[N];

ll f(int x)
{
    int l = 0, r = x;
    ll t;
    while (l <= r)
    {
        ll m = l + r >> 1;
        if (x - m * (m + 1) / 2 >= 0)
            t = m, l = m + 1;
        else
            r = m - 1;
    }
    return x * (t + 1) - sum[t];
}

ll c[N];
vector<PII> g[N];
ll dp[N];

ll DFS(int u)
{
    if (~dp[u]) return dp[u];
    ll& ret = dp[u];
    ret = 0;
    for (auto e : g[u])
    {
        int v = e.X, w = e.Y;
        ret = max(ret, DFS(v) + w);
    }
    ret += c[u];
    return ret;
}

void go()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + i * (ll)(i + 1) / 2;
    R(n, m);
    while (m--)
    {
        static int x, y, w;
        R(x, y, w);
        --x, --y;
        G[x].push_back({y, w});
    }
    find_scc(n);
    for (int u = 0; u < n; u++)
        for (auto& e : G[u])
        {
            int v = e.X, w = e.Y;
            int &uu = sccno[u], &vv = sccno[v];
            if (uu == vv)
                c[uu] += f(w);
            else
                g[uu].push_back({vv, w});
        }
    int s;
    R(s);
    s = sccno[--s];
    W(DFS(s));
}