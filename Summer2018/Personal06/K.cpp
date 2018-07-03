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

struct Edge
{
    int from, to;
    ll dist;
};

struct HeapNode
{
    ll d;
    int u;
    bool operator<(const HeapNode& rhs) const
    {
        return d > rhs.d;
    }
};

vector<Edge> edges;
vector<int> G[N];

bool vis[N];
ll d[N];

void add_edge(int from, int to, ll dist)
{
    edges.push_back({from, to, dist});
    G[from].push_back(edges.size() - 1);
}

void Dijkstra(int s, int n)
{
    priority_queue<HeapNode> q;
    for (int i = 0; i <= n; i++) d[i] = 1e18;
    d[s] = 0;
    memset(vis, 0, sizeof(vis));
    q.push({0, s});
    while (!q.empty())
    {
        HeapNode x = q.top();
        q.pop();
        int u = x.u;
        if (vis[u]) continue;
        vis[u] = true;
        for (auto& id : G[u])
        {
            Edge& e = edges[id];
            if (!vis[e.to] && d[e.to] > d[u] + e.dist)
            {
                d[e.to] = d[u] + e.dist;
                q.push({d[e.to], e.to});
            }
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
        static ll w;
        R(u, v, w);
        add_edge(u, v, w * 2);
        add_edge(v, u, w * 2);
    }
    for (int i = 1; i <= n; i++)
    {
        static ll a;
        R(a);
        add_edge(0, i, a);
    }
    Dijkstra(0, n);
    for (int i = 1; i <= n; i++) cout << d[i] << " ";
}