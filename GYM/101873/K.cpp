#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    string name;
    ll val;
    bool operator<(const Node& A) const
    {
        return val > A.val;
    }
};
const int maxn = 1e4 + 5;
Node a[maxn];
int main()
{
    int n, d, k;
    cin >> n >> d >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].val;
    }
    sort(a, a + n);
    ll tmp = 0;
    int pos = -1;
    for (int i = 0; i < k && i < n; i++)
    {
        tmp += a[i].val;
        if (tmp >= d)
        {
            pos = i;
            break;
        }
    }
    if(pos == -1){
        cout << "impossible" << endl;
    }
    else{
        cout << pos + 1 << endl;
        for(int i=0;i<=pos;i++){
            cout << a[i].name << ", YOU ARE FIRED!" << endl;
        }
    }
}