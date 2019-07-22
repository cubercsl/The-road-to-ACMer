#include<bits/stdc++.h>

const int MAXN = 201000;

int t;
int n, m;
int arr[MAXN];

int main() {
    
    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        
        std::scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i)
            std::scanf("%d", &arr[i]);

        for(int i = 0; i < 30; ++i) {
            if (m >> i & 1)  {
                for (int j = (1 << i); j < n; j++) {
                    arr[j] ^= arr[j - (1 << i)];
                }
            }
        }
        for (int i = 0; i < n; i++) printf("%d%c", arr[i], " \n"[i == n - 1]);
    }
    return 0;
}