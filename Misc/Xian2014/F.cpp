#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e6+5;
int n,m,k;
ll inv[maxn],c[maxn];
void INV()
{
    inv[1]=1;
    for(int i=2;i<=1e6;i++)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
}

ll Pow(ll a,ll n)
{
    ll t=1;
    for (;n;n>>=1,a=(a*a%mod))
        if(n&1) t=(t*a%mod);
    return t;
}

void cal(ll n)
{
    c[0]=1;
    for(int i=1;i<=k;i++)
        c[i]=((c[i-1]*(n-i+1)%mod)*inv[i]%mod)%mod;
}

int main()
{
    int T,kase=0;
    INV();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        cal(k);
        ll ans=0;
        int s=1;
        for(int i=k;i>=1;i--,s=-s)
            ans=(ans%mod+(s*i*Pow(i-1,n-1))%mod*c[i]%mod+mod)%mod;
        cal(m);
        printf("Case #%d: %lld\n",++kase,(ans%mod*c[k]%mod)%mod);

    }
}