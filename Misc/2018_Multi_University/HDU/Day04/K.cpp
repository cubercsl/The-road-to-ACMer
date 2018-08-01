#include <bits/stdc++.h>
using namespace std;

const int N = 505;
char s[N];

// 0 :op
// 1 :lead zero
// 2 :digit

bool ok(char* s)
{
    // 2*??0?*?
    // cerr << s << endl;
    int state = 0;
    for (int i = 0; s[i]; i++)
    {
        if (state == 0)
        {
            if (s[i] == '0')
                state = 1;
            else if (isdigit(s[i]))
                state = 2;
            else if (s[i] == '?')
                state = 2, s[i] = '1';
            else
                return false;
        }
        else if (state == 1)
        {
            if (s[i] == '+' || s[i] == '*')
                state = 0;
            else if (s[i] == '?')
                state = 0, s[i] = '+';
            else
                return false;
        }
        else
        {
            if (s[i] == '+' || s[i] == '*') state = 0;
            if (s[i] == '?') s[i] = '1';
        }
    }
    return state;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        puts(ok(s) ? s : "IMPOSSIBLE");
    }
}