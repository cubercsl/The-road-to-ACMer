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

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

const int N = 1 << 19;
ll val[N << 2], tag[N << 2];
int col[N], csl[N];

void pushup(int rt)
{
    val[rt] = val[lson] | val[rson];
}

void pushdown(int rt)
{
    if (!tag[rt]) return;
    val[lson] = val[rson] = 1LL << tag[rt];
    tag[lson] = tag[rson] = tag[rt];
    tag[rt] = 0;
}

void build(int l, int r, int rt)
{
    tag[rt] = 0;
    if (l == r)
    {
        val[rt] = 1LL << col[l];
        return;
    }
    int m = l + r >> 1;
    build(Lson), build(Rson);
    pushup(rt);
}

void update(int L, int R, int x, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        val[rt] = 1LL << x;
        tag[rt] = x;
        return;
    }
    pushdown(rt);
    int m = l + r >> 1;
    if (L <= m) update(L, R, x, Lson);
    if (m < R) update(L, R, x, Rson);
    pushup(rt);
}

ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return val[rt];
    pushdown(rt);
    int m = l + r >> 1;
    ll ans = 0;
    if (L <= m) ans |= query(L, R, Lson);
    if (m < R) ans |= query(L, R, Rson);
    return ans;
}

VI G[N];
int in[N], out[N], dfn;

void dfs(int u, int fa)
{
    in[u] = ++dfn;
    col[dfn] = csl[u];
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u);
    }
    out[u] = dfn;
}

void go()
{
    int n, m;
    R(n, m);
    for (int i = 1; i <= n; i++) cin >> csl[i];
    for (int i = 1; i < n; i++)
    {
        static int u, v;
        R(u, v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    build(1, n, 1);
    while (m--)
    {
        static int op, u, x;
        R(op, u);
        if (op == 1)
        {
            debug(in[u], out[u]);
            R(x);
            debug(x);
            update(in[u], out[u], x, 1, n, 1);
        }
        else
        {
            ll res = query(in[u], out[u], 1, n, 1);
            W(__builtin_popcountll(res));
        }
    }
}