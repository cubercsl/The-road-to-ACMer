#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
long long ans[22] = {1, 0};
void init()
{
    for (int i = 2; i < 21; i++)
        ans[i] = (i - 1) * (ans[i - 2] + ans[i - 1]);
}

int main()
{
    init();
    int n;
    while (cin >> n)
        cout << ans[n] << endl;
    return 0;
}
