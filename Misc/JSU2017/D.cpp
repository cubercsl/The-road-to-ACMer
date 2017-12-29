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

const int maxn = 100;
struct box
{
    PII S, E;
} b[maxn];
vector<int> v;

inline int get_id(int x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int MAT[maxn][maxn];
ll pre[maxn][maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        v.clear();
        v.pb(0);
        v.pb(n);
        v.pb(m);
        int s;
        scanf("%d", &s);
        for (int i = 0; i < s; i++)
        {
            scanf("%d%d%d%d", &b[i].S.X, &b[i].S.Y, &b[i].E.X, &b[i].E.Y);
            v.pb(b[i].S.X);
            v.pb(b[i].S.Y);
            v.pb(b[i].E.X);
            v.pb(b[i].E.Y);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < s; i++)
        {
            int x1 = b[i].S.X = get_id(b[i].S.X);
            int y1 = b[i].S.Y = get_id(b[i].S.Y);
            int x2 = b[i].E.X = get_id(b[i].E.X);
            int y2 = b[i].E.Y = get_id(b[i].E.Y);
            // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            for (int x = x1; x < x2; x++)
                for (int y = y1; y < y2; y++)
                    MAT[x][y] = -INF;
        }
        int N = get_id(n);
        int M = get_id(m);
        for (int i = 1; i < N; i++)
            for (int j = 1; j < M; j++)
            {
                if (MAT[i][j] == -INF) continue;
                MAT[i][j] = (v[i] - v[i - 1]) * (v[j] - v[j - 1]);
            }

        /*for (int i = 1; i < N; i++)
            for (int j = 1; j < M; j++)
                printf("%d%c", MAT[i][j], j == M - 1 ? '\n' : ' ');
 */

        int tmp;
        for (int i = 1; i < N; i++)
            for (int j = 1; j < M; j++)
            {
                tmp = MAT[i][j];
                pre[i][j] = pre[i][j - 1] + tmp;
            }
        ll ans = -1e18;
        for (int i = 1; i < N; i++)
            for (int j = i; j < M; j++)
            {
                ll sum = 0;
                for (int k = 1; k < N; k++)
                {
                    sum = max(sum, 0LL);
                    sum += pre[k][j] - pre[k][i - 1];
                    ans = max(ans, sum);
                }
            }
        printf("%lld\n", ans);
    }

    return 0;
}
