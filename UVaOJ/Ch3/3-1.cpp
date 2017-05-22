// Score, ACM/ICPC Seoul 2005, UVa1585

/*Sample Input
5
OOXXOXXOOO
OOXXOOXXOO
OXOXOXOXOXOXOX
OOOOOOOOOO
OOOOXOOOOXOOOOX
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char s[80];
        int cnt = 0, score = 0;
        cin >> s;
        for (int i = 0; i < strlen(s); i++)
            if (s[i] == 'O')
                score += ++cnt;
            else
                cnt = 0;
        cout << score << endl;
    }
    return 0;
}
