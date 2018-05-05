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
        int n, m, q;
        cin >> n >> m >> q;
        vector<string> s(n);
        vector<vector<int>> v(n, vector<int>(m));
        for (auto& t : s) cin >> t;
        vector<PII> op(q);
        for (auto& t : op)
        {
            cin >> t.X >> t.Y;
            --t.X, --t.Y;
        }
        bool flag = 0;
        int step = 0;
        for (auto& t : op)
        {
            ++step;
            int x = t.X, y = t.Y;
            if (s[x][y] == '*')
            {
                flag = 1;
                cout << "Game over in step " << step << endl;
                break;
            }
            v[x][y] = 1;
            stack<PII> S;
            if (s[x][y] == '.') S.push({x, y});
            while (!S.empty())
            {
                PII u = S.top();
                S.pop();
                int x = u.X, y = u.Y;
                for (int i = -1; i <= 1; i++)
                    for (int j = -1; j <= 1; j++)
                    {
                        int xx = x + i, yy = y + j;
                        if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                        if (v[xx][yy]) continue;
                        v[xx][yy] = 1;
                        if (s[xx][yy] == '.') S.push({xx, yy});
                    }
            }
        }
        if (flag) continue;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j])
                {
                    if (s[i][j] == '.')
                        cout << '0';
                    else
                        cout << s[i][j];
                }
                else
                    cout << '.';
            }
            cout << endl;
        }
    }
    return 0;
}
