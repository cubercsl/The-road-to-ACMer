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

const int maxn = 1 << 20;
bool vis[maxn];
int tot, prime[maxn];
void CalPhi(int n)
{
    tot = 0;
    for (int i = 2; i < n; i++)
    {
        if (!vis[i])
            prime[tot++] = i;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

ll fact[100][2];
int getFactors(ll x)
{
    int cnt = 0;
    for (int i = 0; prime[i] <= x / prime[i]; i++)
    {
        fact[cnt][1] = 0;
        if (x % prime[i] == 0)
        {
            fact[cnt][0] = prime[i];
            while (x % prime[i] == 0) fact[cnt][1]++, x /= prime[i];
            cnt++;
        }
    }
    if (x != 1) fact[cnt][0] = x, fact[cnt++][1] = 1;
    return cnt;
}

bool ok(ll x, const vector<pair<int, int>>& v)
{
    for(auto& t : v)
        if((t.first % x) && (t.second % x)) return false; 
    return true;
}

void go()
{
    CalPhi(1000000);
    int n;
    R(n);
    vector<pair<int, int>> v(n);
    R(v);
    int cnt;
    cnt = getFactors(v[0].first);
    for (int i = 0; i < cnt; i++)
    {
        if (ok(fact[i][0], v))
        {
            W(fact[i][0]);
            return;
        }
    }
    cnt = getFactors(v[0].second);
    for (int i = 0; i < cnt; i++)
    {
        if (ok(fact[i][0], v))
        {
            W(fact[i][0]);
            return;
        }
    }
    W(-1);
}
