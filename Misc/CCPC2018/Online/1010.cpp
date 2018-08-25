#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int bit[N];
void update(int x, int v)
{
    for (int i = x; i < N; i += i & -i)
        bit[i] = max(bit[i], v);
}

int query(int x)
{
    int ret = 0;
    for (int i = x; i; i -= i & -i)
        ret = max(ret, bit[i]);
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        memset(bit, 0, sizeof(bit));
        vector<tuple<int, int, int>> a;
        vector<int> v;
        v.push_back(-1);
        for (int i = 0, x, y, z; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            a.emplace_back(x, -y, z);
            v.push_back(y);
        }
        sort(a.begin(), a.end());
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int x, y, z, ans = 0;
        for (auto& t : a)
        {
            tie(x, y, z) = t;
            y = -y;
            int pos = lower_bound(v.begin(), v.end(), y) - v.begin();
            int tmp = query(pos - 1) + z;
            update(pos, tmp);
            ans = max(ans, tmp);
        }
        printf("%d\n", ans);
    }
}