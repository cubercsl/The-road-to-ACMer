#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int mod = 1e9+7;
map<int,int> val[30];
char s[maxn];
int a[30],b[30];
long long hexi[maxn];
void init(){
    hexi[0] = 1;
    for(int i=1;i<maxn;i++){
        hexi[i] = hexi[i-1] *26 % mod;
    }
}
bool cmp(int x,int y){
    auto px = val[x].rbegin();
    auto py = val[y].rbegin();
    while(px != val[x].rend() && py != val[y].rend()){
        while(px != val[x].rend() && px->second == 0) px++;
        while(py != val[y].rend() && py->second == 0) py++;
        if(px->first == py->second) {
            if(px->second == py->second) continue;
            return px->second >py->second;
        }
        return px->first > py->first;
    }
    if(px != val[x].rend()) return false;
    return true;
}

int main(){
    init();
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<26;i++) val[i].clear();
        for(int i=0;i<n;i++){
            scanf("%s",s);
            int len = strlen(s);
            for(int i=len-1;i>=0;i--) {
                int t = len - i - 1;
                val[s[i]-'a'][t] ++;
                while(val[s[i]-'a'][t] == 26){
                    val[s[i]-'a'][t] = 0;
                    t++;
                    val[s[i]-'a'][t]++;
                }
            }
        }
        for(int i=0;i<26;i++) a[i] = i;
        
        sort(a,a+26,cmp);
        for(int i=0;i<26;i++) printf("%d\n",a[i]);
        for(int i=0;i<26;i++) b[a[i]] = 25-i;
        long long sum = 0;
        for(int i=0;i<26;i++){
            for(auto &v:val[i]){
                sum = (sum + hexi[v.first] * v.second % mod) % mod;
            }
        }
        printf("%lld\n",sum);
    }

}