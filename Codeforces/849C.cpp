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
    int k;
    while (cin >> k)
    {
        if (k == 0)
        {
            puts("ab");
            continue;
        }
        int s = 0;
        string str;
        while (k > 0)
        {
            ll l = 1, r = k, res = 0;
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                if (mid * (mid + 1) / 2 <= k)
                    res = mid,
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            k -= res * (res + 1) / 2;
            char q = s + 'a';
            for (int i = 0; i <= res; i++)
                str.pb(q);
            s++;
        }
        cout << str << endl;
    }

    return 0;
}
