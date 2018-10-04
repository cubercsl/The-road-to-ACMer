#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int sg[N];

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        memset(sg, -1, sizeof(sg));
        sg[0] = 0;
        for (int i = 0; i < a; i++) sg[i] = 0;
        for (int i = b + 1; i < N; i++)
        {
            set<int> s;
            for (int j = a; j <= b; j++)
            {
                if (i - j >= a && i - j <= b) continue;
                if (i - j < 0) continue;
                s.insert(sg[i - j]);
            }
            int x = 0;
            for (; s.find(x) != s.end(); x++)
                ;
            sg[i] = x;
        }
        for (int i = 0; i < N; i++) cout << i << ": " << sg[i] << endl;
    }
}