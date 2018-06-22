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

const int N = 1 << 18;
VI G[N];
int in[N], out[N], v[N], val[N];
int dfn;

void dfs(int u)
{
    debug(u);
    in[u] = ++dfn;
    val[dfn] = v[u];
    for (auto& v : G[u])
        dfs(v);
    out[u] = dfn;
}

int sum[N << 2], tag[N << 2];

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

inline void pushup(int rt)
{
    sum[rt] = sum[lson] + sum[rson];
}

void build(int l, int r, int rt)
{
    tag[rt] = 0;
    if (l == r)
    {
        sum[rt] = val[l];
        return;
    }
    int m = l + r >> 1;
    build(Lson), build(Rson);
    pushup(rt);
}

void pushdown(int rt, int m)
{
    if (!tag[rt]) return;
    int l = m - (m >> 1);
    int r = m >> 1;
    sum[lson] = l - sum[lson];
    sum[rson] = r - sum[rson];
    tag[lson] ^= 1;
    tag[rson] ^= 1;
    tag[rt] = 0;
}

void update(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        sum[rt] = (r - l + 1) - sum[rt];
        tag[rt] ^= 1;
        return;
    }
    pushdown(rt, r - l + 1);
    int m = l + r >> 1;
    if (L <= m) update(L, R, Lson);
    if (m < R) update(L, R, Rson);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return sum[rt];
    pushdown(rt, r - l + 1);
    int m = l + r >> 1;
    int sum = 0;
    if (L <= m) sum += query(L, R, Lson);
    if (m < R) sum += query(L, R, Rson);
    return sum;
}

void go()
{
    int n;
    cin >> n;
    for (int i = 2, p; i <= n; i++)
    {
        cin >> p;
        G[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> v[i];
    dfs(1);
    build(1, n, 1);

    int q;
    cin >> q;
    while (q--)
    {
        static string op;
        static int u;
        cin >> op >> u;
        if (op == "get")
            W(query(in[u], out[u], 1, n, 1));
        else
            update(in[u], out[u], 1, n, 1);
    }
}