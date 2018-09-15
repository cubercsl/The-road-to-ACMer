#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        for (auto& t : s)
            if (t >= 'A' && t <= 'Z') t = t - 'A' + 'a';
        if (s == "jessie")
            cout << "Good guy!\n";
        else
            cout << "Dare you say that again?\n";
    }
}
