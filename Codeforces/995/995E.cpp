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

ll Pow(ll a, ll n, ll p)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}

queue<ll> q[2];
map<ll, pair<ll, int>> pre[2];
map<ll, int> vis[2];

inline void add(const ll& t, const ll& a, const int& d, const int& tag)
{
    if (vis[d][a]) return;
    q[d].push(a);
    vis[d][a] = 1;
    pre[d][a] = {t, tag};
}

VI gao(const ll& u, const ll& v, const ll& t)
{
    VI ans;
    for (ll x = t; x != u; x = pre[0][x].first) ans.push_back(pre[0][x].second);
    reverse(ans.begin(), ans.end());
    for (ll x = t; x != v; x = pre[1][x].first) ans.push_back(pre[1][x].second);
    return ans;
}

VI bfs(const ll& u, const ll& v, const ll& p)
{
    q[0].push(u);
    q[1].push(v);
    vis[0][u] = 1;
    vis[1][v] = 1;
    pre[0][u] = {u, 0};
    pre[1][v] = {v, 0};
    while (!q[0].empty() || !q[1].empty())
    {
        int n = q[0].size();
        while (n--)
        {
            ll t = q[0].front();
            q[0].pop();
            if (vis[1].find(t) != vis[1].end()) return gao(u, v, t);
            add(t, (t + 1) % p, 0, 1);
            add(t, (t - 1 + p) % p, 0, 2);
            add(t, Pow(t, p - 2, p), 0, 3);
        }
        int m = q[1].size();
        while (m--)
        {
            ll t = q[1].front();
            q[1].pop();
            if (vis[0].find(t) != vis[0].end()) return gao(u, v, t);
            add(t, (t + 1) % p, 1, 2);
            add(t, (t - 1 + p) % p, 1, 1);
            add(t, Pow(t, p - 2, p), 1, 3);
        }
    }
    assert(false);
}

void go()
{
    ll u, v, p;
    R(u, v, p);
    VI ans = bfs(u, v, p);
    W(ans.size());
    W(ans);
}