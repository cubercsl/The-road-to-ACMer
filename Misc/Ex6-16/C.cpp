#include <iostream>
using namespace std;

int main()
{
    long long fact[11];
    fact[0] = 1;
    for (int i = 1; i <= 10; i++)
        fact[i] = fact[i - 1] * i;
    int n;
    while (cin >> n)
    {
        cout << fact[n] << endl;
    }
    return 0;
}
