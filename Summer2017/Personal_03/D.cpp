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

const int maxn = 1005;
int a[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int x = -(a[i] + a[j]);
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                if (a[l] + a[r] == x)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
                if (a[l] + a[r] < x)l++;
                else  r--;
            }
        }
    cout << "No" << endl;
    return 0;
}
