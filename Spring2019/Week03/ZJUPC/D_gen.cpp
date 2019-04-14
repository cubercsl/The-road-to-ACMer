#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{

    std::string ans;
    for (int c = 0; c <= 2; ++c)
        for (int u = 0; u <= 2; ++u)
            for (int d = 0; d <= 2; ++d)
                for (int l = 0; l <= 2; ++l)
                    for (int r = 0; r <= 2; ++r)
                    {

                        char op = 'I';
                        if (c != 1)
                        {

                            if (c == 2)
                                op = 'P';
                            else if (r == 2)
                                op = 'R';
                            else if (u == 2)
                                op = 'U';
                            else if (l == 2)
                                op = 'L';
                            else if (d == 2)
                                op = 'D';
                            else if (u == 1 && r == 0)
                                op = 'R';
                            else if (r == 1 && d == 0)
                                op = 'D';
                            else if (d == 1 && l == 0)
                                op = 'L';
                            else if (l == 1 && u == 0)
                                op = 'U';
                            else
                                op = 'R';
                        }
                        ans += op;
                    }

    registerGen(argc, argv, 1);
    println(1000);
    for (int t = 0; t < 1000; t++)
    {
        int n = 12, m = 12, k = 200;
        println(n, m, 2, 2, k);
        println(ans);
        vector<string> s(n);
        for (int i = 1; i < n - 1; i++) s[i] = "100000000001";
        s[0] = "111111111111";
        s[n - 1] = "111111111111";
        vector<pair<int, int>> vec;
        for (int i = 1; i <= 10; i++)
            for (int j = 1; j <= 10; j++)
                vec.emplace_back(i, j);
        shuffle(vec.begin(), vec.end());
        for (int i = 0; i < 50; i++)
        {
            int x, y;
            tie(x, y) = vec[i];
            s[x][y] = '2';
        }
        for (auto& t : s) println(t);
    }
}