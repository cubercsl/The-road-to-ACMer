#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int rev(int n)
{
    return n % 10 * 10 + n / 10;
}

int main()
{
    int h, d;
    while (scanf("%d:%d", &h, &d) != EOF)
    {
        int cnt=0;
        while(rev(h)!=d)
        {
            d++,cnt++;
            if(d==60)
                d=0,h++;
            if(h==24)
                h=0;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
