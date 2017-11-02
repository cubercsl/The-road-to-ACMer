#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5;
int s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], Rank[maxn], height[maxn];

void build_sa(int m, int n)
{
    n++;
    int *x = t, *y = t2;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; ~i; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        int p = 0;
        for (int i = n - k; i < n; i++) y[p++] = i;
        for (int i = 0; i < n; i++)
            if (sa[i] >= k) y[p++] = sa[i] - k;
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 0; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; ~i; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n) break;
        m = p;
    }
    n--;
    int k = 0;
    for (int i = 0; i <= n; i++) Rank[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (k) k--;
        int j = sa[Rank[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        height[Rank[i]] = k;
    }
}

int len;
int check(int x, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (sa[i] < len && sa[i] + x <= len && height[i] < x)
        {
            for (++i; i <= n && height[i] >= x && sa[i] < len; i++)
                ;
            if (i > n || height[i] < x)
                return sa[i - 1];
        }
    }
    return -1;
}

char buf[maxn];
int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        int tot = 0, a = 128;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            if (i == 0) len = strlen(buf);
            for (int j = 0; buf[j]; j++)
                s[tot++] = buf[j];
            s[tot++] = a++;
        }
        s[--tot] = 0;
        build_sa(a, tot);
        int ans = 0, st;
        int L = 1, R = len + 1;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            int tmp = check(mid, tot);
            if (~tmp)
                R = mid - 1, st = tmp, ans = mid;
            else
                L = mid + 1;
        }
        printf("Case #%d: ", ++kase);
        if (R <= len)
        {
            for (int i = 0; i < ans; i++)
                printf("%c", s[st + i]);
            puts("");
        }
        else
            puts("Impossible");
    }
}
