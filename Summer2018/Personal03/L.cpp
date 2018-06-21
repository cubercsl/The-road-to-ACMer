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

const int INF = 0x3f3f3f3f;

VI tx = {-1, 0, 1, 0};
VI ty = {0, -1, 0, 1};

struct Tunnel
{
    int x1, y1, x2, y2;
    inline void read()
    {
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --x2, --y1, --y2;
    }
};

void go()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<string> s(n);
        for (auto& t : s) cin >> t;
        auto bfs = [&](const Tunnel& a, const Tunnel& b) {
            vector<VI> d(n, VI(n, -1));
            // a2->b1
            queue<PII> q;
            d[a.x2][a.y2] = 0;
            q.push({a.x2, a.y2});
            while (!q.empty())
            {
                PII tmp = q.front();
                q.pop();
                int &x = tmp.X, &y = tmp.Y;
                if (x == b.x1 && y == b.y1) return d[x][y];
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + tx[i], ny = y + ty[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n || ~d[nx][ny] || s[nx][ny] == '#') continue;
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
            return -1;
        };
        vector<Tunnel> T(m);
        for (auto& t : T) t.read();
        vector<VI> G((m), VI(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                G[i][j] = i == j ? 0 : bfs(T[i], T[j]);
        debug(G);
        vector<VI> dp(1 << m, VI(m, INF));
        for (int i = 0; i < m; i++) dp[1 << i][i] = 0;
        for (int i = 0; i < (1 << m); i++)
            for (int j = 0; j < m; j++)
                if (dp[i][j] != INF)
                    for (int k = 0; k < m; k++)
                        if (!(i & (1 << k)) && ~G[j][k])
                            dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + G[j][k]);
        VI& all = dp[(1 << m) - 1];
        int ans = *min_element(all.begin(), all.end());
        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}