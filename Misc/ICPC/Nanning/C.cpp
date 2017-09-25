// six sheep
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn  = 505;

int ans[maxn];
struct P{
    int id,mon,k;
    P (int id,int mon): id(id),mon(mon) {}
    bool operator < (P A) const{
        if(this->mon == A.mon){
            return this->id < A.id;
        }
        else return this->mon > A.mon;
    }
};
vector<P> peo;
int main(){
    /*
    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    #endif
    */
    std::ios::sync_with_stdio(false);

    int n,m;
    while(cin >> n >> m){
        memset(ans,0,sizeof(ans));

        for(int i=0;i<n;i++){
            peo.clear();
            int w;
            cin >> w;
            int num,mon;
            cin >> num;
            while(num != -1){
                cin >> mon;
                peo.push_back(P(num,mon));
                cin >> num;
            }
            if(peo.size() > 1){
                sort(peo.begin(),peo.end());
                if(peo[1].mon >= w){
                    int temp = peo[1].mon * 1.1;
                    ans[peo[0].id] += min(peo[0].mon,temp);
                }
                else if(peo[0].mon < w){
                    continue;
                }
                else{
                    int temp = w * 1.1;
                    ans[peo[0].id] += min(temp,peo[0].mon);
                }
            }
            else if(peo.size() == 1){
                if(peo[0].mon >= w){
                    int temp = w*1.1;
                    ans[peo[0].id] += min(temp,peo[0].mon);
                }
            }
        }
        int k;
        cin >> k;
        for(int i=0;i<k;i++){
            int num;
            cin >> num;
            cout << ans[num] << '\n';
        }
    }
}
