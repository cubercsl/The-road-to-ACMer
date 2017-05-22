#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h;
    double s;

    while (cin >> n >> h)
    {
        s = 0.5 * h;
        s /= 2.0;
        double t = n;
        s /= t;
        for (int i = 1; i <= n - 1; i++)
        {
            if (i != 1)
                cout << " ";
            cout << fixed << setprecision(11) << 2 * sqrt(h * i * s);
        }
        cout << endl;
    }
    return 0;
}
