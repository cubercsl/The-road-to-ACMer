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

const int INF = 0x3f3f3f3f;

void go()
{
    int n, m, t, tp, tu, td;
    R(n, m, t, tp, tu, td);
    vector<VI> G(n, VI(m));
    R(G);
    vector<vector<VI>> dp(4, vector<VI>(n, VI(m)));
    auto f = [&](int x, int y) {
        if (x > y) return tu;
        if (x < y) return td;
        return tp;
    };
    for (int i = 0; i < n; i++)
    {
        dp[0][i][0] = 0;
        for (int j = 1; j < m; j++)
            dp[0][i][j] = dp[0][i][j - 1] + f(G[i][j], G[i][j - 1]);
        dp[1][0][m - 1] = 0;
        for (int j = m - 2; ~j; j--)
            dp[1][i][j] = dp[1][i][j + 1] + f(G[i][j], G[i][j + 1]);
    }
    for (int j = 0; j < m; j++)
    {
        dp[2][0][j] = 0;
        for (int i = 1; i < n; i++)
            dp[2][i][j] = dp[2][i - 1][j] + f(G[i][j], G[i - 1][j]);
        dp[3][n - 1][j] = 0;
        for (int i = n - 2; ~i; i--)
            dp[3][i][j] = dp[3][i + 1][j] + f(G[i][j], G[i + 1][j]);
    }
    int ans = INF;
    pair<PII, PII> ret;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = i + 2; k < n; k++)
                for (int l = j + 2; l < m; l++)
                {
                    int t0 = dp[0][i][l] - dp[0][i][j];
                    int t1 = dp[1][k][j] - dp[1][k][l];
                    int t2 = dp[2][k][l] - dp[2][i][l];
                    int t3 = dp[3][i][j] - dp[3][k][j];
                    if (abs(t0 + t1 + t2 + t3 - t) < ans)
                    {
                        ans = abs(t0 + t1 + t2 + t3 - t);
                        ret = {{i + 1, j + 1}, {k + 1, l + 1}};
                    }
                }
    debug(ans);
    W(ret);
}