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

int main()
{
    int c, v0, v1, a, l;
    while (cin >> c >> v0 >> v1 >> a >> l)
    {
        int now = 0, cnt = 0;;
        int v = v0;
        while (now < c)
        {
            cnt++;
            if (now)
                now -= l;
            now += v;
            v += a;
            if (v > v1)
                v = v1;
        }
        cout << cnt << endl;
    }
    return 0;

}
