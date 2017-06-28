#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int a, b, c;
bool solve(int &x, int &y, int &z)
{
    for (int i = 100; i >= 1; i--)
        for (int j = 100; j >= 1; j--)
            for (int k = 99; k >= 1; k -= 3)
            {
                if (i + j + k != 100)
                    continue;
                if ((i * a + j * b + (k / 3) * c) != 100)
                    continue;
                x = i, y = j, z = k;
                return true;
            }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int kase = 0;
    while (cin >> a >> b >> c)
    {
        bool flag = 1;
        int na, nb, nc;
        flag = solve(na, nb, nc);
        cout << "Case " << ++kase << ":" << endl;
        if (flag)
            cout << na << " " << nb << " " << nc << endl;
        else
            cout << "Impossible" << endl;
    }
    return 0;
}
