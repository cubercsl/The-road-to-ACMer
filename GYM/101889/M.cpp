#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}

const int maxn = 1 << 20;
struct Suffix_Aray
{
    //倍增算法构造后缀数组,复杂度O(nlogn)
    int s[maxn];
    int sa[maxn], t[maxn], t2[maxn], c[maxn], rank[maxn], height[maxn];
    //n为字符串的长度,字符集的值为0~m-1
    void build_sa(int m, int n)
    {
        n++;
        int *x = t, *y = t2;
        //基数排序
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; ~i; i--) sa[--c[x[i]]] = i;
        for (int k = 1; k <= n; k <<= 1)
        {
            //直接利用sa数组排序第二关键字
            int p = 0;
            for (int i = n - k; i < n; i++) y[p++] = i;
            for (int i = 0; i < n; i++)
                if (sa[i] >= k) y[p++] = sa[i] - k;
            //基数排序第一关键字
            for (int i = 0; i < m; i++) c[i] = 0;
            for (int i = 0; i < n; i++) c[x[y[i]]]++;
            for (int i = 0; i < m; i++) c[i] += c[i - 1];
            for (int i = n - 1; ~i; i--) sa[--c[x[y[i]]]] = y[i];
            //根据sa和y数组计算新的x数组
            swap(x, y);
            p = 1;
            x[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
            if (p >= n) break; //以后即使继续倍增，sa也不会改变，推出
            m = p;             //下次基数排序的最大值
        }
        n--;
        int k = 0;
        for (int i = 0; i <= n; i++) rank[sa[i]] = i;
        for (int i = 0; i < n; i++)
        {
            if (k) k--;
            int j = sa[rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            height[rank[i]] = k;
        }
        for (int i = 0; i < n; i++) dbg(i, rank[i]);
    }
} sa;

const int mod = 1e9 + 7;
int main()
{
    int n;
    scanf("%d", &n);
    int t = 0;
    vector<int> pt;
    for (int i = 0, k; i < n; i++)
    {
        scanf("%d", &k);
        pt.push_back(t);
        for (int j = 0, x; j < k; j++)
        {
            scanf("%d", &x);
            sa.s[t++] = x;
        }
        sa.s[t++] = 301;
    }
    sa.build_sa(302, t);
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) q.push({-sa.rank[pt[i]], pt[i]});
    vector<int> ans;
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int _pt = t.second;
        ans.push_back(sa.s[_pt]);
        if (sa.s[++_pt] != 301) q.push({-sa.rank[_pt], _pt});
    }
    long long tmp = 0;
    dbg(ans);
    for (auto& t : ans) tmp = (tmp * 365 + t * 365) % mod;
    printf("%lld\n", tmp);
}