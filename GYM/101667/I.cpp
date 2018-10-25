#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;
int a[N], pat[N];

int ne[N];
void initkmp(int x[], int m)
{
    int i = 0, j = ne[0] = -1;
    while (i < m)
    {
        while (j != -1 && x[i] != x[j]) j = ne[j];
        ne[++i] = ++j;
    }
}

int kmp(int x[], int m, int y[], int n, int& p, int& k)
{
    int i, j, ans;
    i = j = ans = 0;
    vector<int> pos;
    while (i < n - 1)
    {
        while (j != -1 && y[i] != x[j]) j = ne[j];
        i++, j++;
        if (j >= m)
        {
            pos.push_back(i - m);
            j = ne[j];
            // return i - m;
        }
    }
    if (pos.size() == 0) return false;
    p = n - m - pos.back();
    k = pos.back();
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int l = 1, r = n - 1, k = n - 1, p = 1, pos;
    while (l <= r)
    {
        int x = l + r >> 1;
        int m = 0;
        for (int i = x; i < n; i++) pat[m++] = a[i];
        initkmp(pat, m);
        pat[m] = -1;
        if (kmp(pat, m, a, n, p, k))
            r = x - 1;
        else
            l = x + 1;
    }
    printf("%d %d\n", k, p);
}