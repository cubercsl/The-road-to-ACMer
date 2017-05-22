// All in All, UVa 10340

/*Sample Input
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    string t;
    while (cin >> s >> t)
    {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length())
        {
            if (s[i] == t[j])
                i++, j++;
            else
                j++;
        }
        if (s.length() == i)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
