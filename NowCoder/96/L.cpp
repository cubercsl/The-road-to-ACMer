#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    while (T--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        vector<int> v(n);
        for (auto& t : v) cin >> t;
        string flag = "Yes";
        for (auto& t : v)
        {
            while (t > 1 && b) b--, t -= 2;
            while (t && a) a--, t--;
            while (t && b) b--, t--;
            if (t) flag = "No";
        }
        cout << flag << endl;
    }
    return 0;
}