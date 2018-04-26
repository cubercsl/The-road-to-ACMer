#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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

int a[6][6], r[6], c[6];

inline int getid(char c)
{
    if (isdigit(c)) return c - '0';
    return c - 'A' + 10;
}
inline char gao(int x, int y)
{
    int id = x * 6 + y;
    if (id < 10) return id + '0';
    id -= 10;
    return 'A' + id;
}

char s[505];
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
        clr(a, 0), clr(r, 0), clr(c, 0);
        scanf("%s", s);
        for (int i = 0; s[i]; i++)
        {
            int id = getid(s[i]);
            int x = id / 6, y = id % 6;
            a[x][y]++;
        }
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                r[i] += a[i][j], c[j] += a[i][j];
        int mr = *max_element(r, r + 6), mc = *max_element(c, c + 6);
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                if (r[i] == mr && c[j] == mc) printf("%c", gao(i, j));
        puts("");
    }
    return 0;
}