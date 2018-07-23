#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
struct Node
{
    pair<int, int> p;
    int id;
    bool operator<(const Node& rhs) const
    {
        return p < rhs.p;
    }
} p[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 3 * n; i++)
        {
            scanf("%d%d", &p[i].p.first, &p[i].p.second);
            p[i].id = i + 1;
        }
        sort(p, p + n * 3);
        for (int i = 0; i < n * 3; i += 3)
            printf("%d %d %d\n", p[i].id, p[i + 1].id, p[i + 2].id);
    }
}