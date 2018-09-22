#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int, int> PII;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> a(4, INF), b(4, INF);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] += 3 - i;
        for (int i = 1; i <= m; i++) scanf("%d", &b[i]), b[i] += 3 - i;
        if (a[2] < a[3]) swap(a[2], a[3]);
        if (b[2] < b[3]) swap(b[2], b[3]);
        printf("%d\n", [](PII a1, PII a2, PII b1, PII b2) {
            if (a1 > a2) swap(a1, a2);
            if (b1 > b2) swap(b1, b2);
            if (a1 != b1) return (a1 < b1) * 2 - 1;
            if (a2 != b2) return (a2 < b2) * 2 - 1;
            return 0;
        }({a[3], a[2]}, {a[1], a[0]}, {b[3], b[2]}, {b[1], b[0]}));
    }
}