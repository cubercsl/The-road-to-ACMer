#include <bits/stdc++.h>
using namespace std;
#define REP(X, N) for (int X = 0; X < N; X++)
typedef long long ll;
typedef pair<ll, ll> expr;

int sqrt_root = 1;
int mod = 1;

expr operator+(const expr& a, const expr& b)
{
    return {(a.first + b.first) % mod, (a.second + b.second) % mod};
}

expr operator-(const expr& a, const expr& b)
{
    return {(a.first - b.first) % mod, (a.second - b.second) % mod};
}

expr operator*(const expr& a, const expr& b)
{
    return {(a.first * b.first % mod + a.second * b.second % mod * sqrt_root % mod) % mod, (a.first * b.second + a.second * b.first) % mod};
}

expr operator/(const expr& a, int b)
{
    return {(a.first / b % mod + mod) % mod, (a.second / b % mod + mod) % mod};
}

expr pow_mod(expr a, ll n)
{
    expr res = make_pair(1, 0);
    while (n)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

pair<ll, ll> normalize(ll n)
{
    ll tn = n;
    ll a = 1;
    for (ll i = 2; (i * i) <= n; i++)
    {
        while (n % (i * i) == 0)
        {
            n /= i;
            n /= i;
            a *= i;
        }
        while (n % i == 0)
        {
            n /= i;
        }
    }
    return make_pair(a, tn / a / a);
}

default_random_engine e;
ll rnd()
{
    uniform_int_distribution<ll> dist(1, 100000000000000000ll);
    return dist(e);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b, p;
        ll n;
        /*
        a=rnd()%1000000+1;
        b=rnd()%1000000+1;
        n=rnd()%100000000000000000ll+1;
        p=rnd()%1000000000+1;
        */
        scanf("%d%d%lld%d", &a, &b, &n, &p);
        //ans = ((1+a*sqrt(b))^n - (1-a*sqrt(b))^n)/ 2
        auto nb = normalize(b);
        mod = p * 2;
        expr e1, e2;
        sqrt_root = nb.second;

        bool print_first = false;
        if (nb.second == 1)
        {
            e1 = make_pair(a + nb.first % mod, 0);
            e2 = make_pair(a - nb.first % mod, 0);
            print_first = true;
        }
        else
        {
            e1 = make_pair(a % mod, nb.first % mod);
            e2 = make_pair(a % mod, -nb.first % mod);
        }
        expr ans1 = pow_mod(e1, n);
        expr ans2 = pow_mod(e2, n);
        expr ans = ans1 - ans2;
        mod = p;
        ans = ans / 2;
        printf("1 ");
        if (print_first)
        {
            printf("%d 1\n", (int)ans.first);
        }
        else
        {
            printf("%d %d\n", (int)ans.second, (int)sqrt_root);
        }
    }
    //printf("end %d\n", 0);
    return 0;
}