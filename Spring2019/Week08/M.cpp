#include <bits/stdc++.h>

using ll = long long;

const ll MOD = 1000000007;

const int MAXM = 16;

ll dfs(int* a, int n) {
    
    if(n == 1) return 1;
    bool same = true;
    for(int i = 0; i < n / 2; ++i)
        if(a[i] != a[i + n / 2]) { same = false; break; }
    if(same) return 2 * dfs(a, n / 2) % MOD;
    std::set<int> set;
    for(int i = 0; i < n / 2; ++i)
        set.insert(a[i]);
    for(int i = 0; i < n / 2; ++i)
        if(set.count(a[i + n / 2])) return 0;
    ll x = dfs(a, n / 2);
    if(!x) return 0;
    return x * dfs(a + n / 2, n / 2) % MOD;

}

int m, n;
int arr[1 << MAXM];

int main() {

    std::scanf("%d%d", &m, &n);
    for(int i = 0; i < (1 << m); ++i)
        std::scanf("%d", &arr[i]);

    if(!m) std::puts("1");
    else {

        ll result = dfs(arr, 1 << m);
        std::printf("%lld\n", result);

    }

}