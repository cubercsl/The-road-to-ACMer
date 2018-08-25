//moira
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp make_pair
#define pb push_back
#define X first
#define Y second
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
    int T, p;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &p);
        printf("0");
        for (int i = 1; i < p; i++)
            printf(" %d", i);
        puts("");

        for (int i = 1; i < p; i++)
        {
            printf("%d", i);
            for (int j = 1; j < p; j++)
                printf(" %d", 0);
            puts("");
        }

        printf("0");
        for (int i = 1; i < p; i++)
            printf(" %d", 0);
        puts("");

        for (int i = 1; i < p; i++)
        {
            printf("%d", 0);
            for (int j = 1; j < p; j++)
                printf(" %d", i * j % p);
            puts("");
        }
    }
    return 0;
}