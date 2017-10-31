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

const int N = 1e6 + 5;
char s[N];
int Next[N];
void initkmp(char x[], int m)
{
    int i = 0, j = Next[0] = -1;
    while (i < m)
    {
        while (j != -1 && x[i] != x[j]) j = Next[j];
        Next[++i] = ++j;
    }
}
int kmp(char x[], int m, char y[], int n)
{
    int i, j, ans;
    i = j = ans = 0;
    initkmp(x, m);
    while (i < n)
    {
        while (j != -1 && y[i] != x[j]) j = Next[j];
        i++, j++;
        if (j >= m) ans++, y[i - 2] = y[i - 3] = '$', j = Next[j];
    }
    return ans;
}
int Kmp(char x[], int m, char y[], int n)
{
    int i, j, ans;
    i = j = ans = 0;
    initkmp(x, m);
    while (i < n)
    {
        while (j != -1 && y[i] != x[j]) j = Next[j];
        i++, j++;
        if (j >= m) ans++, j = Next[j];
    }
    return ans;
}

char ccpc[] = "CCPC";
char cpc[] = "CPC";
char ccc[] = "CCC";
char ccp[] = "CCP";

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        initkmp(s, n);
        int ans = kmp(ccpc, 4, s, n);
        // printf("%s\n", s);
        ans += (Kmp(cpc, 3, s, n) || Kmp(ccc, 3, s, n) || Kmp(ccp, 3, s, n));
        printf("%d\n", ans);
    }
    return 0;
}
