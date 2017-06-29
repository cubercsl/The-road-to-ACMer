#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> >q;
    int n;
    while (cin >> n)
    {
        int ans = 0;
        while (!q.empty())
            q.pop();
        while (n--)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        while (q.size() > 1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            int tmp = a + b;
            ans += tmp;
            q.push(tmp);
        }
        cout << ans << endl;
    }
    return 0;
}
