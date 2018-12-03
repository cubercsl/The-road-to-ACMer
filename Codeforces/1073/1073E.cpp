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
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    go();
    return 0;
}

/****************************************************************************************************/

const int mod = 119 << 23 | 1;

int a[20];
pair<ll, ll> dp[20][1 << 10];
bool vis[20][1 << 10];

ll p[20], k;
pair<ll, ll> dfs(int pos, int state, bool limit, bool lead)
{
    if (pos == -1) return __builtin_popcount(state) <= k ? make_pair(1, 0) : make_pair(0, 0);
    if (!limit && !lead && vis[pos][state]) return dp[pos][state];
    int up = limit ? a[pos] : 9;
    pair<ll, ll> ans = {0, 0};
    for (int i = 0; i <= up; i++)
    {
        int n_s = state;
        if (lead && i == 0)
            n_s = 0;
        else
            n_s = state | (1 << i);
        auto tmp = dfs(pos - 1, n_s, limit && i == a[pos], lead && i == 0);
        ll pre = 1LL * i * p[pos] % mod;
        (ans.first += tmp.first) %= mod;
        (ans.second += tmp.second + pre * tmp.first) %= mod;
    }
    if (!limit && !lead) dp[pos][state] = ans, vis[pos][state] = true;
    return ans;
}

ll solve(ll x)
{
    int pos = 0;
    do
    {
        a[pos++] = x % 10;

    } while (x /= 10);
    return dfs(pos - 1, 0, true, true).second;
}

void go()
{
    p[0] = 1;
    for (int i = 1; i < 20; i++) p[i] = p[i - 1] * 10 % mod;
    ll l, r;
    R(l, r, k);
    W((solve(r) - solve(l - 1) + mod) % mod);
}