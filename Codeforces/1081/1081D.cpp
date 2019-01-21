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

const int N = 1 << 17;
int fa[N];
vector<pair<int, int>> G[N];
int sz[N], dp[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v) return;
    sz[u] += sz[v];
    fa[v] = u;
}

void go()
{
    int n, m, k;
    R(n, m, k);
    for (int i = 1; i <= n; i++) fa[i] = i;
    VI a(k);
    R(a);
    for (auto& t : a) sz[t] = 1;
    vector<tuple<int, int, int>> edges;
    for (int i = 0, u, v, w; i < m; i++)
    {
        R(u, v, w);
        edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    int cnt = 0;
    for (auto& [w, u, v] : edges)
    {
        if (find(u) == find(v)) continue;
        ans = max(ans, w);
        unite(u, v);
        if (sz[find(u)] == k)
        {
            for (int i = 0; i < k; i++) cout << ans << " ";
            return;
        }
        if (++cnt == n - 1) break;
    }
    for (int i = 0; i < k; i++) cout << ans << " ";
}