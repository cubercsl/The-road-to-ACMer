#include <bits/stdc++.h>
using namespace std;
 
char a[242];
bool judge(int i)
{
    return a[i] > a[i + 1];
}
 
void del()
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (judge(i))
        {
            for (int j = i; j < strlen(a); j++)
                a[j] = a[j + 1];
            break;
        }
    }
}
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> a >> n;
        while (n--)
            del();
        // 去除前导0
        bool flag = 0;
        bool flag2 = 0;
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] != '0')
            {
                cout << a[i];
                flag = 1;
                flag2 = 1;
            }
            else if (flag)
            {
                cout << a[i];
                flag2 = 1;
            }
        }
        if (!flag2)
            cout << "0";
        cout << endl;
    }
    return 0;
}
