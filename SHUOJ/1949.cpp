#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int f[7] = {1, 3, 27, 356684, 1010249, 713667, 525919};
// 欧拉定理计算后打表
int main()
{
    int t;
    int n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        n > 6 ? cout << f[6] : cout << f[n];
        cout << endl;
    }
    return 0;
}
