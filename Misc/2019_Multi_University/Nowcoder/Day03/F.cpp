#include <bits/stdc++.h>
 
 
typedef long long i64;
 
 
const int MAXN = 510;
 
template <typename T>
struct DQ {
     
    int left, right;
    T data[MAXN * 2];
     
    DQ() : left(0), right(0) {}
     
    bool empty() const { return left == right; }
     
    const T& front() const { return data[left]; }
    const T& back() const { return data[right - 1]; }
     
    void pop_front() { ++left; }
    void push_back(T t) { data[right++] = t; }
    void pop_back() { --right; }
     
};
 
int t, n, m;
int arr[MAXN][MAXN];
int minmax[MAXN][2];
 
int main() {
     
    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
         
        std::scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                std::scanf("%d", &arr[i][j]);
         
        int result = 0;
        for(int i = 0; i < n; ++i) {
             
            for(int j = i; j < n; ++j) {
                 
                if(i == j)
                    for(int k = 0; k < n; ++k)
                        minmax[k][0] = minmax[k][1] = arr[j][k];
                else
                    for(int k = 0; k < n; ++k)
                        minmax[k][0] = std::min(minmax[k][0], arr[j][k]), minmax[k][1] = std::max(minmax[k][1], arr[j][k]);
                 
                DQ<std::pair<int, int>> minq, maxq;
                for(int left = 0, right = 0; right < n; ++right) {
                     
                    while(!minq.empty() && minq.back().second > minmax[right][0]) minq.pop_back();
                    minq.push_back(std::pair<int, int>(right, minmax[right][0]));
                    while(!maxq.empty() && maxq.back().second < minmax[right][1]) maxq.pop_back();
                    maxq.push_back(std::pair<int, int>(right, minmax[right][1]));
                    while(left <= right && maxq.front().second - minq.front().second > m) {
                         
                        ++left;
                        while(!minq.empty() && minq.front().first < left) minq.pop_front();
                        while(!maxq.empty() && maxq.front().first < left) maxq.pop_front();
                         
                    }
                    result = std::max(result, (j - i + 1) * (right - left + 1));
                     
                }
                 
            }
             
        }
        std::printf("%d\n", result);
         
    }
     
}