#include <bits/stdc++.h>
using namespace std;

inline double dis(const pair<double, double>& a,
                  const pair<double, double>& b)
{
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    mt19937 rng(time(0));
    int n;
    cin >> n;
    if (n > 1000) return cout << 0 << endl, 0;
    time_t s = clock();

    double sum = 0;
    vector<pair<double, double>> vec;
    int m;
    while (clock() - s < 1.8 * CLOCKS_PER_SEC)
    {
        m++;
        vec.clear();
        for (int i = 0; i < n; i++)
            vec.emplace_back(rng() % 1000000 * 1.0 / 1000000, rng() % 1000000 * 1.0 / 1000000);
        double ans = 2;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                ans = min(ans, dis(vec[i], vec[j]));
        sum += ans;
    }
    cout << sum / m << endl;
}