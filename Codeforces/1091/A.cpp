#include<bits/stdc++.h>
using namespace std;

int main()
{
    int y, b, r;
    cin >> y >> b >> r;
    int ans = 0;
    for (int i = 1; i <= y; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= r; k++)
                if(j == i + 1 && k == j + 1)
                    ans = max(ans, i + j + k);
    cout << ans << endl;
}