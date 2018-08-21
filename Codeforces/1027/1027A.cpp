#include <bits/stdc++.h>
using namespace std;

bool judge(char s, char t)
{
    return (s == t) || (s + 1 == t - 1) || (s - 1 == t + 1);
}

bool judge(const string& s)
{
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (!judge(s[i], t[i])) return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (judge(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}