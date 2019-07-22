#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a.begin(), a.end(), greater<int>());
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] - a[i] > k)
            {
                printf("%d\n", i);
                flag =true;
                break;
            }
        }
        if (!flag) printf("%d\n", n);
    }
}