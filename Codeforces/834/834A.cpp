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

char m[] = "^>v<";

int main()
{
    char a, b;
    int n;
    while (cin >> a >> b >> n)
    {
        int ka, kb;
        for (int i = 0; i < 4; i++)
        {
            if (a == m[i])
                ka = i;
            if (b == m[i])
                kb = i;
        }
        if ((ka - kb) % 2 == 0)
            cout << "undefined" << endl;
        else if ((ka + n) % 4 == kb)
            cout << "cw" << endl;
        else
            cout << "ccw" << endl;

    }
    return 0;
}
