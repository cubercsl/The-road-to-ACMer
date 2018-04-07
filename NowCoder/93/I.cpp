#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int k, n;
        scanf("%d%d", &n, &k);
        vector<pair<int, int> > v(n);
        double l = 0, r = 0;
        for (auto& t : v) scanf("%d%d", &t.first, &t.second), r = max(r, t.second * 1.0 / t.first);
        while (r - l > eps)
        {
            double m = (l + r) / 2;
            sort(v.begin(), v.end(), [m](const pair<int, int>& x, const pair<int, int>& y) {
                return x.second - x.first * m > y.second - y.first * m;
            });
            double s = 0;
            for (int i = 0; i < k; i++) s += v[i].second - v[i].first * m;
            s < 0 ? r = m : l = m;
        }
        printf("%.2f\n", l);
    }
    return 0;
}
