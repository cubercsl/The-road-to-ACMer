#include <bits/stdc++.h>
using namespace std;

int solve(string& s)
{
    int a[3] = {0};
    for (auto& t : s)
    {
        if (isupper(t)) a[0]++;
        if (islower(t)) a[1]++;
        if (isdigit(t)) a[2]++;
    }
    if (a[0] && a[1] && a[2]) return cout << s << endl, 0;
    if (a[0] && a[1])
    {
        if (a[0] > 1)
        {
            for (auto& t : s)
            {
                if (isupper(t))
                {
                    t = '0';
                    cout << s << '\n';
                    return 0;
                }
            }
        }
        if (a[1] > 1)
        {
            for (auto& t : s)
            {
                if (islower(t))
                {
                    t = '0';
                    cout << s << '\n';
                    return 0;
                }
            }
        }
    }
    if (a[0] && a[2])
    {
        if (a[0] > 1)
        {
            for (auto& t : s)
            {
                if (isupper(t))
                {
                    t = 'a';
                    cout << s << '\n';
                    return 0;
                }
            }
        }
        if (a[2] > 1)
        {
            for (auto& t : s)
            {
                if (isdigit(t))
                {
                    t = 'a';
                    cout << s << '\n';
                    return 0;
                }
            }
        }
    }
    if (a[1] && a[2])
    {
        if (a[1] > 1)
        {
            for (auto& t : s)
            {
                if (islower(t))
                {
                    t = 'A';
                    cout << s << '\n';
                    return 0;
                }
            }
        }
        if (a[2] > 1)
        {
            for (auto& t : s)
            {
                if (isdigit(t))
                {
                    t = 'A';
                    cout << s << '\n';
                    return 0;
                }
            }
        }
    }
    if (a[0])
    {
        cout << "a0" << s.substr(2) << '\n';
        return 0;
    }
    if (a[1])
    {

        cout << "A0" << s.substr(2) << '\n';
        return 0;
    }
    if (a[2])
    {

        cout << "Aa" << s.substr(2) << '\n';
        return 0;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        solve(s);
    }
}