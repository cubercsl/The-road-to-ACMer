#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<point> vec;
        for (int i = 0, x, y; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            vec.emplace_back(x, y);
        }
        sort(vec.begin(), vec.end());
        int m = n >> 1;
        int x1 = vec[m - 1].first, y1 = vec[m - 1].second;
        int x2 = vec[m].first, y2 = vec[m].second;
        if (x1 != x2)
        {
            printf("%d %d %d %d\n", x1, -1000000000, x2, 1000000000);
        }
        else
        {
            printf("%d %d %d %d\n", x1 - 1, y1 + 1000000, x2 + 1, y2 - 1000000);
        }
    }
}