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

#ifndef ONLINE_okDGE
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
const int N = 1 << 18;
bool ok[N];
int a[N];
void go()
{
    int n;
    R(n);
    int cnt = 0;
    VI v;
    int pos = 1, maxv = -INF;
    for (int i = 1; i <= n; ++i)
    {
        R(a[i]);
        ok[i] = 1;
        if (!a[i]) v.push_back(i);
        if (a[i] < 0) ++cnt;

        if (a[i] < 0 && a[i] > maxv)
        {
            pos = i;
            maxv = a[i];
        }
    }
    int op = 0;
    int tot = v.size() - 1;
    for (int i = 0; i < tot; ++i)
    {
        cout << 1 << " " << v[i] << " " << v[i + 1] << endl;
        ++op;
        ok[v[i]] = 0;
    }
    tot = 1;
    if (v.size() == 0) tot = 0;

    if (cnt % 2)
    {
        if (tot)
        {
            cout << 1 << " " << pos << " " << v.back() << endl;
            ++op;
            ok[pos] = 0;
            if (op < n - 1)
            {
                cout << 2 << " " << v.back() << endl;
                ok[v.back()] = 0;
            }
        }
        else
        {
            cout << 2 << " " << pos << endl;
            ok[pos] = 0;
        }
    }
    else
    {
        if (tot)
        {
            if (op < n - 1)
            {
                cout << 2 << " " << v.back() << endl;
                ok[v[v.size() - 1]] = 0;
            }
        }
    }
    v.clear();
    for (int i = 1; i <= n; i++)
        if (ok[i]) v.push_back(i);
    tot = v.size() - 1;
    for (int i = 0; i < tot; i++) cout << 1 << " " << v[i] << " " << v[i + 1] << endl;
}
