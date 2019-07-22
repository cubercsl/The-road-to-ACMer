#include <bits/stdc++.h>

using i64 = long long;

const int END = -42;
const int MAXN = 501000;

int t;
int n, k;
int arr[MAXN];
int indexs[MAXN];
int prev[MAXN], next[MAXN];

void remove(int x) {
    
    next[prev[x]] = next[x];
    prev[next[x]] = prev[x];

}

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        
        std::scanf("%d%d", &n, &k);
        for(int i = 0; i < n; ++i)
            std::scanf("%d", &arr[i]), indexs[i] = i, prev[i] = i == 0 ? END : i - 1, next[i] = i == n - 1 ? END : i + 1;
        std::sort(indexs, indexs + n, [](int a, int b) { return arr[a] < arr[b]; });
        i64 result = 0;
        for(int i = 0; i < n; ++i) {
            
            int index = indexs[i];
            int il = index, ir = index, cl = 0, cr = 0;
            while(prev[il] != END && cl < k - 1) il = prev[il], ++cl;
            while(next[ir] != END && cr < k - 1) ir = next[ir], ++cr;

            if(cl + cr >= k - 1) {

                while(cl + cr > k - 1) ir = prev[ir], --cr;
                while(il <= index && ir != END) {
                    
                    int jl = prev[il], jr = next[ir];
                    if(jl == END) jl = -1;
                    if(jr == END) jr = n;
                    result += i64(il - jl) * (jr - ir) * arr[index];
                    il = next[il], ir = next[ir], cl--, cr++;

                }

            }
            remove(index);

        }
        std::printf("%lld\n", result);

    }

}