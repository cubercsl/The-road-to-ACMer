#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll res;
    string line;
    getline(cin, line);
    cin >> res;
    stringstream ss1(line), ss2(line);
    stack<ll> stk;
    ll x;
    ss1 >> x;
    stk.push(x);
    char op;
    while (ss1 >> op)
    {
        ss1 >> x;
        if (op == '+') stk.push(x);
        else{
            ll tmp = stk.top();
            stk.pop();
            stk.push(x * tmp);
        }
    }
    ll ans1 = 0;
    while (stk.size())
    {
        ans1 += stk.top();
        stk.pop();
    }
    ll ans2 = 0;
    ss2 >> ans2;
    while(ss2 >> op){
        ss2 >> x;
        if (op == '+') ans2 = ans2 + x;
        else
            ans2 = ans2 * x;
    }
    if(ans1 == res){
        if(ans2 == res)
            cout << "U" << endl;
        else
            cout << "M" << endl;
    }
    else if(ans2 == res)
        cout << "L" << endl;
    else
        cout << "I" << endl;
}