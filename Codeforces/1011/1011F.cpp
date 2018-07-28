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

const int N = 1 << 20;
int id[N];
int ch[N][2], a[N], ans[N];

void go()
{
    string s;
    int n;
    R(n);
    for (int i = 1; i <= n; ++i)
    {
        R(s);
        if (s[0] == 'A')
        {
            R(ch[i][0]);
            R(ch[i][1]);
            id[i] = 1;
            continue;
        }
        if (s[0] == 'O')
        {
            R(ch[i][0]);
            R(ch[i][1]);
            id[i] = 2;
            continue;
        }
        if (s[0] == 'N')
        {
            R(ch[i][0]);
            id[i] = 3;
            continue;
        }
        if (s[0] == 'I')
        {
            R(a[i]);
            id[i] = 4;
            continue;
        }
        R(ch[i][0]);
        R(ch[i][1]);
        id[i] = 5;
    }
    function<void(int)> dfs = [&](int x) {
        if (id[x] <= 2 || id[x] == 5)
        {
            dfs(ch[x][0]);
            dfs(ch[x][1]);
            if (id[x] == 1)
                a[x] = a[ch[x][0]] & a[ch[x][1]];
            else if (id[x] == 2)
                a[x] = a[ch[x][0]] | a[ch[x][1]];
            else
                a[x] = a[ch[x][0]] ^ a[ch[x][1]];
        }
        else if (id[x] == 3)
        {
            dfs(ch[x][0]);
            a[x] = !a[ch[x][0]];
        }
    };
    dfs(1);
    function<void(int, int)> gao = [&](int x, int ss) {
        if (id[x] == 1)
        {
            if (a[ch[x][0]] > a[ch[x][1]])
                swap(ch[x][0], ch[x][1]);
            if (!a[ch[x][1]])
            {
                gao(ch[x][0], 0);
                gao(ch[x][1], 0);
            }
            else if (!a[ch[x][0]] && a[ch[x][1]] == 1)
            {
                gao(ch[x][0], ss);
                gao(ch[x][1], 0);
            }
            else
                for (int i = 0; i < 2; i++) gao(ch[x][i], ss);
        }
        else if (id[x] == 2)
        {
            if (a[ch[x][0]] > a[ch[x][1]])
                swap(ch[x][0], ch[x][1]);
            if (!a[ch[x][1]])
            {
                gao(ch[x][0], ss);
                gao(ch[x][1], ss);
            }
            else if (!a[ch[x][0]] && a[ch[x][1]] == 1)
            {
                gao(ch[x][0], 0);
                gao(ch[x][1], ss);
            }
            else
                for (int i = 0; i < 2; i++) gao(ch[x][i], 0);
        }
        else if (id[x] == 3)
            gao(ch[x][0], ss);
        else if (id[x] == 5)
            for (int i = 0; i < 2; i++) gao(ch[x][i], ss);
        else
            ans[x] = ((ss == 1) ? a[1] : (a[1] ^ 1));
    };
    gao(1, 1);
    for (int i = 1; i <= n; ++i)
        if (id[i] == 4) cout << (ans[i] ^ 1);
}
