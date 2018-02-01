#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
typedef long long ll;
typedef long double ld;

int n;
int a[maxn];
vector<int> disc;
ll bit1[maxn];
ll bitsum[maxn];
int inline lsb(int x)
{
    return x & (-x);
}
ll query(ll cc[], int x)
{
    ll ret = 0;
    while (x)
    {
        ret += cc[x];
        x -= lsb(x);
    }
    return ret;
}
void add(ll cc[], int x, int b)
{
    while (x < disc.size())
    {
        cc[x] += b;
        x += lsb(x);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%d", &n))
    {
        disc = {-inf, inf};
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            disc.push_back(a[i]);
        }
        sort(disc.begin(), disc.end());
        disc.erase(unique(disc.begin(), disc.end()), disc.end());
        ld ans = 0;
        for (int i = 0; i < n; i++)
        {
            int id = lower_bound(disc.begin(), disc.end(), a[i]) - disc.begin();
            int L = id - 1, R = id;
            if (disc[id - 1] == a[i] - 1) L--;
            if (disc[id + 1] == a[i] + 1) R++;
            ans += a[i] * (query(bit1, disc.size() - 1) - query(bit1, R) + query(bit1, L))
                - (query(bitsum, disc.size() - 1) - query(bitsum, R) + query(bitsum, L));
            add(bit1, id, 1);
            add(bitsum, id, a[i]);
        }
        cout << fixed << setprecision(0) << ans << '\n';
    }
}
