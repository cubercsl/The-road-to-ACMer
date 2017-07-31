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
    int s, v1, v2, t1, t2;
    while (cin >> s >> v1 >> v2 >> t1 >> t2)
    {
        int a1 = s * v1 + t1 * 2;
        int a2 = s * v2 + t2 * 2;
        if (a1 < a2)
            cout << "First" << endl;
        else if (a1 > a2)
            cout << "Second" << endl;
        else
            cout << "Friendship" << endl;
    }
    return 0;
}
