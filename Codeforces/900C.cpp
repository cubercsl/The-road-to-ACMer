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

const int N = 1 << 17;
int a[N];
int cnt[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        clr(cnt, 0);
        set<int> s;
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        s.insert(a[0]);
        cnt[a[0]]--;
        for (int i = 1; i < n; i++)
        {
            int tmp = *s.rbegin();
            if (a[i] < tmp)
            {
                s.erase(tmp);
                if (s.empty() || a[i] > *s.rbegin())
                    cnt[tmp]++;
                s.insert(tmp);
            }
            else
                cnt[a[i]]--;
            s.insert(a[i]);
        }
        /*for(int i = 1; i <= n; i++)
            cout << cnt[i] << endl;*/
        int ans = -INF, out = INF;
        for (int i = 1; i <= n; i++)
            if (cnt[i] > ans)
                out = i, ans = cnt[i];
        printf("%d\n", out);
    }
    return 0;
}