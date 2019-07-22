#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 8;
long long w[N];
char s[N][N];
struct HeapNode
{
    bitset<N> a;
    long long w;
    bool operator<(const HeapNode& rhs) const
    {
        return w > rhs.w;
    }
};

unordered_set<bitset<N>> vis;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    --k;
    if (k == 0) return puts("0"), 0;
    for (int i = 0; i < n; i++) scanf("%d", w + i);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    priority_queue<HeapNode> q;
    for (int i = 0; i < n; i++)
    {
        bitset<N> s;
        s.set(i);
        q.push({s, w[i]});
    }
    while (!q.empty())
    {
        auto t = q.top();
        --k;
        q.pop();
        if (k == 0) return printf("%lld\n", t.w), 0;
        for (int i = 0; i < n; i++)
        {
            if (t.a[i]) continue;
            bool flag = true;
            for (int j = t.a._Find_first(); j != t.a.size(); j = t.a._Find_next(j))
            {
                if (s[i][j] == '0')
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                auto nt = t;
                nt.a.set(i);
                nt.w += w[i];
                if (vis.count(nt.a)) continue;
                vis.insert(nt.a);
                q.push(nt);
            }
        }
    }
    puts("-1");
}