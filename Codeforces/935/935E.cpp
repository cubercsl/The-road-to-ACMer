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

const int N = 1 << 14;
const int M = 1 << 7;
vector<int> v[N];
int val[N];
int dp[2][N][M];

void dfs(int u, bool d)
{
    if (val[u])
    {
        dp[0][u][0] = dp[1][u][0] = val[u];
        return;
    }
    int lson = v[u][0], rson = v[u][1];
    dfs(lson, d), dfs(rson, d);
    for (int i = 0; i < M; i++)
        for (int j = 0; i + j + 1 < M; j++)
        {
            dp[0][u][i + j + d] = max(dp[0][u][i + j + d], dp[0][lson][i] + dp[0][rson][j]);
            dp[0][u][i + j + (d ^ 1)] = max(dp[0][u][i + j + (d ^ 1)], dp[0][lson][i] - dp[1][rson][j]);
            dp[1][u][i + j + d] = min(dp[1][u][i + j + d], dp[1][lson][i] + dp[1][rson][j]);
            dp[1][u][i + j + (d ^ 1)] = min(dp[1][u][i + j + (d ^ 1)], dp[1][lson][i] - dp[0][rson][j]);
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s;
    int p, m;
    cin >> s >> p >> m;
    stack<int> st;
    int x = 0;
    for (auto& ch : s)
    {
        if (ch == '(') st.push(++x);
        if (ch == ')')
        {
            int t = st.top();
            st.pop();
            if (!st.empty()) v[st.top()].push_back(t);
        }
        if (isdigit(ch))
        {
            if (st.empty()) return cout << ch - '0', 0;
            v[st.top()].push_back(++x);
            val[x] = ch - '0';
        }
    }
    memset(dp[0], 0xc0, sizeof(dp[0]));
    memset(dp[1], 0x3f, sizeof(dp[1]));
    dfs(1, p < m);
    cout << dp[0][1][min(p, m)];
    return 0;
}