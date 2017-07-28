#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
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

const int maxn = 1e5 + 5;
int n, m;
int l, r;
int a[maxn];
int ans;

bool ok(int x)
{
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] <= x)
            sum += a[i];
        else if (a[i] > x)
            return false;
        else
            sum = a[i], cnt++;
    }
    return cnt <= m;
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    cin >> n >> m;
    l = INF;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        r += a[i];
        l = min(a[i], l);
    }
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (ok(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans << endl;

    return 0;
}
