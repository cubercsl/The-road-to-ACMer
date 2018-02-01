#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 30;
char ans[maxn];
int G[maxn][maxn];
int deg[maxn];

void init()
{
    clr(G, 0);
    clr(deg, 0);
    clr(ans, 0);
}

void add_edge(int u, int v)
{
    if (G[u][v]) return;
    G[u][v] = 1;
    deg[v]++;
}

bool toposort(int n)
{
    int tot = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (deg[i] == 0) q.push(i);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        ans[tot++] = v + 'a';
        for (int i = 0; i < n; i++)
            if (G[v][i] == 1)
                if (--deg[i] == 0)
                    q.push(i);
    }
    if (tot < 26) return false;
    ans[26] = '\0';
    return true;
}

int main()
{
    fastin
    int n;
    while (cin >> n)
    {
        init();
        bool flag = true;
        string s[105];
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 1; i < n; i++)
        {
            int tmp = min(s[i - 1].length(), s[i].length());
            bool ok = false;
            for (int j = 0; j < tmp && (!ok); j++)
                if (s[i - 1][j] != s[i][j])
                {
                    add_edge(s[i - 1][j] - 'a', s[i][j] - 'a');
                    ok = true;
                }
            if ((!ok) && s[i - 1].length() > s[i].length())
            {
                flag = false;
                break;
            }
        }
        if (flag && toposort(26))
            cout << ans;
        else cout << "Impossible";
        cout << endl;

    }
    return 0;
}
