    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int n;
        while (cin >> n)
        {
            int ans = n, a = n;
            for (int i = 2; i * i <= a; i++)
                if (a % i == 0)
                {
                    ans = ans / i * (i - 1);
                    while (a % i == 0)
                        a /= i;
                }
            if (a > 1)
                ans = ans / a * (a - 1);
            cout << ans << endl;
        }
        return 0;
    }
