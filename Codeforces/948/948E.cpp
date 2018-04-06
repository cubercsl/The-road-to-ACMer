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
char S[N], T[N];
int AS[N], AT[N], BS[N], BT[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> (S + 1) >> (T + 1);
    int n = strlen(S + 1), m = strlen(T + 1);
    for (int i = 1; i <= n; i++)
    {
        AS[i] = S[i] == 'A' ? AS[i - 1] + 1 : 0;
        BS[i] = BS[i - 1] + (S[i] == 'B' || S[i] == 'C');
    }
    for (int i = 1; i <= m; i++)
    {
        AT[i] = T[i] == 'A' ? AT[i - 1] + 1 : 0;
        BT[i] = BT[i - 1] + (T[i] == 'B' || T[i] == 'C');
    }
    int q;
    cin >> q;
    while (q--)
    {
        static int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ss = BS[b] - BS[a - 1];
        int tt = BT[d] - BT[c - 1];
        if (ss > tt || (ss & 1) ^ (tt & 1))
            cout << 0;
        else
        {
            int x = min(b - a + 1, AS[b]), y = min(d - c + 1, AT[d]);
            if(x < y) cout << 0;
            else if(x > y  && (x - y) % 3 && ss + 2 > tt) cout << 0;
            else if(x == y && x == b - a + 1  && y != d - c + 1) cout << 0;
            else cout << 1;
        }
    }
    return 0;
}
