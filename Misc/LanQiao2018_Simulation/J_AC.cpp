#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        if ((n ^ m ^ k) & 1)
            cout << "win" << endl;
        else
            cout << "lose" << endl;
    }
}