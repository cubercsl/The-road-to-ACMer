#include <bits/stdc++.h>

using ll = long long;

const int MAXN = 101000;

int n, m;
int p[MAXN], c[MAXN];

bool check(ll x) {

    ll sum = 0;
    for(int i = 0; i < n; ++i)
        sum = std::min(ll(m), sum + std::max(ll(0), p[i] * x - c[i]));
    return sum == m;

}

int main() {
    
    std::scanf("%d%d", &n, &m);
    
    for(int i = 0; i < n; ++i)
        std::scanf("%d%d", &p[i], &c[i]);

    ll left = 1, right = 5e9;
    while(left < right) {

        ll mid = (left + right) / 2;
        if(!check(mid)) left = mid + 1;
        else right = mid;

    }

    std::printf("%lld\n", left);

}