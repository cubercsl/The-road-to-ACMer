#include<bits/stdc++.h>
using namespace std;
const int TIME_MAX = 43200;
const int maxn = 1e5+5;
typedef pair<int,int> pii;
pii a[maxn];

int main (){
    int n;
    while(~scanf("%d",&n)){
        int h,m,s;
        scanf("%d%d%d",&h,&m,&s);
        int now = h * 60 * 60 + m * 60 + s;
        now %= TIME_MAX;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&h,&m,&s);
            int tmp = h * 60 * 60 + m * 60 + s;
            tmp %= TIME_MAX;
            if(tmp >= now) a[i].first = tmp - now;
            else a[i].first = TIME_MAX - now + tmp;
            
            a[i].second = TIME_MAX - a[i].first;
        }
        int ans = 1e9;
        int shun = 0, ni = 0;
        for(int i=0;i<n;i++){
            shun = max(shun,a[i].first);
            ni = max(ni,a[i].second);
        }
        ans = min(shun,ni);
        pii t1(1e9,0),t2(0,1e9);

        for(int i=0;i<n;i++){
            if(a[i].first >= a[i].second){
                if(a[i].first - a[i].second < t1.first - t1.second) t1 = a[i];
            } else{
                if(a[i].second - a[i].first < t2.second - t2.first) t2 = a[i];
            } 
        }
        int tmp = min(t1.second, t2.first);
        ans = min(ans, t1.second + t2.first + tmp);
        printf("%.2f\n",ans * 6.0);
    }
}