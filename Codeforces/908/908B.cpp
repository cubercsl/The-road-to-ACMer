#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int N = 55;
char maze[N][N];
int n, m;

int tx[] = {1, 0, -1, 0};
int ty[] = {0, -1, 0, 1};

bool ok(string s, int sx, int sy, int ex, int ey, vector<int> v)
{
    int x = sx, y = sy;
    for (auto c : s)
    {
        int d = c - '0';
        x += tx[v[d]], y += ty[v[d]];
        if (x < 0 || y < 0 || x >= n || y >= m || maze[x][y] == '#') return false;
        if (maze[x][y] == 'E') return true;
    }
    return maze[x][y] == 'E';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n >> m;
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') sx = i, sy = j;
            if (maze[i][j] == 'E') ex = i, ey = j;
        }
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> v;
    v.pb(0), v.pb(1), v.pb(2), v.pb(3);
    do
        if (ok(s, sx, sy, ex, ey, v)) cnt++;
    while (next_permutation(v.begin(), v.end()));
    cout << cnt << endl;
    return 0;
}
