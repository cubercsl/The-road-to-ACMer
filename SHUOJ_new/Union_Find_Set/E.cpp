#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 210;
int par[maxn];

void init(int n)
{
    for (int i = 1; i <= 2 * n; i++)
        par[i] = i;
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite (int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        par[x] = y;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    Tcase
    {
        int n, m;
        bool flag = 0;
        cin >> n >> m;
        init(n);
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            if (same(x, y) || same(x + n, y + n))
                flag = 1;
            else
                unite(x, y + n), unite(y, x + n);
        }
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
