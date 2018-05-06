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

const int N = 1 << 10;
char s[N][N];
const char p[][5] = {"cat", "girl"};
const int tx[] = {-1, 0, 1, 0};
const int ty[] = {0, -1, 0, 1};

int n, m;
void dfs(int x, int y, int d, int cur, int& cnt)
{
    if (s[x][y] != p[d][cur]) return;
    if (cur == 2 + d)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + tx[i], ny = y + ty[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        dfs(nx, ny, d, cur + 1, cnt);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int cnt[2] = {0, 0};
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < 2; k++)
                    dfs(i, j, k, 0, cnt[k]);
        cout << cnt[1] << " " << cnt[0] << endl;
    }
    return 0;
}