#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[22];
    set<long long> s;
    while (cin >> n)
    {
        s.clear();
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int cnt = 1 << n;
        for (int i = 0; i < cnt; i++)
        {
            long long sum = 0;
            for (int j = 0; j < n; j++)
            {
                int sig = i >> j & 1;
                sum += a[j] * (sig ? 1 : -1);
            }
            s.insert(sum);
        }
        cout << s.size() << endl;
    }
    return 0;
}
