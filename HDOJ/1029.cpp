// Ignatius and the Princess IV, HDU1029

/*Sample Input
5
1 3 2 3 3
11
1 1 1 1 1 5 5 5 5 5 5
7
1 1 1 1 1 1 1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int ans;
        int cnt = 0;
        while (n--)
        {
            int num;
            scanf("%d", &num);
            if (ans == num)
                cnt++;
            else if (cnt--);
            else
                ans = num, cnt = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
