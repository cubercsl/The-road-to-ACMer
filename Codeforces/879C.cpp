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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    char op[2];
    int num;
    scanf("%d", &n);
    int t1 = 0, t2 = 1023;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", op, &num);
        switch (op[0])
        {
        case '&':
            t1 &= num;
            t2 &= num;
            break;
        case '|':
            t1 |= num;
            t2 |= num;
            break;
        case '^':
            t1 ^= num;
            t2 ^= num;
            break;
        }
    }
    int OR = 0, AND = 1023, XOR = 0;
    for (int i = 0; i < 10; i++)
    {
        if ((t1 >> i & 1) && (t2 >> i & 1))
            OR |= 1 << i;
        else if ((t1 >> i & 1) && !(t2 >> i & 1))
            XOR |= 1 << i;
        else if (!(t1 >> i & 1) && !(t2 >> i & 1))
            AND ^= 1 << i;
    }
    puts("3");
    printf("& %d\n", AND);
    printf("| %d\n", OR);
    printf("^ %d\n", XOR);
    return 0;
}
