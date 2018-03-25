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

int a[3][1005][1005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int X, Y, Z, N;
    cin >> X >> Y >> Z >> N;
    while (N--)
    {
        static int x, y, z;
        cin >> x >> y >> z;
        --x, --y, --z;
        a[0][x][y] = 1;
        a[1][z][y] = 1;
        a[2][z][x] = 1;
    }
    for (int yy = Y - 1; ~yy; yy--)
    {
        for (int xx = 0; xx < X; xx++)
        {
            if (a[0][xx][yy])
                cout << 'x';
            else
                cout << '.';
        }
        cout << ' ';
        for (int zz = 0; zz < Z; zz++)
        {
            if (a[1][zz][yy])
                cout << 'x';
            else
                cout << '.';
        }
        cout << endl;
    }
    cout << '\n';
    for (int zz = 0; zz < Z; zz++)
    {
        for (int xx = 0; xx < X; xx++)
            if (a[2][zz][xx])
                cout << 'x';
            else
                cout << '.';
        cout << endl;
    }
    return 0;
}