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

const int maxn = 12;

struct node
{
    int id, v, a;
    bool operator < (const node &b)const
    {
        return id < b.id;
    }
} my[maxn], npc[maxn], a[maxn], b[maxn];

bool solve(int n)
{
    memcpy(a, my, sizeof(my));
    memcpy(b, npc, sizeof(npc));
    int p1 = 0, p2 = 0;
    while (p1 < n  && p2 < n )
    {
        int c1 = (a[p1].v + b[p2].a - 1) / b[p2].a;
        int c2 = (b[p2].v + a[p1].a - 1) / a[p1].a;
        if (c1 < c2)
            b[p2].v -= c1 * a[p1].a, p1++;
        else if (c1 > c2)
            a[p1].v -= c2 * b[p2].a, p2++;
        else
            p1++, p2++;
    }
    if (p1 == n)
        return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        bool flag = false;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> npc[i].v >> npc[i].a;
            npc[i].id = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> my[i].v >> my[i].a;
            my[i].id = i;
        }
        do
        {
            flag = solve(n);
            if (flag)
                break;
        }
        while (next_permutation(my, my + n));
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
