#include <bits/stdc++.h>
using namespace std;

int solve(int ta, int tb)
{
    int ans;
    int a[3], b[3];
    a[0] = ta % 10;
    a[1] = ta / 10 % 10;
    a[2] = ta / 100;
    b[0] = tb % 10;
    b[1] = tb / 10 % 10;
    b[2] = tb / 100;
    ans = a[0] - b[0] + 19 * (a[1] - b[1]) + 199 * (a[2] - b[2]);
    return ans;
}

int main()
{
    int numa, numb;
    int t;
    int kase=0;
    cin >> t;
    while (t--)
    {
        cin >> numa >> numb;
        int ans = 0;
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++)
            ans = max(ans, solve(numa + i, numa) + solve(numb + n - i, numb));
        cout <<"Case "<<++kase<<": "<< ans << endl;
    }
    return 0;
}
