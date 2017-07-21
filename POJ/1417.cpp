// True Liars, POJ1417

/*Sample Input
2 1 1
1 2 no
2 1 no
3 2 1
1 1 yes
2 2 yes
3 3 yes
2 2 1
1 2 yes
2 3 no
5 4 3
1 2 yes
1 3 no
4 5 yes
5 6 yes
6 7 no
0 0 0
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
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

const int maxn = 605;
int par[maxn], val[maxn]; // 与父结点的关系:0为同类,1为异类
int dp[maxn][maxn];       // 前i个集合选出j个好人的方案数量
int pre[maxn][maxn];      // 记录状态转移
vector <int> re[maxn][2]; // 每个小组的两类人
vector <int> root;        // 记录所有的根结点
vector <int> ans;         // 记录答案

void init (int n)
{
    root.clear();
    for (int i = 0; i < maxn; i++)
    {
        re[i][0].clear();
        re[i][1].clear();
    }
    ans.clear();
    clr(pre, 0);
    clr(dp, 0);
    for (int i = 1; i <= n; i++)
        par[i] = i, val[i] = 0;
}

int find(int x)
{
    if (par[x] == x) return x;
    int tmp = find(par[x]);
    val[x] ^= val[par[x]];
    return par[x] = tmp;
}

void unite(int x, int y, int d)
{
    int t1 = find(x);
    int t2 = find(y);
    if (t1 == t2) return;
    par[t2] = t1;
    val[t2] = val[x] ^ val[y] ^ d;
}

void solve(int p)
{
    int x = root.size();
    int y = p;
    while (x > 0)
    {
        if (pre[x][y])
        {
            for (int i = 0; i < re[x - 1][1].size(); i++)
                ans.pb(re[x - 1][1][i]);
            y  -= re[--x][1].size();
        }
        else
        {
            for (int i = 0; i < re[x - 1][0].size(); i++)
                ans.pb(re[x - 1][0][i]);
            y  -= re[--x][0].size();
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    cout << "end" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, p, q;
    while (cin >> n >> p >> q, n + p + q)
    {
        init(p + q);
        while (n--)
        {
            int x, y, d;
            char a[5];
            cin >> x >> y >> a;
            d = a[0] == 'y' ? 0 : 1;
            unite(x, y, d);
        }
        for (int i = 1; i <= p + q; i++)
            if (find(i) == i)
                root.pb(i);
        for (int i = 0; i < root.size(); i++)
            for (int j = 1; j <= p + q; j++)
                if (find(j) == root[i])
                    re[i][val[j]].pb(j);
        /*
                for (int i = 0; i < root.size(); i++)
                {
                    for (int j = 0; j < re[i][0].size(); j++)
                        cout << re[i][0][j] << " ";
                    cout << endl;
                    for (int j = 0; j < re[i][1].size(); j++)
                        cout << re[i][1][j] << " ";
                    cout << endl;
                }
        */
        dp[0][0] = 1;
        for (int i = 0; i < root.size(); i++)
        {
            for (int j = 0; j <= p; j++)
            {
                int t1 = re[i][0].size();
                int t2 = re[i][1].size();
                if (j >= t1 && dp[i][j - t1])
                {
                    dp[i + 1][j] += dp[i][j - t1];
                    pre[i + 1][j] = 0;
                }
                if (j >= t2 && dp[i][j - t2])
                {
                    dp[i + 1][j] += dp[i][j - t2];
                    pre[i + 1][j] = 1;
                }
            }
        }
        if (dp[root.size()][p] != 1)
            cout << "no" << endl;
        else
            solve(p);
    }
    return 0;
}
