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

const int N = 1 << 19;
vector<int> G[N];
int pre[N], lowlink[N], sccno[N], dfs_clock, scc_cnt;
stack<int> S;
void dfs(int u, int fa)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        if (!pre[v])
        {
            dfs(v, u);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else
            lowlink[u] = min(lowlink[u], pre[v]);
    }
    if (lowlink[u] == pre[u])
    {
        scc_cnt++;
        for (;;)
        {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}

vector<int> T[N];
int d[N];

void bfs(int s)
{
    queue<int> q;
    memset(d, -1, sizeof(d));
    d[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto& v : T[u])
            if (!~d[v])
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
    }
}

void go()
{
    int n, m;
    R(n, m);
    while (m--)
    {
        static int u, v;
        R(u, v);
        --u, --v;
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs(0, -1);
    for (int u = 0; u < n; u++)
        for (auto& v : G[u])
            if (sccno[u] != sccno[v])
                T[sccno[u]].push_back(sccno[v]);
    bfs(1);
    int s = 0;
    for (int i = 1; i <= scc_cnt; i++)
        if (d[i] > d[s]) s = i;
    bfs(s);
    int ans = 0;
    for (int i = 1; i <= scc_cnt; i++) ans = max(ans, d[i]);
    W(ans);
}