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

const int maxn = 100005;
struct Point
{
    int x, y, id;
    bool operator < (const Point &b) const
    {
        if (x == b.x)
            return y < b.y;
        return x < b.x;
    }
} P[maxn];

double K(Point a, Point b)
{
    double dy = b.y - a.y;
    double dx = b.x - a.x;
    return dy / dx;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> P[i].x >> P[i].y;
        P[i].id = i + 1;
    }
    sort(P, P + n);
    vector <int> v;
    double ans = -INF;
    for (int i = 0; i < n - 1; i++)
    {
        double tmp = K(P[i], P[i + 1]);
        if (tmp < ans) continue;
        else if (tmp > ans) v.clear();
        ans = tmp;
        v.pb(i);
    }
    for (int i = 0; i < v.size(); i++)
        cout << P[v[i]].id << " " << P[v[i] + 1].id << endl;
    return 0;
}
