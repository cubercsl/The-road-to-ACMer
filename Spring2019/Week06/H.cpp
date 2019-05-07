#include <bits/stdc++.h>

using ll = long long;

const int MAXN = 101000;

int t;
int n;
int arr[MAXN];
int crack[MAXN];

bool check(int* p) {

    return p[-1] < p[0] && p[1] < p[0];

}

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        std::scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            std::scanf("%d", &arr[i]);
        
        if(n <= 3) std::puts("0");
        else {
            
            crack[0] = crack[n - 1] = 0;
            int sum = 0;
            for(int i = 1; i < n - 1; ++i)
                sum += crack[i] = check(&arr[i]);
            int result = sum;
            result = std::min(result, sum - crack[1]);
            result = std::min(result, sum - crack[n - 2]);
            int a1[] = {arr[0], arr[2], arr[3]};
            int a2[] = {arr[n - 4], arr[n - 3], arr[n - 1]};
            result = std::min(result, sum - crack[1] - crack[2] + check(&a1[1]));
            result = std::min(result, sum - crack[n - 3] - crack[n - 2] + check(&a2[1]));
            for(int i = 2; i < n - 2; ++i) {
                
                int a3[] = {arr[i - 2], arr[i - 1], arr[i + 1], arr[i + 2]};
                result = std::min(result, sum - crack[i - 1] - crack[i] - crack[i + 1] + check(&a3[1]) + check(&a3[2]));
                
            }
            std::printf("%d\n", result);

        }

    }

}
