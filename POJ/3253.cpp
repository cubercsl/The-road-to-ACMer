// Fence Repair, POJ3253

/*Sample Input
3
8
5
8
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
    long long ans = 0;
    cin >> n;
    while (n--)
    {
        int p;
        cin >> p;
        q.push(p);
    }
    while (q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        int tmp = a + b;
        q.push(tmp);
        ans += a + b;
    }
    cout << ans << endl;
    return 0;
}
