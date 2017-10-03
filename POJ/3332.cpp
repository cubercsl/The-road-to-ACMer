// Parsing Real Numbers, POJ3332

/*Sample Input
2
  1.5e+2
3.
*/

#include <cctype>
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

int dfa(int s, char c)
{
    switch (s)
    {
    case 0:
        if (c == '+' || c == '-') return 1;
        if (isdigit(c)) return 2;
        return -1;
    case 1:
        if (isdigit(c)) return 2;
        return -1;
    case 2:
        if (isdigit(c)) return 2;
        if (c == '.') return 3;
        if (c == 'E' || c == 'e') return 5;
        if (c == '\0') return 8;
        return -1;
    case 3:
        if (isdigit(c)) return 4;
        return -1;
    case 4:
        if (isdigit(c)) return 4;
        if (c == 'E' || c == 'e') return 5;
        if (c == '\0') return 8;
        return -1;
    case 5:
        if (c == '+' || c == '-') return 6;
        if (isdigit(c)) return 7;
        return -1;
    case 6:
        if (isdigit(c)) return 7;
        return -1;
    case 7:
        if (isdigit(c)) return 7;
        if (c == '\0') return 8;
        return -1;
    }
    return -1;
}
bool solve(const char* s)
{
    int n = strlen(s);
    int st = 0;
    for (int i = 0; i <= n; i++)
    {
        st = dfa(st, s[i]);
        if (st == -1) return false;
    }
    return st == 8;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    char s[1005];
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        puts(solve(s) ? "LEGAL" : "ILLEGAL");
    }
    return 0;
}
