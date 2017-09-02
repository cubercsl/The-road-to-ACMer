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

const int maxn = 36;
ll c[maxn];
void Catalan()
{
    c[0] = c[1] = 1;
    for (int i = 2; i <= 35; i++)
    for (int j = 0; j < i; j++)
    c[i] += c[j] * c[i - j - 1];
}

int main()
{
    Catalan();
    int n;
    int t = 1;
    while (cin >> n && n != -1)
    cout << t++ << " " << n << " " << 2 * c[n] << endl;
    return 0;
}
