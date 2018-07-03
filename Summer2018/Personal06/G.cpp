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

const int N = 1 << 21;
VL G[N], pre[N];
int d[N];

void dfs(int rt, const int& n)
{
    if (rt > n) return;
    dfs(lson, n), dfs(rson, n);
    int pl = 0, pr = 0;
    VL &A = G[lson], &B = G[rson], &C = G[rt];
    int a = d[lson], b = d[rson];
    int sl = A.size(), sr = B.size();
    C.push_back(0);
    while (pl < sl && pr < sr)
    {
        if (A[pl] + a < B[pr] + b)
            C.push_back(A[pl++] + a);
        else
            C.push_back(B[pr++] + b);
    }
    while (pl < sl) C.push_back(A[pl++] + a);
    while (pr < sr) C.push_back(B[pr++] + b);
    pre[rt].push_back(0);
    for (int i = 1; i < C.size(); i++) pre[rt].push_back(pre[rt][i - 1] + C[i]);
}

ll calc(int a, int h, const int& n)
{
    if (h < 0 || a > n || a == 0) return 0;
    int pos = upper_bound(G[a].begin(), G[a].end(), h) - G[a].begin() - 1;
    return ~pos ? (ll)h * (pos + 1) - pre[a][pos] : 0;
}

ll solve(int a, int h, const int& n)
{
    ll ans = 0;
    ans += calc(a, h, n);
    while (a > 1 && (h -= d[a]) > 0)
    {
        ans += h;
        ans += calc(a ^ 1, h - d[a ^ 1], n);
        a >>= 1;
    }
    return ans;
}

void go()
{
    int n, m;
    R(n, m);
    for (int i = 1; i < n; i++) R(d[i + 1]);
    dfs(1, n);
    while (m--)
    {
        static int a, h;
        R(a, h);
        W(solve(a, h, n));
    }
}