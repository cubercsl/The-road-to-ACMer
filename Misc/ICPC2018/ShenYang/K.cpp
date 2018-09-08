#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isp(int x)
{
    if (x == 1) return true;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

bool ok(int x)
{
    vector<int> d;
    do
        d.push_back(x % 10);
    while (x /= 10);
    int n = d.size();
    reverse(d.begin(), d.end());
    for (int i = 0; i < (1 << n); i++)
    {
        int c = 0;
        for (int j = 0; j < n; j++)
            if (i >> j & 1) c = c * 10 + d[j];
        if (!isp(c)) return false;
    }
    return true;
}

int main()
{
    vector<int> a;
    for (int i = 1; i <= 1000000; i++)
    {
        if (ok(i)) a.push_back(i);
    }
    int T, kase = 0;
    cin >> T;
    while (T--)
    {
        string n;
        cin >> n;
        cout << "Case #" << ++kase << ": ";
        a.push_back(10000);
        if (n.size() < 4)
        {
            int x = stoi(n);
            for (int i = 0;; i++)
                if (a[i] > x)
                {
                    cout << a[i - 1] << "\n";
                    break;
                }
        }
        else
        {
            cout << "317\n";
        }
    }
}