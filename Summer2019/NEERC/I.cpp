#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int a[maxn],b[maxn];

int main(){
    int n;
    cin >> n;

    cout << "? " << n;
    for(int i=1;i<=n;i++) cout << " " << i;
    cout << endl;

    int m;
    cin >> m;
    for(int i=1;i<=m;i++) cin >> a[i];

    cout << "? " << n;
    for(int i=n;i>=1;i--) cout << " " << i;
    cout << endl;

    cin >> m;
    for(int i=1;i<=m;i++) cin >> b[i];

    cout << "!";
    int l = 1, r = m;
    for(int i=1;i<=n;i++){
        int beg = r;
        while(r > 0){
            if(b[r] == a[l]) break;
            r--;
        }
        cout << ' ' << beg - r + 1;
        for(int j=r;j<=beg;j++) cout << ' ' << b[j];
        r--;
        l += beg - r;
    }
    cout << endl;
}