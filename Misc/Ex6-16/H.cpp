#include <iostream>
using namespace std;

int a[22];
bool flag;
int sum, n;
void dfs(int now, int dep)
{
    if (flag)
        return;
    if (now > sum)
        return;
    if (now == sum)
        flag = 1;
    for (int i = dep + 1; i < n; i++)
        dfs(now + a[i], i);
}

int main()
{
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0, -1);
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
