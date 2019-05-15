
#include <bits/stdc++.h>

using ll = long long;

const int MAXN = 101000;
const int MAXF = 32;

int n;
int arr[MAXN];

int fib[MAXF];

int main() {

    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < MAXF; ++i)
        fib[i] = fib[i - 2] + fib[i - 1];

    std::scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        std::scanf("%d", &arr[i]);

    std::set<int> s1, s2;
    for(int i = 0; i < n; ++i)
        if(arr[i] == fib[0]) s1.insert(i);
    int result[2] = {-1, -1};
    if(s1.size() >= 2) {

        auto it = s1.begin();
        result[0] = *it;
        ++it;
        result[1] = *it;

    } else {
        
        for(int i = 2; i < MAXF; ++i) {

            s2.clear();
            for(int j = 0; j < n; ++j)
                if(arr[j] == fib[i]) s2.insert(j);
            if(!s1.empty() && !s2.empty()) {
                
                result[0] = *s1.begin();
                result[1] = *s2.begin();
                break;

            }
            s1 = std::move(s2);

        }

    }

    if(result[0] >= 0) std::printf("%d %d\n", result[0] + 1, result[1] + 1);
    else std::puts("impossible");

}
