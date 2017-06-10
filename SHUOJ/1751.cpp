#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 32;
int main()
{
    int n, target[MAXN];
    while (cin >> n)
    {
        stack<int> s;
        int a = 1, b = 1;
        for (int i = 1; i <= n; i++)
            cin >> target[i];
        bool flag = 1;
        while (b <= n)
        {
            if (a == target[b])
                a++, b++;
            else if (!s.empty() && s.top() == target[b])
            {
                s.pop();
                b++;
            }
            else if (a <= n)
                s.push(a++);
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
