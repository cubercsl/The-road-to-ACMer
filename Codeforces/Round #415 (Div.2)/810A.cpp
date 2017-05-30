#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        double sum = 0;
        int score;
        for (int i = 0; i < n; i++)
        {
            cin >> score;
            sum += score;
        }
        int ans = 0;
        while ((sum + ans * k) / (n + ans) + 0.5 < k)
            ans++;
        cout << ans << endl;
    }
    return 0;
}
