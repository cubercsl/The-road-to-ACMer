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

const int maxn = 5e6 + 5;
vector <int> v[maxn];
map<PII, int> acm;

int main()
{
    int n;
    scanf("%d", &n);
    int tot = 0;
    while (n--)
    {
        int id, x, y;
        scanf("%d%d%d", &id, &x, &y);
        PII tmp = mp(x, y);
        if (!acm.count(tmp))
            acm[tmp] = tot++;
        v[acm[tmp]].pb(id);

    }
    for (int i = 0; i < tot; i++)
        sort(v[i].begin(), v[i].end());
    scanf("%d", &n);
    while (n--)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        printf("%d\n", v[acm[mp(x, y)]][k - 1]);
    }
    return 0;
}
