#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
const int N = 1e9 + 5;
ll a[maxn], b[maxn];
int main()
{
    int n, h,tmp;
    scanf("%d%d", &n, &h);
    for (int i = 1,l,r; i <= n;i++){
        scanf("%d%d", &l, &r);
        a[i] = r - l;
        b[i] = l - tmp;
        tmp = r;
    }
    b[1] = 0LL;
    n++;
    a[n] = 0LL;
    b[n] = N;
    for (int i = 1; i <= n; i++) a[i] += a[i - 1], b[i] += b[i - 1];
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        ll l = i + 1, r = n, pos = -1;
        while(l <= r){
            ll m = l + r >> 1;
            if(b[m] - b[i] >= h){
                pos = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        assert(pos > 0);
        ans = max(ans, a[pos - 1] - a[i - 1] + h);
    }
    printf("%lld\n", ans);
}