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
const double eps = 1e-6;

struct bint
{
    int l;
    short int w[100];
    bint(int x = 0)
    {
        l = x == 0;
        memset(w, 0, sizeof(w));
        while (x != 0) {
            w[l++] = x % 10;
            x /= 10;
        }
    }
    bool operator<(const bint& x) const
    {
        if (l != x.l) return l < x.l;
        int i = l - 1;
        while (i >= 0 && w[i] == x.w[i]) i--;
        return (i >= 0 && w[i] < x.w[i]);
    }
    bint operator+(const bint& x) const
    {
        bint ans;
        ans.l = l > x.l ? l : x.l;
        for (int i = 0; i < ans.l; i++) {
            ans.w[i] += w[i] + x.w[i];
            ans.w[i + 1] += ans.w[i] / 10;
            ans.w[i] = ans.w[i] % 10;
        }
        if (ans.w[ans.l] != 0) ans.l++;
        return ans;
    }
    bint operator*(const bint& x) const
    {
        bint res;
        int up, tmp;
        for (int i = 0; i < l; i++) {
            up = 0;
            for (int j = 0; j < x.l; j++) {
                tmp = w[i] * x.w[j] + res.w[i + j] + up;
                res.w[i + j] = tmp % 10;
                up = tmp / 10;
            }
            if (up != 0) res.w[i + x.l] = up;
        }
        res.l = l + x.l;
        while (res.w[res.l - 1] == 0 && res.l > 1) res.l--;
        return res;
    }
    void print()
    {
        for (int i = l - 1; i >= 0; i--)
            printf("%d", w[i]);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    char s[100], t[100];
    while (~scanf("%s%s", s, t))
    {
        bint a, b;
        for (int i = 0; i < strlen(s); i++)
            a = a * bint(10) + bint(s[i] - '0');
        for (int i = 0; i < strlen(t); i++)
            b = b * bint(10) + bint(t[i] - '0');
        bint c = a + b;
        a.print();
        printf("+");
        b.print();
        printf("=");
        c.print();
        puts("");
    }
    return 0;
}
