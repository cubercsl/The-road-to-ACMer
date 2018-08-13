#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;
bool vis[N];
int ans[N];
int main()
{
    int n;
    scanf("%d", &n);
    int t = 1;
    while (t <= n) t <<= 1;
    for (int i = n - 1; ~i; i--)
    {
        while (t - i - 1 < 0 || t - i - 1 >= n || vis[t - i - 1]) t >>= 1;
        ans[i] = t - i - 1;
        vis[t - i - 1] = 1;
    }
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i == n - 1]);
}