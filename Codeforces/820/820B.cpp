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
    int n, a;
    input_2(n, a)
    {
        double base = 180.0 / n;
        double r = a / base;
        //  cout << r << endl;
        int b = r + 0.5;
        if (!b)
            b = 1;
        if (b > n - 2)
            b = n - 2;
        cout << "1 " << "2 " << n  - b + 1 << endl;
    }
    return 0;
}
