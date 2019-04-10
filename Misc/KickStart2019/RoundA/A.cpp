#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T, kase = 0;;
    scanf("%d", &T);
    while(T--)
    {
        int n, p;
        scanf("%d%d", &n, &p);
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a.begin(), a.end());
        ll sum = 0;
        for (int i = 0; i < p; i++) sum += a[p - 1] - a[i];
        ll ans = sum;
        for (int i = p; i < n; i++)
        {
            sum -= a[i - 1] - a[i - p];
            sum += 1LL * (a[i] - a[i - 1]) * (p - 1);
            ans = min(ans, sum);
        }
        printf("Case #%d: %d\n", ++kase, ans);
    }
}