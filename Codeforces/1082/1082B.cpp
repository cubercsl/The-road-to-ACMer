#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
char s[N];

int a[N];

bool check(int m, int n)
{
    for (int i = 1; i + m - 1 <= n; i++)
    {
        if (a[i + m - 1] - a[i - 1] == m) return true;
        if (a[i + m - 1] - a[i - 1] == m - 1 && a[n] > m - 1) return true;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; s[i]; i++) a[i] = s[i] == 'G';
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    int l = 1, r = n, ans = 0;
    while(l <= r)
    {
        int m = l + r >> 1;
        if (check(m, n)) l = m + 1, ans = m;
        else r = m - 1;
    }
    printf("%d\n", ans);
}