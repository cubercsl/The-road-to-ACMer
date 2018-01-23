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

const int N = 5;

struct Node
{
    int type, id, cnt;
    bool operator<(const Node& rhs) const
    {
        return cnt > rhs.cnt || cnt == rhs.cnt && type > rhs.type;
    }
} a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int p, q, r;
    cin >> p >> q >> r;
    a[0] = {p, 1, 0};
    a[1] = {q, 2, 0};
    a[2] = {r, 3, 0};
    for (int i = 0; i < 100; i++)
    {
        sort(a, a + 3);
        // cout << a[0].cnt << " " << a[0].id<<" ";
        int ans = a[0].id;
        // cout << ans << endl;
        --ans;
        if (ans == 0) ans = 3;
        cout << ans << endl;
        --ans;
        if(ans == 0) ans = 3;
        for (int i = 0; i < 3; i++)
            if (a[i].id == ans) a[i].cnt++;
    }
    return 0;
}
