#include <bits/stdc++.h>

const int MAXN = 110;

using ll = long long;

int t;
int n;
ll a[MAXN], b[MAXN];

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        std::scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            std::scanf("%lld", &a[i]);
        for(int i = 0; i < n; ++i)
            std::scanf("%lld", &b[i]);

        bool ok = true;
        for(int i = n - 1; i >= 0; --i) {
            
            if(b[i] < a[i]) { ok = false; break; }
            if(i) b[i - 1] += b[i] - a[i];

        }

        std::puts(ok ? "Yes" : "No");

    }

}
