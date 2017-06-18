// The 3n + 1 problem, UVa100

/*Sample Input
1  10
100  200
201  210
900  1000
*/

#include <bits/stdc++.h>
using namespace std;

int np(int n)
{
    int cnt = 1;
    while (n != 1)
    {
        if (n % 2)
            n = 3 * n + 1;
        else n /= 2;
        cnt++;
    }
    return cnt;
}

int main()
{
    int be, en;
    while (cin >> be >> en)
    {
        cout << be << " " << en << " " ;
        if (en < be)
            swap(en, be);
        int ans = 0;
        for (int i = be; i <= en; i++)
            ans = max(ans, np(i));
        cout << ans << endl;
    }
    return 0;
}
