// Alice's Classified Message, HDU5558

/*Sample Input
2
aaaaaa
aaaaabbbbbaaabbc
*/

#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 2e6 + 5;
//倍增算法构造后缀数组,复杂度O(nlogn)
char s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], Rank[maxn], height[maxn];
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
    for (int i = 0; i <= n; i++) Rank[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (k) k--;
        int j = sa[Rank[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        height[Rank[i]] = k;
    }
}

int pre[maxn], suf[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int n = strlen(s);
        build_sa(128, n);
        pre[0] = 0;
        suf[n] = n;
        for (int i = 1; i <= n; i++)
            pre[i] = height[i] ? pre[i - 1] : i;
        for (int i = n - 1; i; i--)
            suf[i] = height[i + 1] ? suf[i + 1] : i;
        printf("Case #%d:\n", ++kase);
        int k, t;
        for (int i = 0; i < n; i += k ? k : 1)
        {
            int tmp = Rank[i];
            k = 0, t = i;
            int mm = height[tmp];
            for (int j = tmp - 1; j >= pre[tmp]; j--)
            {
                mm = min(mm, height[j + 1]);
                if (mm < k) break;
                if (sa[j] >= i) continue;
                if (mm > k || mm == k && sa[j] < t)
                    k = mm, t = sa[j];
            }
            mm = height[tmp + 1];
            for (int j = tmp + 1; j <= suf[tmp]; j++)
            {
                mm = min(mm, height[j]);
                if (mm < k) break;
                if (sa[j] >= i) continue;
                if (mm > k || mm == k && sa[j] < t)
                    k = mm, t = sa[j];
            }
            if (k)
                printf("%d %d\n", k, t);
            else
                printf("%d %d\n", -1, s[i]);
        }
    }
    return 0;
}
