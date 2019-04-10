#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        ++a;
        string op;
        while (a <= b)
        {
            int m = a + b >> 1;
            cout << m << endl;
            cin >> op;
            if (op == "TOO_SMALL")
                a = m + 1;
            else if (op == "TOO_BIG")
                b = m - 1;
            else if (op == "CORRECT")
                break;
            else
                assert(false);
        }
    }
}