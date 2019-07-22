#include <bits/stdc++.h>


const int MAXN = 10001000;
const int MAXM = 100;

unsigned int arr[MAXN];

int n, m;
unsigned int x, y, z;
unsigned int rng61() {

    unsigned int t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
    
}
std::map<int, std::vector<int>> query;
unsigned int result[MAXM];
int t;

int main() {

    while(~std::scanf("%d%d%u%u%u", &n, &m, &x, &y, &z)) {

        for(int i = 0; i < n; ++i)
            arr[i] = rng61();
        query = {};
        for(int i = 0; i < m; ++i) {
            
            int x;
            std::scanf("%d", &x);
            query[x].push_back(i);

        }
        int last = n;
        for(auto it = query.rbegin(); it != query.rend(); ++it) {
            
            int k = it->first;
            std::nth_element(arr, arr + k, arr + last);
            for(auto&& x : it->second)
                result[x] = arr[k];
            last = k;

        }

        ++t;
        std::printf("Case #%d:", t);
        for(int i = 0; i < m; ++i)
            std::printf(" %u", result[i]);
        std::putchar('\n');

    }

}