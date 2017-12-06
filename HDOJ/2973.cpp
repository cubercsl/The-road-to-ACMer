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

    bool isprime(int x)
    {
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return x != 1;
    }

    const int N = 1e6 + 5;
    int f[N];

    inline void init()
    {
        f[0] = 0;
        for (int i = 1; i < N; i++)
            f[i] = f[i - 1] + isprime(3 * i + 7);
    }

    int main()
    {
    #ifndef ONLINE_JUDGE
        freopen("1.in", "r", stdin);
        freopen("1.out", "w", stdout);
    #endif
        init();
        int t;
        scanf("%d", &t);
        while (t--)
        {
            int n;
            scanf("%d", &n);
            printf("%d\n", f[n]);
        }
        return 0;
    }
