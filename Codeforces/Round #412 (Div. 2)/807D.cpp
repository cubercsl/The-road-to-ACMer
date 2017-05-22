#include <bits/stdc++.h>
using namespace std;

int n;
int a[120][5];
int solve[5];
int cheat[5];

int cal(int time, int ac, int total)
{
    if (time == -1)
        return 0;
    if (2 * ac > total)
        return 2 * (250 - time);
    if (4 * ac > total)
        return 4 * (250 - time);
    if (8 * ac > total)
        return 6 * (250 - time);
    if (16 * ac > total)
        return 8 * (250 - time);
    if (32 * ac > total)
        return 10 * (250 - time);
    return 12 * (250 - time);
}

bool check(int k)
{
    for (int i = 0; i < 5; i++)
        cheat[i] = solve[i];
    for (int i = 0; i < 5; i++)
        if (a[0][i] != -1)
        {
            if (a[1][i] == -1)
                continue;
            else if (a[0][i] > a[1][i])
                cheat[i] += k;
        }
    int vasya = 0, petya = 0;
    for (int i = 0; i < 5; i++)
    {
        vasya += cal(a[0][i], cheat[i], n + k);
        petya += cal(a[1][i], cheat[i], n + k);
    }
    return vasya > petya;
}

int main()
{
    bool flag = 0;
    while (cin >> n)
    {
        memset(a, 0, sizeof(a[0][0]) * 120 * 5);
        memset(solve, 0, sizeof(solve));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
            {
                cin >> a[i][j];
                if (a[i][j] != -1)
                    solve[j]++;
            }
        for (int i = 0; i < 33 * n; i++)
            if (check(i))
            {
                cout << i << endl;
                flag = 1;
                break;
            }
        if (!flag)
            cout << -1 << endl;
    }
    return 0;
}
