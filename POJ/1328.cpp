// Radar Installation, POJ1328

/*Sample Input
3 2
1 2
-3 1
2 1

1 2
0 2

0 0
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;
bool bad;

struct radar
{
    double l, r;
} a[1005];

bool cmp(radar a, radar b)
{
    if (a.r == b.r)
        return a.l > b.l;
    return a.r < b.r;
}

int main()
{
    int n, d, kase = 0;
    while (cin >> n >> d, n && d)
    {
        bad = 0;
        int x, y;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            if (bad)
                continue;
            if (y > d)
                bad = 1;
            double r = sqrt(d * d - y * y);
            a[i].l = x - r;
            a[i].r = x + r;
        }
        cout << "Case " << ++kase << ": ";
        if (bad)
            cout << -1 << endl;
        else
        {
            sort(a, a + n, cmp);
            double tmp = a[0].r;
            int cnt = 1;
            for (int i = 1; i < n; i++)
            {
                if (tmp < a[i].l)
                    cnt++, tmp = a[i].r;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
