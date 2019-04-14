T = int(raw_input())
for i in range(T):
    n = int(raw_input())
    ans = 0
    n //= 2
    while n:
        ans += n
        n //= 2
    print(ans)
