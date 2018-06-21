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
VI tx = {-1, 0, 1, 0}, ty = {0, 1, 0, -1};

int dis[1000][1000][4], dp[1000][1000][4];
char maze[1005][1005];
void go()
{
    int kase = 0;
    int n, m, mod;
    map<char, int> dic = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
    while (cin >> n >> m >> mod, mod)
    {
        auto in = [&](const int& x, const int& y) { return x >= 0 && x < n && y >= 0 && y < m; };
        for (int i = 0; i < n; i++) cin >> maze[i];
        PII s, e;
        cin >> s.X >> s.Y >> e.X >> e.Y;
        char c;
        cin >> c;
        int d = dic[c];
        memset(dis, -1, sizeof(dis));
        memset(dp, 0, sizeof(dp));
        dis[s.X][s.Y][d] = 0;
        dp[s.X][s.Y][d] = 1;
        queue<pair<PII, int>> q;
        q.push({s, d});
        while (!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            int &x = tmp.X.X, &y = tmp.X.Y, &d = tmp.Y;
            for (int i = 0; i < 3; i++)
            {
                int nx = x, ny = y, nd = d;
                if (i == 0) nx = x + tx[d], ny = y + ty[d];
                if (i == 1) nd = (d + 1) % 4;
                if (i == 2) nd = (d - 1 + 4) % 4;
                if (in(nx, ny) && maze[nx][ny] == '.')
                {
                    if (!~dis[nx][ny][nd])
                    {
                        dis[nx][ny][nd] = dis[x][y][d] + 1;
                        dp[nx][ny][nd] = dp[x][y][d];
                        q.push({{nx, ny}, nd});
                    }
                    else if (dis[nx][ny][nd] == dis[x][y][d] + 1)
                        (dp[nx][ny][nd] += dp[x][y][d]) %= mod;
                }
            }
        }
        int ans = 0, tmp = INF;
        for (int i = 0; i < 4; i++)
            if (~dis[e.X][e.Y][i] && dis[e.X][e.Y][i] < tmp)
                tmp = dis[e.X][e.Y][i];
        for (int i = 0; i < 4; i++)
            if (dis[e.X][e.Y][i] == tmp)
                (ans += dp[e.X][e.Y][i]) %= mod;
        if (tmp == INF) ans = -1;
        cout << "Case " << ++kase << ": " << mod << " " << ans << endl;
    }
}