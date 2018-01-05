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

const int N = 1 << 18;
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
bool kmp(char x[], int m, char y[], int n)
{
    int i, j, ans;
    i = j = ans = 0;
    initkmp(x, m);
    while (i < n)
    {
        while (j != -1 && y[i] != x[j]) j = Next[j];
        i++, j++;
        if (j >= m) return true;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    char s[N], t[N];
    while (~scanf("%s%s", s, t))
    {
        int n = strlen(s);
        for (int i = 0; i < n; i++) s[n + i] = s[i];
        n <<= 1;
        int m = strlen(t);
        puts(kmp(t, m, s, n) ? "yes" : "no");
    }
    return 0;
}
