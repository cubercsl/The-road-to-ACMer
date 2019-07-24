#include <cassert>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>

#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

//#include <random>
//#include <unordered_map>


typedef long long i64;


const int MOD = 1000003;

int n;
int arr[MOD];

int main() {
    
    arr[0] = 1;
    for(int i = 1; i < MOD; ++i)
        arr[i] = i64(arr[i - 1]) * i % MOD;
    while(~std::scanf("%d", &n))
        std::printf("%d\n", n < MOD ? arr[n] : 0);
    
}
