#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1 << 17;
char buf[N];

struct Node
{
    string name;
    int p, c, t, r;
    Node() {}
    Node(const char* s)
    {
        p = c = t = r = 0;
        int i = 0;
        for (i = 0; s[i]; i++)
        {
            if (s[i] != ',')
                name.push_back(s[i]);
            else
                break;
        }
        i++;
        for (; s[i]; i++)
        {
            if (s[i] == ',') break;
            p = p * 10 + s[i] - '0';
        }
        i++;
        for (; s[i]; i++)
        {
            if (s[i] == ',') break;
            c = c * 10 + s[i] - '0';
        }
        i++;
        for (; s[i]; i++)
        {
            if (s[i] == ',') break;
            t = t * 10 + s[i] - '0';
        }
        i++;
        for (; s[i]; i++)
        {
            if (s[i] == ',' || s[i] == '\n') break;
            r = r * 10 + s[i] - '0';
        }
    }
};
vector<string> an[N];
ll floor(int a, int b) { return (a + b - 1) / b; }
int main()
{
    int l, m;
    scanf("%d%d", &l, &m);
    getchar();
    vector<Node> vec;
    for (int i = 0; i < m; i++)
    {
        fgets(buf, N, stdin);
        vec.emplace_back(buf);
    }
    int lim = N;
    for (auto& [name, p, c, t, r] : vec)
    {
        double tmp = 1.0 * l / (c * t) * (t + r);
        if (tmp <= 10080 && p <= lim)
        {
            an[p].emplace_back(name);
            lim = p;
        }
    }
    if (lim == N)
        puts("no such mower");
    else
        for (auto& v : an[lim])
            printf("%s\n", v.c_str());
}