#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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
const double eps = 1e-6;

const int maxn = 35;
bool a[maxn];
int s[maxn];
int n, top, tot;

bool judge(int t)
{
    tot = 0;
    int i = t / 20 + 2;
    while (i <= top)
    {
        while (i <= top && !a[i])
            i++;
        if (4 * (i - 1) + 10 * tot > t)
            return false;
        int j = (t - 10 * tot + 20 * i + 4) / 24;
        i = (t - 10 * tot + 16 * j + 4) / 20 + 1;
        s[tot++] = j;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n, n)
    {
        clr(a, 0);
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            a[tmp] = true;
            top = tmp;
        }
        int L = 0, R = (top - 1) * 14;
        int ans;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (judge(mid))
                ans = mid, R = mid - 1;
            else
                L = mid + 1;
        }
        judge(ans);
        cout << ans << endl;
        cout << tot;
        for (int i = 0; i < tot; i++)
            cout << " " << s[i];
        cout << endl;
    }
    return 0;
}
