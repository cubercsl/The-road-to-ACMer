#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        if (a <= 120)
        {
            cout << 0 << endl;
            continue;
        }
        cout << ceil((a - 120) * 1.0 / b) << endl;
    }
    return 0;
}
