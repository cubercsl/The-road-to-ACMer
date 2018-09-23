#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int cnt[maxn];
int main()
{
    int k, n;
    scanf("%d%d", &k, &n);
    for (int i = 1, x; i <= n; i++) scanf("%d", &x), cnt[x]++;
    int val = n % k;
    if (val == 0)
    {
        bool f = true;
        int ave = n / k;
        int a, b;
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= k; i++)
        {
            if(cnt[i] == ave + 1){
                a = i;
                c1++;
            }
            else if(cnt[i] == ave - 1){
                b = i;
                c2++;
            }
            else if(cnt[i] != ave){
                f = false;
                break;
            }
        }
        if (!f || c1 != 1 || c2 != 1) puts("*");
        else{
            printf("-%d +%d\n", a, b);
        }
    }
    else if(val == 1){
        bool f = true;
        int ave = n / k;
        int x;
        int c = 0;
        for (int i = 1; i <= k; i++)
        {
            if(cnt[i] == ave + 1){
                x = i;
                c++;
            }
            else if(cnt[i] != ave){
                f = false;
                break;
            }
        }
        if (!f || c != 1) puts("*");
        else{
            printf("-%d\n", x);
        }
    }
    else if(val == k - 1){
        int ave = (n + 1) / k;
        bool f = true;
        int x;
        int c = 0;
        for (int i = 1; i <= k; i++)
        {
            if(cnt[i] == ave - 1){
                x = i;
                c++;
            }
            else if(cnt[i] != ave){
                f = false;
                break;
            }
        }
        if (!f || c != 1) puts("*");
        else{
            printf("+%d\n", x);
        }
    }
    else{
        puts("*");
    }
    // int fuck;
    // scanf("%d", &fuck);
}