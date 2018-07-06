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
const ull Seed_Pool[] = {146527, 19260817};
const ull Mod_Pool[] = {1000000009, 998244353};
struct Hash
{
    ull SEED, MOD;
    vector<ull> p, h;
    Hash(int seed_index = 0, int mod_index = 0)
    {
        SEED = Seed_Pool[seed_index];
        MOD = Mod_Pool[mod_index];
    }
    Hash(const string& s, int seed_index = 0, int mod_index = 0)
    {
        SEED = Seed_Pool[seed_index];
        MOD = Mod_Pool[mod_index];
        int n = s.length();
        p.resize(n + 1), h.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) p[i] = p[i - 1] * SEED % MOD;
        for (int i = 1; i <= n; i++) h[i] = (h[i - 1] * SEED % MOD + s[i - 1]) % MOD;
    }
    ull get(int l, int r) { return (h[r] - h[l] * p[r - l] % MOD + MOD) % MOD; }
    ull substr(int l, int m) { return get(l, l + m); }
};

void go()
{
    int n;
    R(n);
    vector<string> v(n);
    VI pos(n + 1);
    R(v);
    string s;
    for (int i = 0; i < n; i++)
    {
        pos[i] = s.length();
        s += v[i];
        s.push_back(' ');
    }
    pos[n] = s.length();
    pair<Hash, Hash> h = {Hash(s, 0, 0), Hash(s, 1, 1)};
    int len = s.length() - 1;
    int ans = s.length() - 1;
    for (int i = 1; i <= n / 2; i++)
    {
        map<pair<ull, ull>, PII> dic;
        for (int j = 0; j + i <= n; j++)
        {
            pair<ull, ull> tmp = {h.first.get(pos[j], pos[j + i]), h.second.get(pos[j], pos[j + i])};
            if (dic.find(tmp) == dic.end())
                dic[tmp] = {j, 1};
            else if (j - dic[tmp].first >= i)
            {
                dic[tmp].first = j, ++dic[tmp].second;
                int& t = dic[tmp].second;
                ans = min(ans, len - t * (pos[j + i] - pos[j]) + t * (i + 1));
            }
        }
    }
    W(ans);
}