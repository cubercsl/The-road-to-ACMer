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

int ne[maxn], ext[maxn];

void pre_EKMP(char x[], int m)
{
    ne[0] = m;
    int j = 0;
    while (j + 1 < m && x[j] == x[j + 1]) j++;
    ne[1] = j;
    int k = 1;
    for (int i = 2; i < m; i++)
    {
        int p = ne[k] + k - 1;
        int L = ne[i - k];
        if (i + L < p + 1) ne[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < m && x[i + j] == x[j]) j++;
            ne[i] = j;
            k = i;
        }
    }
}

void EKMP(char x[], int m, char y[], int n)
{
    pre_EKMP(x, m);
    int j = 0;
    while (j < n && j < m && x[j] == y[j])j++;
    ext[0] = j;
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        int p = ext[k] + k - 1;
        int L = ne[i - k];
        if (i + L < p + 1)ext[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < n && j < m && y[i + j] == x[j])j++;
            ext[i] = j;
            k = i;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    char s[maxn], t[maxn];
    ll ans;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%s%s", s, t);
        int slen = strlen(s), tlen = strlen(t);
        reverse(s, s + slen);
        reverse(t, t + tlen);
        EKMP(t, tlen, s, slen);
        for (int i = 0; i < slen; i++)
            ans = (ans + ((ll)ext[i] * (ext[i] + 1) / 2) % mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
