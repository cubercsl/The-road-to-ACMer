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
char s[N], str[N << 1];
int p[N << 1], ans[N];
void Manacher(const char* s, int& n)
{
    str[0] = '$';
    str[1] = '#';
    for (int i = 0; i < n; i++)
    {
        str[(i << 1) + 2] = s[i];
        str[(i << 1) + 3] = '#';
    }
    n = (n << 1) + 2;
    str[n] = 0;
    int mx = 0, id;
    for (int i = 1; i < n; i++)
    {
        p[i] = mx > i ? min(p[(id << 1) - i], mx - i) : 1;
        for (; str[i - p[i]] == str[i + p[i]]; p[i]++)
            if (p[i] + i > mx) mx = p[i] + i, id = i;
    }
}

void solve(const char* s)
{
    int n = strlen(s);
    Manacher(s, n);
    puts(str);
    clr(ans, 0);
    for (int i = 1; i < n; i++)
    {
        printf("%d\n", p[i]);
        int& t = p[i];
        t--;
        if (t == 0) continue;
        ans[(i - t - 1) >> 1] = max(ans[(i - t - 1) >> 1], t);
    }
    n = strlen(s);
    for (int i = 0; i < n; i++)
        printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    while (~scanf("%s", s))
        solve(s);
    return 0;
}
