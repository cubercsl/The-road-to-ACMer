#include <bits/stdc++.h>


using ll = long long;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }

const int MAXN = 101000;

int t;
int n;
ll x, y;
int arr[MAXN];

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        std::scanf("%d%lld%lld", &n, &x, &y);
        for(int i = 0; i < n; ++i)
            std::scanf("%d", &arr[i]);
        
        ll xx = 0, yy = 0;
        for(int i = 0; i < n; ++i) {
            
            xx += ll(i + 1) * arr[i];
            yy += ll(i + 1) * arr[i] * arr[i];

        }
        ll dx = x - xx, dy = y - yy;
        
        std::map<int, int> m;
        for(int i = 0; i < n; ++i)
            ++m[arr[i]];

        if(!dx) {

            if(dy) std::puts("0");
            else {
                
                ll result = 0;
                for(auto&& p : m)
                    result += ll(p.second) * (p.second - 1) / 2;
                std::printf("%lld\n", result);

            }
            
        } else {
            
            if(dy % dx || dy / dx <= 0) std::puts("0");
            else {
                
                ll g = gcd(std::abs(dx), std::abs(dy));
                ll result = 0;
                for(int i = 1; i <= n - 1; ++i) {
                    
                    if(i > g) break;
                    if(g % i) continue;
                    for(int j = 0; j < n - i; ++j) {
                        
                        int i1 = j, i2 = j + i;
                        ll a1 = arr[i1], a2 = arr[i2];
                        if(i * (a1 - a2) == dx && i * (a1 * a1 - a2 * a2) == dy) ++result;

                    }

                }
                std::printf("%lld\n", result);

            }

        }
        
    }

}
