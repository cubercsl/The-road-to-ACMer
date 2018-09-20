#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll l, r;
    cin >> l >> r;
    cout << "YES\n";
    for (ll i = l; i <= r; i += r)
        cout << i << " " << i + 1 << '\n';
}