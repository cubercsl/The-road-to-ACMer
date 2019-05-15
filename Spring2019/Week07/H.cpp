#include <bits/stdc++.h>

using ll = long long;

const int MAX = 60;

ll m;

bool check(ll a, ll b, int c) {

    for(int i = 0; i < c; ++i) {
        
        a /= b;
        if(!a) return false;

    }
    return true;

}
ll calc(ll a, int b) {

    ll result = 1;
    for(int i = 0; i < b; ++i)
        result *= a;
    return result;

}

int main() {

    while(~std::scanf("%lld", &m)) {

        int n = -1, s = -1;
        for(int i = 2; i <= MAX; ++i) {

            ll sum = 0;
            for(int j = 1; check(m - sum, j, i); ++j) {
                
                sum += calc(j, i);
                if(sum == m) { n = i + 1, s = j; goto done; }

            }

        }

        done:
        if(n > 0) std::printf("%d %d\n", n, s);
        else std::puts("impossible");

    }

}
