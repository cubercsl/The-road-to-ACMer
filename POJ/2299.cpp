// Ultra-QuickSort, POJ2299

/*Sample Input
5
9
1
0
5
4
3
1
2
3
0
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
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

const int maxn = 5e5 + 5;
int BIT[maxn];
ll a[maxn], b[maxn];
int n;
int lowbit(int x)
{
    return x&(-x);
}
void add(int i, int x)
{
    while (i <= n)
        BIT[i] += x, i += lowbit(i);
}

int query(int i)
{
    int sum = 0;
    while (i > 0)
        sum += BIT[i], i -= lowbit(i); 
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n && n)
    {
        clr(BIT, 0);
        for (int i = 0; i < n; i++)
        {
            ll num;
            cin >> num;
            a[i] = b[i] = num;
        }
        sort(b, b + n);
        int size = unique(b, b + n) - b;
        for (int i = 0; i < n; i++)
            a[i] = lower_bound(b, b + size, a[i]) - b + 1; // 离散化
        ll ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            add(a[i], 1);
            ans += query(a[i] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
