#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> PII;
const double eps = 1e-6;
 
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    k = n - k;
    vector<int> s(n), c(n);
    for (auto& t : s) scanf("%d", &t);
    for (auto& t : c) scanf("%d", &t);
    vector<double> f(n);
    for (int i = 0; i < n; i++) c[i] *= s[i];
    double l = 0, r = 2e3;
    while(fabs(r - l) > eps)
    {
        double m = (l + r) / 2;
        for (int i = 0; i < n; i++) f[i] = c[i] - m * s[i];
        sort(f.begin(), f.end(), greater<double>());
        double sum = 0;
        for (int i = 0; i < k; i++) sum += f[i];
        if (sum > 0)
            l = m;
        else
            r = m;
    }
    printf("%.10f\n", l);
}