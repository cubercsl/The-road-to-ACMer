// six sheep
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;

int main(){
    /*
    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    #endif
    */
    std::ios::sync_with_stdio(false);
    int tot = 0;
    int times = 0;
    int miss = 0;
    map<char,string> maps;
    string line;
    cin >> line;
    while(line != "END"){
        tot++;
        char c = line[line.size() - 2];
        line.erase(line.begin() + line.size() - 1);
        line.erase(line.begin() + line.size() - 1);
        // cout << c << ' ' << line << endl;
        if(maps[c] == line){
            cout << "Hit" << endl;
            times++;
        }
        else{
            cout << "Miss" << endl;
            maps[c] = line;
        }
        cin >> line;
    }
    double ans;
    if(tot == 0){
        ans = 0;
    }
    else
        ans = times*1.0 / tot * 100;
    cout <<  "Hit ratio = ";
    cout << fixed << setprecision(2) << ans  << "%" << endl;
    getchar();
}
