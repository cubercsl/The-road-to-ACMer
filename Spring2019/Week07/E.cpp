#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+5;
using ll = long long ;
bool nop[maxn];

void init(){
    nop[0] = nop[1] = 1;
    for(ll i=2;i<maxn;i++){
        if(nop[i] == 0)
        for(ll j=i;j*i < maxn;j++){
            nop[i*j] = 1;
        }
    }
}

ll gcd(ll a, ll b){
    if(b)
        while((a %= b) &&(b %= a));
    return a + b;
}
int readMagic() {

    char str[100];
    std::scanf("%s", str);
    int len = std::strlen(str);
    int index = 0;
    while(str[index] && str[index] != '.') ++index;
    if(index < len) {

        int a, b;
        std::sscanf(str, "%d.%d", &a, &b);
        for(int i = 0; i < 5 - (len - index - 1); ++i)
            b *= 10;
        return a * 100000 + b;

    } else {

        int a;
        std::sscanf(str, "%d", &a);
        return a * 100000;

    }

}
int main(){
    init();
    int n;
    scanf("%d",&n);
    for(int test = 0; test < n; ++test) {

        int a = readMagic(), b = readMagic();
        if(a == b) std::puts("2 2");
        else {
            int d = gcd(a,b);
            a /= d;
            b /= d;
            if(nop[a] == 0 && nop[b] == 0){
                printf("%d %d\n",a,b);
            }
            else puts("impossible");
        }
    }
}