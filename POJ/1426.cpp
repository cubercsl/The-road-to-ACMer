// Find The Multiple, POJ1426

/*Sample Input
2
6
19
0
*/

#include <iostream>
using namespace std;

bool flag;

void dfs(int n, unsigned long long k, int len)
{
    if (flag || len == 19)
        return;
    if (k % n == 0)
    {
        flag = 1;
        cout << k << endl;
        return;
    }
    dfs(n, k * 10, len + 1);
    dfs(n, k * 10 + 1, len + 1);
    return;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        flag = 0;
        dfs(n, 1, 0);
    }
}