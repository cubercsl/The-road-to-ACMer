#include <bits/stdc++.h>
using namespace std;

string t1 = "lansou", t2 = "xianggu";
int main()
{
    string buf;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> buf;
        if (buf == t1)
            cout << t2 << endl;
        else
            cout << t1 << endl;
    }
    return 0;
}
