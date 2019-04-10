#include <bits/stdc++.h>
using namespace std;

int main()
{
    int b, k;
    cin >> b >> k;
    int ans = 0;
    for (int i = 0, x; i < k; i++)
    {
        cin >> x;
        ans = ans * b + x;
        ans %= 2;
    }
    if (ans)
        cout << "odd" << endl;
    else
        cout << "even" << endl;
}