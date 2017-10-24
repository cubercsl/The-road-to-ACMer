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

const int maxn = 1e6 + 5;

int ne[maxn];
void initkmp(char x[], int m)
{
    int i, j;
    j = ne[0] = -1;
    i = 0;
    while (i < m)
    {
        while (j != -1 && x[i] != x[j])
            j = ne[j];
        ne[++i] = ++j;
    }
}

ll kmp(char x[], int m, char y[], int n)
{
    ll i, j;
    ll ans = 0;
    i = j = 0;
    initkmp (x, m);
    while (i < n)
    {
        while (j != -1 && y[i] != x[j])
        {
            ans = (ans + ((1LL + j)  * j  / 2LL) % mod) % mod;
            j = ne[j];
        }
        i++;
        j++;
        if (j >= m)
        {
            ans = (ans + ((1LL + j)  * j  / 2LL) % mod) % mod;
            j = ne[j];
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char s[maxn], t[maxn];
        scanf("%s%s", s, t);
        int len1 = strlen(s);
        int len2 = strlen(t);
        reverse(s, s + len1);
        for (int i = len1; i < maxn; i++)
            s[i] = '#';
        len1 += len2;
        reverse(t, t + len2);
        printf("%lld\n", kmp(t, len2, s, len1));
    }
    return 0;
}
