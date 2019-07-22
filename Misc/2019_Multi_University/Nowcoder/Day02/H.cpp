#include <bits/stdc++.h>
 
 
typedef long long i64;
 
 
const int MAXN = 1100;
 
int n, m;
int arr[MAXN][MAXN];
 
int main() {
     
    std::scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
             
            char c;
            std::scanf(" %c", &c);
            arr[i][j] = c - '0';
             
        }
     
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(arr[i][j]) arr[i][j] += arr[i - 1][j];
     
    std::vector<int> result;
    std::stack<std::pair<int, int>> stack;
     
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j) {
             
            if(stack.empty() && !arr[i][j]) continue;
            if(stack.empty() || stack.top().second <= arr[i][j])
                stack.push(std::pair<int, int>(j, arr[i][j]));
            else {
                 
                int last = -1;
                while(!stack.empty() && stack.top().second > arr[i][j]) {
                     
                    last = stack.top().first;
                    int dx = stack.top().second, dy = j - last;
                    result.push_back(dx * dy);
                    result.push_back((dx - 1) * dy);
                    result.push_back(dx * (dy - 1));
                    std::sort(result.begin(), result.end(), std::greater<int>());
                    result.resize(2);
                    stack.pop();
                     
                }
                stack.push(std::pair<int, int>(last, arr[i][j]));
                 
            }
             
        }
     
    if(result.size() < 2) std::puts("0");
    else std::printf("%d\n", result[1]);
     
}