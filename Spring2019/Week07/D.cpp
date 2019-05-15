#include <bits/stdc++.h>

using ll = long long;

const int MAXN = 1001000;

int n;
int arr[MAXN];

int main() {

    std::scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        std::scanf("%d", &arr[i]);


    ll minX = 0, maxX = 1e18;
    ll current = 0;
    for(int i = 0; i < n; ++i) {

        current = arr[i] - current;
        if(i & 1) minX = std::max(minX, -current);
        else maxX = std::min(maxX, current);

    }
    std::printf("%lld\n", std::max(ll(0), maxX - minX + 1));

}
