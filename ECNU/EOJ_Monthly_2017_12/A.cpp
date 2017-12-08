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

int a[6], b[6];
int vis[6];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int p;
    while(cin >> p)
    {
        clr(vis, 0);
        for(int i = 0; i < 6; i++) cin >> a[i];
        for(int i = 0; i < 6; i++) cin >> b[i];
        for(int i = 0 ; i < 6; i++)
           for(int j =0; j < 6; j++)
           {
               int tmp = (a[i] + b[j]) % p;
               vis[tmp]++;
           }
        bool flag = 1;
        for(int i = 1; i < p && flag;i++) if(vis[i] != vis[0]) flag = 0;
        puts(flag ? "YES" : "NO");
    }

    return 0;
}
