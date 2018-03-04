#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int r[N * N], c[N * N];
int dis[N * N];
int main()
{
    int h, w, d, num;
    cin >> h >> w >> d;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> num, r[num] = i, c[num] = j;
    for (int i = 1; i + d <= h * w; i++)
        dis[i] = abs(r[i + d] - r[i]) + abs(c[i + d] - c[i]);
    for (int i = 1; i + d <= h * w; i++)
        dis[i + d] += dis[i];
    // for (int i = 1; i <= h * w; i++)
        // cout << dis[i] << endl;
    int q;
    cin >> q;
    while (q--)
    {
        static int l, r;
        cin >> l >> r;
        l -= d, r -= d;
        cout << dis[max(0, r)] - dis[max(0, l)] << endl;
    }
    return 0;
}