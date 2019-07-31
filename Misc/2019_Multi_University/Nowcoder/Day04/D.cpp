#include <bits/stdc++.h>
 
typedef long long i64;
typedef unsigned long long u64;
 
 
const int MOD = 998244353;
const int MAXN = 201000;
 
 
int t;
u64 n;
bool arr[64];
bool arr1[64], arr2[64];
 
int main() {
     
    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
         
        std::scanf("%llu", &n);
        if(n % 3 == 0) std::printf("1 %llu\n", n);
        else {
             
            for(int i = 0; i < 64; ++i)
                arr[i] = n & (u64(1) << i);
            for(int i = 0; i < 64; ++i)
                arr1[i] = arr2[i] = 0;
             
            std::vector<int> pos[2] = {};
            for(int i = 0; i < 64; ++i)
                if(arr[i]) pos[i & 1].push_back(i);
             
            int s0 = pos[0].size(), s1 = pos[1].size();
             
            if(s0 > s1) std::swap(pos[0], pos[1]), std::swap(s0, s1);
                 
            if(s0 == 0) {
                 
                int c = s1 / 3 * 3;
                for(int i = 0; i < c; ++i)
                    arr1[pos[1][i]] = 1;
                for(int i = 0; i < c; ++i)
                    arr2[pos[1][s1 - i - 1]] = 1;
                 
            } else {
                 
                if(s0 == 1 && s1 % 3 == 2) {
                     
                    arr1[pos[0][0]] = arr1[pos[1][0]] = 1;
                    arr2[pos[0][0]] = 1;
                    for(int i = 1; i < s1; ++i)
                        arr2[pos[1][i]] = 1;
                     
                } else {
                     
                    for(int i = 0; i < s0; ++i)
                        arr1[pos[0][i]] = arr1[pos[1][i]] = 1;
                    for(int i = s1 % 3; i < s1; ++i)
                        arr2[pos[1][i]] = 1;
                     
                }
                 
            }
             
            u64 a = 0, b = 0;
            for(int i = 0; i < 63; ++i)
                a |= u64(arr1[i]) << i, b |= u64(arr2[i]) << i;
            if(a % 3 || b % 3 || (a | b) != n) { std::cerr << "Error!" << std::endl; *(int*)0 = 0; }
            std::printf("2 %llu %llu\n", a, b);
             
        }
         
    }
     
}