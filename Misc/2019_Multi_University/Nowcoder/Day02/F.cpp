#include <bits/stdc++.h>
 
 
typedef long long i64;
 
 
const int MAXN = 50;
 
int n;
i64 arr[MAXN][MAXN];
 
std::vector<int> vec1, vec2;
i64 dfs(int depth = 0) {
     
    if(depth == n * 2) {
         
        return 0;
         
    }
    i64 result = LLONG_MAX;
    if(int(vec1.size()) < n) {
         
        i64 current = 0;
        for(int x : vec1) current += arr[x][depth];
        vec1.push_back(depth);
        result = std::min(result, current + dfs(depth + 1));
        vec1.pop_back();
         
    }
    if(int(vec2.size()) < n) {
         
        i64 current = 0;
        for(int x : vec2) current += arr[x][depth];
        vec2.push_back(depth);
        result = std::min(result, current + dfs(depth + 1));
        vec2.pop_back();
         
    }
    return result;
     
}
 
int main() {
     
    std::scanf("%d", &n);
    for(int i = 0; i < n * 2; ++i)
        for(int j = 0; j < n * 2; ++j)
            std::scanf("%lld", &arr[i][j]);
     
    i64 result = 0;
    for(int i = 0; i < n * 2 - 1; ++i)
        for(int j = i + 1; j < n * 2; ++j)
            result += arr[i][j];
    result -= dfs();
    std::printf("%lld\n", result);
     
}