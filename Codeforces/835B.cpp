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
    ll k;
    string n;
    while (cin >> k >> n)
    {
        sort(n.begin(), n.end());
        ll sum = 0;
        for (int i = 0; i < n.length(); i++)
            sum += n[i] - '0';
        int cnt = 0;
        int i = 0;
        while (sum < k)
        {
            sum += (9 - (n[i++] - '0'));
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
