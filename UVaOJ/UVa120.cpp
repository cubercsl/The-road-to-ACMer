// Stacks of Flapjacks, UVa120

/*Sample Input
1 2 3 4 5
5 4 3 2 1
5 1 2 3 4
*/

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

const int maxn = 30 + 5;
int n, a[maxn];

void flip(int p)
{
    for (int i = 0; i < p - i; i++)
        swap(a[i], a[p - i]);
    printf("%d ", n - p);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s;
    while (getline(cin, s))
    {
        cout << s << endl;
        stringstream ss(s);
        n = 0;
        while (ss >> a[n]) n++;
        for (int i = n - 1; i > 0; i--)
        {
            int p = max_element(a, a + i + 1) - a;
            if (p == i) continue;
            if (p > 0) flip(p);
            flip(i);
        }
        cout << 0 << endl;
    }
    return 0;
}
