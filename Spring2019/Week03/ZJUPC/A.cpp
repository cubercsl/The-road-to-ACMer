#include <bits/stdc++.h>

const int MAXN = 101000;

using ll = long long;

int t;
int n, m;
int a[MAXN], b[MAXN], p[MAXN], q[MAXN];

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        std::scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i)
            std::scanf("%d", &a[i]);
        for(int i = 0; i < m; ++i)
            std::scanf("%d", &b[i]);
        for(int i = 0; i < n; ++i)
            std::scanf("%d", &p[i]);
        for(int i = 0; i < m; ++i)
            std::scanf("%d", &q[i]);

        std::deque<int> arr[2][2];

        for(int i = 0; i < n; ++i)
            arr[0][p[i]].push_back(a[i]);
        for(int i = 0; i < m; ++i)
            arr[1][q[i]].push_back(b[i]);
        
        std::sort(arr[0][0].begin(), arr[0][0].end());
        std::sort(arr[0][1].begin(), arr[0][1].end());
        std::sort(arr[1][0].begin(), arr[1][0].end());
        std::sort(arr[1][1].begin(), arr[1][1].end());

        int result = 0;
        
        for(int i = 0; i < 2; ++i) {
            
            auto& x = arr[i][0];
            auto& y = arr[!i][1];
            while(!x.empty() && !y.empty()) {
                
                if(x[0] <= y[0]) {
                    
                    x.pop_front();

                } else {
                    
                    x.pop_front();
                    y.pop_front();
                    ++result;

                }

            }

        }

        std::printf("%d\n", result);

    }

}
