#include <iostream>
using namespace std;

long long f(long long n)
{
    if (n < 20150001)
        return n + 2014;
    return 20152014;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}
