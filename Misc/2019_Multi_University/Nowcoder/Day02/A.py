mod = 10 ** 9 + 7
T = int(input())
ans = 1
for i in range(T):
    n, m = map(int, input().split())
    if n == 1:
        ans = ans * 1
    else:
        if m == 0:
            ans = 0
        else:
            ans = ans * pow(n - 1, mod - 2, mod) % mod
    print(ans)