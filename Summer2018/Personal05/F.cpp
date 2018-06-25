#include <iostream>
#include <string>
using namespace std;

void go();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    go();
    return 0;
}

/****************************************************************************************************/

const int maxn = 1 << 20;
int ne[maxn];
void getfail(const string& s)
{
    int i, j, m = s.length();
    j = ne[0] = -1;
    i = 0;
    while (i < m)
    {
        while (j != -1 && s[i] != s[j])
            j = ne[j];
        ne[++i] = ++j;
    }
}

void print(int len)
{
    if (!ne[len]) return;
    print(ne[len]);
    cout << ne[len] << " ";
}

void go()
{
    string s;
    while (cin >> s)
    {
        getfail(s);
        print(s.length());
        cout << s.length() << endl;
    }
}
