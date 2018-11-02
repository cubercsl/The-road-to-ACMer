#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int a[N], b[N];

int main()
{
    set<int> s;
    int n, m;
    scanf("%d%*d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i), s.insert(a[i]);
    scanf("%d%*d", &m);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", b + i);
        if (s.count(b[i])) ans = 2;
    }
    for (int x = 1; x < 1e9; x <<= 1)
    {
        map<int, int> cnt;
        int y = x << 1;
        for (int i = 0; i < n; i++) cnt[(a[i] + x) % y]++;
        for (int i = 0; i < m; i++) cnt[b[i] % y]++;
        for (auto& t : cnt) ans = max(ans, t.second);
    }
    printf("%d\n", ans);
}
