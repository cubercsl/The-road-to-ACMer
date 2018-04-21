T = int(input())
while True:
    try:
        n, m = map(int, input().split())
        n = n + 1
        ans = (n * (n + 1) * (2 * n + 1) + 3 * (n + 1) * n) // 12
        print(ans % m)
    except:
        break