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

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    int a[4];
    int kase = 0;
    while (cin >> a[0] >> a[1] >> a[2] >> a[3], a[0] + a[1] + a[2] + a[3])
    {
        if (kase++)
            cout << endl;
        sort(a, a + 4);
        int tmp = a[0];
        int cnt = 0;
        do
        {
            if (a[0] == 0)
                continue;
            if (tmp == 0)
                tmp = a[0];
            if (a[0] != tmp)
            {
                tmp = a[0];
                cnt = 0;
                cout << endl;
            }
            if (cnt)
                cout << " ";
            for (int i = 0; i < 4; i++)
                cout << a[i];
            cnt++;
        }
        while (next_permutation(a, a + 4));
        cout << endl;
    }
    return 0;
}
