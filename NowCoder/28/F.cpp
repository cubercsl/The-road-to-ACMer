#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 1000; i <= 9999; i++)
    {
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        cout << s << t << endl;
    }
    return 0;
}
