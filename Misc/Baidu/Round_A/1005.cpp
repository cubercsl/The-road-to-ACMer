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

int check(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
        return 1;
    else if (year % 400 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    fastin
    int t;
    int y, m, d;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d-%d-%d", &y, &m, &d);
        int  k = 0;
        if (m > 2)
        {
            while (true)
            {
                ++y;
                if (check(y)) k += 2;
                else ++k;
                k %= 7;
                if (!k) break;
            }
        }
        else if (m == 1 || (m == 2 && d <= 28))
        {
            while (true)
            {
                ++y;
                if (check(y - 1)) k += 2;
                else ++k;
                k %= 7;
                if (!k) break;
            }
        }
        else if (m == 2 && d == 29)
        {
            while (true)
            {
                ++y;
                if (check(y - 1)) k += 2;
                else ++k;
                k %= 7;
                if (!k && check(y)) break;
            }
        }
        printf("%d\n", y);
    }
    return 0;
}
