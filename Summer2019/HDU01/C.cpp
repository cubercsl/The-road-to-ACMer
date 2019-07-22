#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


namespace io
{
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline void rnext()
{
    if (++ps == pe)
        pe = (ps = buf) + fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}

template <class T>
inline bool in(T& ans)
{
    ans = 0;
    T f = 1;
    if (ps == pe) return false; //EOF
    do
    {
        rnext();
        if ('-' == *ps) f = -1;
    } while (!isdigit(*ps) && ps != pe);
    if (ps == pe) return false; //EOF
    do
    {
        ans = (ans << 1) + (ans << 3) + *ps - 48;
        rnext();
    } while (isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}

const int MAXOUT = 10000;
char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
inline void write()
{
    fwrite(bufout, sizeof(char), pout - bufout, stdout);
    pout = bufout;
}
inline void out_char(char c)
{
    *(pout++) = c;
    if (pout == pend) write();
}
inline void out_str(char* s)
{
    while (*s)
    {
        *(pout++) = *(s++);
        if (pout == pend) write();
    }
}
template <class T>
inline void out_int(T x)
{
    if (!x)
    {
        out_char('0');
        return;
    }
    if (x < 0) x = -x, out_char('-');
    int len = 0;
    while (x)
    {
        outtmp[len++] = x % 10 + 48;
        x /= 10;
    }
    outtmp[len] = 0;
    for (int i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
    out_str(outtmp);
}
}


const int maxn = 2e5+5;
int a[maxn];
int sz[maxn], heavySonSz[maxn], treeSz,rt;
bool vis[maxn];

int head[maxn << 1], nxt[maxn << 1], ver[maxn << 1];
int totver;
inline void add(int u,int v){
    ver[++totver] = v, nxt[totver] = head[u], head[u] = totver;
    ver[++totver] = u, nxt[totver] = head[v], head[v] = totver;
}
void getRoot(int u,int fa){
    sz[u] = 1, heavySonSz[u] = 0;
    for(int i=head[u];i;i=nxt[i]){
        int v = ver[i];
        if(vis[v] || v == fa) continue;
        getRoot(v,u);
        sz[u] += sz[v];
        heavySonSz[u] = max(heavySonSz[u], sz[v]);
    }
    heavySonSz[u] = max(heavySonSz[u], treeSz - sz[u]);
    if(heavySonSz[u] < heavySonSz[rt]) rt = u;
}

ll ans;
int subsz[maxn];
int num[maxn];
ll cnt[maxn];
ll sum;
void getSz(int u,int fa){
    subsz[u] = 1;
    for(int i=head[u];i;i=nxt[i]){
        int v = ver[i];
        if(vis[v] || v == fa) continue;
        getSz(v,u);
        subsz[u] += subsz[v];
    }
    cnt[a[u]] = 0;
}
void change(int u,int fa,int sign){
    num[a[u]]++;
    if(num[a[u]] == 1){
        sum += sign * subsz[u];
        cnt[a[u]] += sign * subsz[u];
    }
    for(int i=head[u];i;i=nxt[i]){
        int v = ver[i];
        if(vis[v] || v == fa) continue;
        change(v,u,sign);
    }
    num[a[u]]--;
}
int tot;
ll tmp;
void solve(int u,int fa){
    num[a[u]]++;
    if(num[a[u]] == 1){
        sum -= cnt[a[u]];
        tot++;
    }
    tmp += sum + 1LL * tot * subsz[0];
    for(int i=head[u];i;i=nxt[i]){
        int v = ver[i];
        if(vis[v] || v == fa) continue;
        solve(v,u);
    }
    num[a[u]]--;
    if(num[a[u]] == 0) {
        sum += cnt[a[u]];
        tot--;
    }
}

void cal(int u){
    sum = 0;
    getSz(u,0);
    change(u,0,1);
    ans += sum;
    tmp = 0;

    for(int i=head[u];i;i=nxt[i]){
        int v = ver[i];
        if(vis[v]) continue;
        num[a[u]]++;
        change(v,u,-1);
        num[a[u]]--;
        subsz[0] = subsz[u] - subsz[v] - 1;
        sum -= subsz[v] + 1;
        cnt[a[u]] -= subsz[v] + 1;
        solve(v,u);

        num[a[u]]++;
        change(v,u,1);
        num[a[u]]--;
        sum += subsz[v] + 1;
        cnt[a[u]] += subsz[v] + 1;
    }
    ans += tmp / 2;
}

void dfs(int u){
    vis[u] = 1;
    cal(u);
    for(int i=head[u];i;i=nxt[i]){
        int v = ver[i];
        if(vis[v]) continue;
        rt = 0, treeSz = sz[v];
        getRoot(v,u);
        dfs(rt);
    }
    /*
        for(auto &v:G[u]){
            if(vis[v]) continue;
            rt = 0, treeSz = sz[v];
            getRoot(v,u);
            dfs(rt);
        }
    */
}

int main(){
    int kase = 1, n;
    while(io::in(n)){
        for(int i=1;i<=n;i++) io::in(a[i]), vis[i] = 0, cnt[i] = 0, head[i] = 0;
        totver = 0;
        for(int i=0,u,v;i<n-1;i++){
            io::in(u);
            io::in(v);
            add(u,v);
        }
        rt=0, heavySonSz[rt] = 1e9, treeSz = n;
        getRoot(1,0);
        ans = -n;
        dfs(rt);
        io::out_str("Case #");
        io::out_int(kase++);
        io::out_str(": ");
        io::out_int(ans);
        io::out_char('\n');
    }
    io::write();
}
/*
3
1 2 1
1 2
2 3
6
1 2 1 3 2 1
1 2
1 3
2 4
2 5
3 6
 */