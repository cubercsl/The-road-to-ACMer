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

const int N = 1 << 20;
// 返回y中x的个数
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
    // initkmp(x, m);
    while (i < n)
    {
        while (j != -1 && y[i] != x[j]) j = Next[j];
        i++, j++;
        if (j >= m) ans++, j = Next[j];
    }
    return ans;
}

char s[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%s", s);
    int n = strlen(s);
    initkmp(s, n);
    int t = n;
    while (t = Next[t])
    {
        if (kmp(s, t, s, n) > 2)
        {
            s[t] = '\0';
            printf("%s\n", s);
            return 0;
        }
    }
    puts("Just a legend");
    return 0;
}