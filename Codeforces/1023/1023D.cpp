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
vector<int> pos[N];
int a[N];

template <class T>
struct RMQ
{
    vector<vector<T> > rmq;
    // vector<T> rmq[20]; or T[100002][20] if need speed
    //T kInf = numeric_limits<T>::max(); // if need return a value when the interval fake
    void init(const vector<T>& a)
    { // 0 base
        int n = (int)a.size(), base = 1, depth = 1;
        while (base < n)
            base <<= 1, ++depth;
        rmq.assign((unsigned)depth, a);
        for (int i = 0; i < depth - 1; ++i)
            for (int j = 0; j < n; ++j)
            {
                rmq[i + 1][j] = min(rmq[i][j],
                                    rmq[i][min(n - 1, j + (1 << i))]);
            }
    }
    T q(int l, int r)
    { // [l, r)
        if (l > r) return 0x3f3f3f3f;
        int dep = 31 - __builtin_clz(r - l); // log(b - a)
        return min(rmq[dep][l], rmq[dep][r - (1 << dep)]);
    }
};

void go()
{
    int n, q;
    R(n, q);
    a[0] = 1;
    for (int i = 1; i <= n; i++) R(a[i]);
    int now = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            a[i] = a[i - 1];
            now = i;
        }
        pos[a[i]].push_back(i);
    }
    RMQ<int> rmq;
    rmq.init(VI(a, a + n + 1));
    for (int i = 1; i <= q; i++)
    {
        for (int j = 0; j < (int)(pos[i].size()) - 1; j++)
        {
            int x = rmq.q(pos[i][j] + 1, pos[i][j + 1]);
            if (x < i)
                return (void)W("NO");
        }
    }
    bool ok = false;
    for (int i = 1; i <= n; i++)
        if (a[i] == q) ok = true;
    if (!ok)
    {
        if (~now)
            a[now] = q;
        else
            return (void)W("NO");
    }
    W("YES");
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}