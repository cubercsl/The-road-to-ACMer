#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[] = "STEED";
    int n;
    while (cin >> n)
    {
        sort(str, str + 5);
        while (--n)
            next_permutation(str, str + 5);
        cout << str << endl;
    }
    return 0;
}
