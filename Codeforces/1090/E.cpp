#include <bits/stdc++.h>
using namespace std;

int id[8][8] = {1, 28, 7, 18, 3, 26, 9, 24,
                6, 19, 2, 27, 8, 23, 12, 15,
                29, 64, 21, 4, 17, 14, 25, 10,
                20, 5, 30, 63, 22, 11, 16, 13,
                45, 48, 43, 54, 31, 62, 37, 52,
                42, 57, 46, 49, 36, 53, 32, 61,
                47, 44, 55, 40, 59, 34, 51, 38,
                56, 41, 58, 35, 50, 39, 60, 33};

bool f[64], g[64];

int dic[64];

string decode(int pos)
{
    int x = pos / 8;
    int y = pos % 8;
    string s = {(char)('a' + y), (char)('1' + x)};
    return s;
}

int main()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) id[i][j]--;
    for (int i = 0; i < 64; i++) dic[id[i / 8][i % 8]] = i;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int x = s[1] - '1';
        int y = s[0] - 'a';
        f[id[x][y]] = true;
    }
    for (int i = 0; i < n; i++) g[id[i / 8][i % 8]] = true;
    vector<pair<int, int>> ans;
    bool flag = true;
    for (; flag;)
    {
        flag = false;
        for (int i = 0; i < 64; i++)
        {
            if (f[i] == true && g[i] == false)
            {
                for (int j = i;; (++j) %= 64)
                {
                    if (f[j] == true && f[(j + 1) % 64] == false)
                    {
                        flag = true;
                        ans.emplace_back(j, (j + 1) % 64);
                        f[j] = false;
                        f[(j + 1) % 64] = true;
                        break;
                    }
                }
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto& t : ans)
        cout << decode(dic[t.first]) << '-' << decode(dic[t.second]) << '\n';
}
