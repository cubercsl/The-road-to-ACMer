#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int x = 0;
        vector<int> vec;
        for (int i = 0, a, b; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            vec.push_back(a);
            if (b) x++;
        }
        sort(vec.begin(), vec.end(), greater<int>());
        x = min(x, m);
        double ans = 0;
        for (int i = 0; i < x; i++) ans += vec[i] * 0.5;
        for (int i = x; i < n; i++) ans += vec[i];
        printf("%.1f\n", ans);
    }
}