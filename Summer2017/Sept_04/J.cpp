#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;

const int maxn = 50;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    int n, sum, ans;
    int a[maxn];
    cin >> t;
    while (t--)
    {
        cin >> n;
        sum = ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ans ^= a[i];
            if (a[i] > 1)sum++;
        }
        puts((ans && sum) || (!ans && !sum) ? "John" : "Brother");
    }
    return 0;
}
