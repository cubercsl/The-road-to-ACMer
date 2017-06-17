// Yogurt factory, POJ2393

/*Sample Input
4 5
88 200
89 400
97 300
91 500
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, s;
    int mc = 0x3f3f3f3f;
    long long ans = 0;
    cin >> n >> s;
    while (n--)
    {
        int c, y;
        cin >> c >> y;
        mc = min(c, mc + s);
        ans += mc * y;
    }
    cout << ans << endl;
    return 0;
}
