// Power Strings, POJ2406

/*Sample Input
abcd
aaaa
ababab
.
*/

#include <cstdio>
#include <cstring>
#include <vector>
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

const int maxn = 1e6 + 5;
char s[maxn];

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

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    while (~scanf("%s", s))
    {
        if (s[0] == '.')
            break;
        int len = strlen(s);
        initkmp(s, len);
        for (int i = 0; i <= len; i++)
            printf("%d%c", ne[i], i == len ? '\n' : ' ');
        printf("%d\n", len % (len - ne[len]) ? 1 : len / (len - ne[len]));
    }
    return 0;
}
