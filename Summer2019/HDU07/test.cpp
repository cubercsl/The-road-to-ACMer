#include <bits/stdc++.h>
using namespace std;

int main()
{
    auto isp = [](int x) {
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    };
    int ans = 0;
    for (int i = 20; i <= 500; i++) 
        if (isp(i)) ans++;
    cout << ans << endl;
}