// Periodic Strings, UVa455

/*Sample Input
1
HoHoHo 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char s[100];
    cin >> n;
    while (n--)
    {

        cin >> s;
        for (int j, i = 1; i <= strlen(s); i++)
            if (strlen(s) % i == 0)
            {
                for (j = i; j < strlen(s); j++)
                    if (s[j] != s[j % i])
                        break;
                if (j == strlen(s))
                {
                    cout << i << endl;
                    break;
                }
            }
        if (n)
            cout << endl;
    }
    return 0;
}
