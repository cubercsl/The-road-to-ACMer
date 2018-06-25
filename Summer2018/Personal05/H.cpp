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

typedef unsigned long long ull;
const int N = 1 << 18;
namespace Hash
{
ull p[N];
const static ull mod = 1e9 + 7;
void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++) p[i] = p[i - 1] * mod;
}
vector<ull> make(const string& s)
{
    int n = s.length();
    vector<ull> v(n + 1);
    for (int i = 1; i <= n; i++) v[i] = v[i - 1] * mod + s[i - 1];
    return v;
}
ull get(int l, int r, const vector<ull>& h) { return h[r] - h[l] * p[r - l]; }
}; // namespace Hash

void go()
{
    int m, l;
    Hash::init();
    while (cin >> m >> l)
    {
        string s;
        cin >> s;
        int n = s.length();
        vector<ull> h = Hash::make(s);
        unordered_map<ull, int> M;
        int ans = 0;
        for (int i = 0; i < l && i + m * l <= n; i++)
        {
            M.clear();
            for (int j = 0; j < m; j++)
            {
                ull tmp = Hash::get(i + j * l, i + (j + 1) * l, h);
                debug(s.substr(i + j * l, l));
                M[tmp]++;
            }
            if (M.size() == m) ans++;
            for (int j = 0; i + j + (m + 1) * l <= n; j += l)
            {
                ull tmp = Hash::get(i + j, i + j + l, h);
                debug(s.substr(i, l));
                M[tmp]--;
                if (M[tmp] == 0) M.erase(tmp);
                tmp = Hash::get(i + j + m * l, i + j + (m + 1) * l, h);
                debug(s.substr(i + j + m * l, l));
                M[tmp]++;
                if (M.size() == m) ans++;
            }
        }
        cout << ans << endl;
    }
}