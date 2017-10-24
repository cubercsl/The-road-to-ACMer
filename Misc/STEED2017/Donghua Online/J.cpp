#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int cnt = 0;
        do
            cnt += n % 2;
        while (n >>= 1);
        cout << cnt << endl;
    }
    return 0;
}
