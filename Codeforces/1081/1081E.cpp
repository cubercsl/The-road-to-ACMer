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

clock_t T;

const int N = 1 << 18;
vector<pair<ll, ll>> G[N];
ll a[N];
int n;

bool dfs(int now, long long sum)
{
    if (clock() - T > 1.98 * CLOCKS_PER_SEC) 
    {
        cout << "No" << endl;
        exit(0);
    }
    if (now > n) return true;
    for (auto& [x, y] : G[now])
    {
        // x^2 - y^2 = a[now];
        a[now - 1] = y * y - sum;
        if (a[now - 1] <= 0) continue;
        if (dfs(now + 2, sum + a[now - 1] + a[now])) return true;
    }
    return false;
}

void go()
{
    T = clock();
    R(n);
    VL ans;
    for (int i = 1; i <= n / 2; i++) R(a[i * 2]);
    for (int i = 2; i <= n; i += 2)
    {
        for (ll j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j) continue;
            ll x = j, y = a[i] / j;
            if ((x + y) & 1) continue;
            G[i].emplace_back(y + x >> 1, y - x >> 1);
        }
    }
    for (int i = 2; i <= n; i += 2) reverse(G[i].begin(), G[i].end());
    if (dfs(2, 0))
    {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    }
    else
        cout << "No" << endl;
}