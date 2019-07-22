#include <bits/stdc++.h>
using namespace std;

template <class _EuclideanRingElement>
_EuclideanRingElement lcm(_EuclideanRingElement a, _EuclideanRingElement b)
{
    _EuclideanRingElement g = __gcd(a, b);
    if (g == 0) return a * b;
    return a / g * b;
}

class Rational
{
public:
    Rational(const long long& n = 0, const long long& d = 1)
    {
        numerator = d < 0 ? -n : n;
        denominator = d < 0 ? -d : d;
        reduce();
    }

    Rational(const long long& t) : numerator(t), denominator(1)
    {
        reduce();
    }

    Rational(const int& t) : numerator(t), denominator(1)
    {
        reduce();
    }

    Rational operator+(const Rational& a) const
    {
        Rational t;
        t.denominator = lcm(a.denominator, denominator);
        t.numerator = a.numerator * (t.denominator / a.denominator) + (t.denominator / denominator) * numerator;
        if (denominator != 0) t.reduce();
        return t;
    }

    Rational operator-(const Rational& s) const
    {
        Rational t;
        t.denominator = lcm(s.denominator, denominator);
        t.numerator = numerator * (t.denominator / denominator) - (t.denominator / s.denominator) * s.numerator;
        if (denominator != 0) t.reduce();
        return t;
    }

    Rational operator*(const Rational& m) const
    {
        Rational t;
        t.numerator = m.numerator * numerator;
        t.denominator = m.denominator * denominator;
        if (denominator != 0) t.reduce();
        return t;
    }
    Rational operator/(const Rational& v) const
    {
        Rational t;
        t.numerator = v.denominator * numerator;
        t.denominator = denominator * v.numerator;
        if (denominator != 0) t.reduce();

        return t;
    }
    int cmp()
    {
        if (numerator == 0) return 0;
        return numerator < 0 ? -1 : 1;
    }
    bool operator<(const Rational& s) const
    {
        return ((*this) - s).cmp() < 0;
    }
    bool operator==(const Rational& s)
    {
        return ((*this) - s).cmp() == 0;
    }
    void print()
    {
        reduce();
        if (denominator == 0)
        {
            cout << endl
                 << "DIVIDE BY ZERO ERROR!!!" << endl;
            exit(-1);
        }
        else if (numerator == 0)
            printf("%d\n", 0);
        else if (denominator == 1)
            printf("%lld\n", numerator);
        else
            printf("%lld/%lld\n", numerator, denominator);
    }

    long long numerator;
    long long denominator;

    void reduce()
    {
        if (denominator < 0) denominator = -denominator, numerator = -numerator;
        long long n = numerator < 0 ? -numerator : numerator;
        long long d = denominator;
        long long gcd = __gcd(n, d);

        if (gcd != 0)
        {
            numerator /= gcd;
            denominator /= gcd;
        }
    }
};

const int N = 1 << 14;
int a[N], id[N];
Rational A[N], P[N];

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]), id[i] = i;
        for (int i = 0; i < n; i++) A[i] = Rational(a[i]) / m;
        Rational sum = 0;
        for (int i = 0; i < n; i++) sum = sum + A[i];
        sum = (sum - 1) / n;
        for (int i = 0; i < n; i++) P[i] = A[i] - sum;
        sort(id, id + n, [&](int a, int b) {
            return P[a] < P[b];
        });
        Rational res = 0;
        for (int i = 0; i < n; i++)
        {
            auto t = res / (n - i);
            res = res - min(t, P[id[i]]);
            P[id[i]] = max(P[id[i]] - t, Rational(0));
        }
        Rational ans = 0;
        for (int i = 0; i < n; i++) ans = ans + (A[i] - P[i]) * (A[i] - P[i]);
        ans.print();
    }
}