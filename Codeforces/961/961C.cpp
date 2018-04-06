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

const int N = 105;
char s[4][N][N];
int v[4];
int n;
int gao()
{
    int cnt = 0;
    for (int k = 0; k < 4; k++)
    {
        int id = v[k];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (s[id][i][j] - '0' != ((i ^ j ^ k) & 1)) cnt++;
    }
    return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n;
    for (int c = 0; c < 4; c++)
    {
        for (int i = 0; i < n; i++)
            scanf("%s", s[c][i]);
    }
    int ans = INF;
    for (int i = 0; i < 4; i++) v[i] = i;
    do
        ans = min(ans, gao());
    while (next_permutation(v, v + 4));
    cout << ans << endl;

    return 0;
}