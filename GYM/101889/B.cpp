#include<bits/stdc++.h>
using namespace std;
map<char,int> yuan = {{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};
int main(){
    string line;
    while(cin >> line){
        int x = 0;
        for(auto c:line) 
            x += (yuan[c] == 1);
        if(yuan[line[0]] == 0){
            if(!x) cout << 1<< endl;
            else cout << 0 << endl;
            continue;
        }        
        int cnt = (x + 1) / 2;
        // cerr << cnt << endl;
        int ans = 0;
        for(auto c:line){
            if(yuan[c]) cnt--;
            if(cnt == 0) ans++;
        } 
        cout << ans << endl;
    }
}