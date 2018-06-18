mod = 1000000007
x, k = map(int, input().split())
if x == 0:
    print(0)
else:
    ans = (pow(2, k + 1, mod) * x % mod - (pow(2, k, mod) - 1 + mod) % mod + mod) % mod
    print(ans)