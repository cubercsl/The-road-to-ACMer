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

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int t;
    char s[1005];
    scanf("%d", &t);
    vector <int> v;
    while (t--)
    {
        ll ans = 0;
        scanf("%s", s);
        for (int i = 0; i < strlen(s); i++)
        {
            v.clear();
            if (s[i] == '(')
            {
                i++;
                while (s[i++] != ')')
                    v.pb(s[i - 1] - '0');
                i += 2;
                int n = s[i++] - '0';
                while (n--)
                {
                    for (int j = 0; j < v.size(); j++)
                        ans = (ans * 10 + v[j]) % mod;
                }
            }
            else
                ans = (ans * 10 + s[i] - '0') % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
