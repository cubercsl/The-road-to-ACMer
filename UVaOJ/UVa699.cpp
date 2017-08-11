// The Falling Leaves, UVa699

/*Sample Input
5  7  -1  6  -1  -1  3  -1  -1
8  2  9  -1  -1  6  5  -1  -1  12  -1
-1  3  7  -1  -1  -1
-1
*/

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

const int maxn = 1000;
int sum[maxn];

void build (int p)
{
    int v;
    cin >> v;
    if (v == -1) return;
    sum[p] += v;
    build(p - 1);
    build(p + 1);
}

bool init()
{
    int v;
    cin >> v;
    if (v == -1) return false;
    clr(sum, 0);
    int pos = maxn / 2;
    sum[pos] = v;
    build(pos - 1);
    build(pos + 1);
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int kase = 0;
    while (init())
    {
        int p = 0;
        while (sum[p] == 0)p++;
        cout << "Case " << ++kase << ":" << endl;
        cout << sum[p++];
        while (sum[p]) cout << " " << sum[p++];
        cout << endl << endl;
    }
    return 0;
}
