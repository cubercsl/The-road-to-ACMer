#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int base = 1;
        while (true)
        {
            if (a < base)
            {
                cout << "Vladik" << endl;
                break;
            }
            a -= base++;
            if (b < base)
            {
                cout << "Valera" << endl;
                break;
            }
            b -= base++;
        }
    }
    return 0;
}
