n, m = map(int, input().split())
x = max(n - m * 2, 0)
for i in range(n + 1):
    if i * (i - 1) // 2 >= m:
        y = n - i
        print(x, y)
        exit()