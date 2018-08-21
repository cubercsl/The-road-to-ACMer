#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        vector<int> v(n);
        for (auto& t : v) scanf("%d", &t);
        sort(v.begin(), v.end());
        int ans = -1;
        for (int i = 2; i < n; i++)
        {
            if (v[i] < v[i - 1] + v[i - 2])
                ans = max(ans, v[i] + v[i - 1] + v[i - 2]);
        }
        printf("%d\n", ans);
    }
}