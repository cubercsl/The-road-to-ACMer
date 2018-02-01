#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        n *= 2;
        char cmd[10];
        int num;
        int now = 1;
        int cnt = 0;
        stack<int> s;
        while (n--)
        {
            scanf("%s", cmd);
            if (cmd[0] == 'a')
            {
                scanf("%d", &num);
                s.push(num);
            }
            else if (!s.empty())
            {
                if (s.top() == now)
                {
                    s.pop();
                    now++;
                }
                else
                {
                    now++;
                    cnt++;
                    while (!s.empty())
                        s.pop();
                }
            }
            else
                now++;
        }
        cout << cnt << endl;
    }
}
