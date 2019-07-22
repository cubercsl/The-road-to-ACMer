#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n)
        cout << (n * n + 11 * n) / 2 + 7 << '\n';
}