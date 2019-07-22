#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Pow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

ll dfs(ll n, ll a)
{
    if (a == 1) return n;
    return Pow(n, dfs(n, a - 1));
}

int main()
{
    /* 
    int n,a;
    while(cin >> n >> a){
        cout << dfs(n,a) << endl;
    }
    */
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n, a, m, b;
        scanf("%lld%lld%lld%lld", &n, &a, &m, &b);
        if (n == m)
        {
            if (n == 1 || a == b)
                puts("=");
            else
            {
                if (a > b)
                    puts(">");
                else
                    puts("<");
            }
            continue;
        }
        if(n == 1 || m == 1){
            if(n == 1) puts("<");
            else puts(">");
            continue;
        }
        if(a == b){
            if(n > m) puts(">");
            else puts("<");
            continue;
        }

        if(n > m){
            swap(n,m);
            swap(a,b);
        }
        if(a <= b){
            puts("<");
            continue;
        }
        if(b == 1){
            if(n == 2 && m == 4 && a == 2) puts("=");
            else puts(">");
            continue;
        }
        if(a - b == 1){
            if(n == 2){
                if(m == 3){
                    if(a == 2) puts(">");
                    else puts("<");
                } else if(m == 4){
                    if(a == 2) puts("=");
                    else puts("<");
                } else puts("<");
            } else{
                puts(">");
            }
            continue;
        }
        if(a - b == 2){
            if(n == 2 && m == 3){
                if(a == 3) puts(">");
                else puts("<");
            } else puts(">");
            continue;
        }
        puts(">");
    }
}