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

void go()
{
    int n, m;
    R(n, m);
    vector<VL> s(n + 2, VL(m + 2));
    vector<vector<VL> > dp(4, vector<VL>(n + 2, VL(m + 2)));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> s[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + s[i][j];
    for (int i = n; i; i--)
        for (int j = m; j; j--)
            dp[1][i][j] = max(dp[1][i + 1][j], dp[1][i][j + 1]) + s[i][j];
    for (int i = n; i; i--)
        for (int j = 1; j <= m; j++)
            dp[2][i][j] = max(dp[2][i + 1][j], dp[2][i][j - 1]) + s[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = m; j; j--)
            dp[3][i][j] = max(dp[3][i - 1][j], dp[3][i][j + 1]) + s[i][j];
    ll ans = 0;
    debug(dp[0]);
    debug(dp[1]);
    debug(dp[2]);
    debug(dp[3]);
    for (int i = 2; i < n; i++)
        for (int j = 2; j < m; j++)
        {
            ll t1 = dp[0][i - 1][j] + dp[1][i + 1][j] + dp[2][i][j - 1] + dp[3][i][j + 1];
            debug(dp[0][i - 1][j], dp[1][i + 1][j], dp[2][i][j - 1], dp[3][i][j + 1]);
            ll t2 = dp[0][i][j - 1] + dp[1][i][j + 1] + dp[2][i + 1][j] + dp[3][i - 1][j];
            debug(dp[0][i][j - 1], dp[1][i][j + 1], dp[2][i + 1][j], dp[3][i - 1][j]);
            debug(t1, t2);
            ans = max({ans, t1, t2});
        }
    W(ans);
}