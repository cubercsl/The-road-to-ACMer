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
struct Trie
{
    int ch[N][26], f[N], fa[N];
    VI pos;
    int sz, rt;
    int newnode(int u = -1)
    {
        fa[sz] = u;
        memset(ch[sz], -1, sizeof(ch[sz]));
        return sz++;
    }
    void init() { pos.resize(1), sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'a'; };
    void insert(const string& s)
    {
        int u = rt;
        for (auto& t : s)
        {
            int c = idx(t);
            if (ch[u][c] == -1) ch[u][c] = newnode(u);
            u = ch[u][c];
        }
        pos.push_back(u);
    }
    void build(int n)
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 26; c++)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int c = 0; c < 26; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
        dfs_clock = 0;
        for (int i = 1; i < sz; i++) G[f[i]].push_back(i);
        dfs(rt);
        for (int i = 1; i <= n; i++)
        {
            root[i] = root[i - 1];
            for (int j = pos[i]; j != rt; j = fa[j])
                update(in[j], 1, dfs_clock, root[i], root[i]);
        }
    }
    vector<int> G[N];
    int in[N], out[N], dfs_clock;
    void dfs(int u)
    {
        in[u] = ++dfs_clock;
        for (auto& v : G[u]) dfs(v);
        out[u] = dfs_clock;
    }
    int root[N];
    // segmemt tree
    int sum[N << 5], lson[N << 5], rson[N << 5];
    int tot = 0;
    void update(int p, int l, int r, int& x, int y)
    {
        x = ++tot, lson[x] = lson[y], rson[x] = rson[y];
        sum[x] = sum[y] + 1;
        if (l == r) return;
        int m = l + r >> 1;
        if (p <= m)
            update(p, l, m, lson[x], lson[y]);
        else
            update(p, m + 1, r, rson[x], rson[y]);
    }
    int query(int L, int R, int l, int r, int x, int y)
    {
        if (L <= l && r <= R) return sum[y] - sum[x];
        int ans = 0;
        int m = l + r >> 1;
        if (L <= m) ans += query(L, R, l, m, lson[x], lson[y]);
        if (m < R) ans += query(L, R, m + 1, r, rson[x], rson[y]);
        return ans;
    }
    int ask(int l, int r, int k) { return query(in[pos[k]], out[pos[k]], 1, dfs_clock, root[l - 1], root[r]); }
} ac;

void go()
{
    int n, q;
    R(n, q);
    string s;
    ac.init();
    for (int i = 1; i <= n; i++)
    {
        R(s);
        ac.insert(s);
    }
    ac.build(n);
    while (q--)
    {
        static int l, r, k;
        R(l, r, k);
        W(ac.ask(l, r, k));
    }
}