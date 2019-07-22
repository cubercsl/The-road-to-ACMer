#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans;
    int l = 0, r = 0;
    for(int i=0;i<s.size();i+=2){
        if(s[i] == '<'){
            if(r > 0){
                r--;
                ans.push_back(']');
            } else{
                l++;
                ans.push_back('[');
            }
        } else{
            if(l > 0){
                l--;
                ans.push_back(']');
            } else{
                r++;
                ans.push_back('[');
            }
        }
    }
    if(l == 0 && r == 0)
        cout << ans << endl;
    else cout << "Keine Loesung" << endl;
}