#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    string s;
    cin >> s;
    long long ans = 1;
    for (auto& t : s)
    {
        if (t == 'i' || t == 'l' || t == 'L' || t == 'I')
            ans = (1LL * ans * 4) % mod;
        else if (t == '0' || t == 'o' || t == 'O')
            ans = (1LL * ans * 3) % mod;
        else if(isalpha(t))
            ans = (1LL * ans * 2) % mod;
    }
    cout << ans << endl;
    return 0;
}