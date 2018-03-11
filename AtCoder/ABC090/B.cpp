#include <bits/stdc++.h>
using namespace std;

bool check(int x)
{
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main()
{
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i++)
        ans += check(i);
    cout << ans << endl;
}