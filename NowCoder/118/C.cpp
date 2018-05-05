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
    int x0, x1, x2, x3, y0, y1, y2, y3;
    int a, b;
    while (cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        double xx1 = 1.0 * (x1 - x0);
        double xx2 = 1.0 * (x2 - x0);
        double xx3 = 1.0 * (x3 - x0);
        double yy1 = 1.0 * (y1 - y0);
        double yy2 = 1.0 * (y2 - y0);
        double yy3 = 1.0 * (y3 - y0);
        if (xx1 != 0)
        {
            if (yy1 != 0)
            {
                yy2 -= xx2 * (yy1 / xx1);
                yy3 -= xx3 * (yy1 / xx1);
                yy1 = 0;
            }
        }
        else if (yy1 != 0)
        {
            swap(xx1, yy1);
            swap(xx2, yy2);
            swap(xx3, yy3);
        }
        else if (yy1 == 0)
        {
            cout << "Yes" << endl;
            continue;
        }

        xx2 /= xx1;
        xx3 /= xx1;
        xx1 = 1;
        if (yy2 != 0)
        {
            yy3 /= yy2;
            yy2 = 1;
            if (xx2 != 0) xx3 -= xx2 * yy3;
            if (xx3 <= 0 && yy3 <= 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (yy3 != 0)
        {
            if (xx2 <= 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
        {
            if (xx2 > 0 && xx3 > 0)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
}
