#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        ++n;
        vector<int> s(n), v(n), l(n);
        for (auto& t : l) scanf("%d", &t);
        for (auto& t : s) scanf("%d", &t);
        for (auto& t : v) scanf("%d", &t);
        double ans = 0; 
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i) sum += l[i];
            ans = max(ans, (sum + s[i]) * 1.0 / v[i]);
        }
        printf("%.10f\n", ans);
    }
}