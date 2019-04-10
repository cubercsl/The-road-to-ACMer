#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec;
    for (int i = 0; i < 30; i++) vec.push_back((1 << i) - 1);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int n;
        scanf("%d", &n);
        if (((n + 1) & n) == 0)
        {
            int ans = 1;
            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    ans = n / i;
                    break;
                }
            }
            printf("%d\n", ans);
        }
        else
        {
            printf("%d\n", *upper_bound(vec.begin(), vec.end(), n));
        }
    }
}