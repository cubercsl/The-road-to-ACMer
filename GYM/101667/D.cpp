#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, int> vis;
int main()
{
    ll n;
    cin >> n;
    vis[n] = 1;
    bool f = false;
    while (n != 1)
    {
        ll tmp = 0;
        while(n){
            tmp += (n % 10) * (n % 10);
            n /= 10;
        }
        n = tmp;
        if(vis[n] == 1) {
            f = true;
            break;
        }
        vis[n] = 1;
    }
    if (f) cout << "UNHAPPY" << endl;
    else
        cout << "HAPPY" << endl;
}