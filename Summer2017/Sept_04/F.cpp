#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;

struct node
{
    int id, period, time;
    node (int a, int p, int t): id(a), period(p), time(t) {}
    bool operator < (const node &rhs) const
    {
        return time > rhs.time || (time == rhs.time && id > rhs.id);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    priority_queue <node > q;
    char s[20];
    while (scanf("%s", s) && s[0] != '#')
    {
        int id, period;
        scanf("%d%d", &id, &period);
        q.push(node(id, period, period));
    }
    int k;
    scanf("%d", &k);
    while (k--)
    {
        node tmp = q.top();
        q.pop();
        printf("%d\n", tmp.id);
        tmp.time += tmp.period;
        q.push(tmp);
    }
    return 0;
}
