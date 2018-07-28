#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

int main()
{
    rope<int> T;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) T.push_back(i + 1);
    while (m--)
    {
        int p, s;
        scanf("%d%d", &p, &s);
        p--;
        T = T.substr(p, s) + T.substr(0, p) + T.substr(p + s, n - p - s);
    }
    for (int i = 0; i < n; i++) printf("%d ", T.at(i));
    return 0;
}