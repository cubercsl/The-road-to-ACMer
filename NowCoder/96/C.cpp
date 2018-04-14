#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        double a, b, k;
        cin >> a >> b >> k;
        cout << fixed << setprecision(3) << b / (a + b) << endl;
    }
}